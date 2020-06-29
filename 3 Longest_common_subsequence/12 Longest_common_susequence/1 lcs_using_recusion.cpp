#include<bits/stdc++.h>
using namespace std;
int lcs(string s, string t, int m,int n)
{
	if (n==0||m==0)
		return 0;
	else 
	{
		if (s[m-1]==t[n-1])
		return 1+lcs(s,t,m-1,n-1);
		else 
			return max(lcs(s,t,m-1,n),lcs(s,t,m,n-1));
	}
}
int main()
{
	string s="shubham";
	string t="sbusbam"; 
	int m=7,n=7;
	cout<<lcs(s,t,m,n);
}
