#include<bits/stdc++.h>
using namespace std;


string convert_to_update(string s)
{
	int n=s.size();
	string res;
	res+="$";
	for(int i=0;i<n;i++)
	{
		res+="#";
		res+=s[i];
	}
	res+="#%";
	return res;
}
string apply_manacher(string updated_string,string orginal_string)
{
	int n=updated_string.size();
	vector<int>p(n);
	int c,r;
	c=r=0;
	for(int i=1;i<n-1;i++)
	{
		int mirror=c-(i-c);
		if(i<r)
			p[i]=min(p[mirror],r-i);
		while(updated_string[i+1+p[i]]==updated_string[i-1-p[i]])
			p[i]++;
		if(i+p[i]>r)
		{
			r=i+p[i];
			c=i;
		}
	}	
	int len=0,center=0;
	for(int i=1;i<n-1;i++)
	{
		if(p[i]>len)
		{
			len=p[i];
			center=i;
		}
	}
    
	int first_index=center-len+1;
	int actual_index=(first_index-2)/2;

	return orginal_string.substr(actual_index,len);
}

// Problem1 : https://www.spoj.com/problems/LPS/
// Solution : https://ideone.com/7vqdHy

// Problem2 : https://www.spoj.com/problems/NUMOFPAL/
// Solution : https://ideone.com/WLtbtn

