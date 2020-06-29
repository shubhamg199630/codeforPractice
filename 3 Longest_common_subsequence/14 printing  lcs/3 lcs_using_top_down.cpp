#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int lcs(string s, string t, int m,int n)
{
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (s[i-1]==t[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else 
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];	
}
void print_lcs(string s, string t,int m, int n)
{
	string str;
	int i=m,j=n;
	while (i!=0&&j!=0)
	{
		if (s[i-1]==t[j-1]){
			str.push_back(s[i-1]);
			i--;
			j--;
		}
		else if (dp[i-1][j]>dp[i][j-1])
			i--;
		else 
			j--;
	}
	int l=str.size();
	for (i=l-1;i>=0;i--)
		cout<<str[i];
}
		
	
void intialization_of_dp()
{  
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<=1000;i++)
	{
		for (int j=0;j<=1000;j++)
		{
			if (j==0||i==0)
				dp[i][j]=0;
		}
	}
}
void printdp(int m, int n)
{
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	string s="shubham";
	string t="sahubadm"; 
	int m=7,n=8;
	intialization_of_dp();
	//printdp(m,n);
	lcs(s,t,m,n);
	print_lcs(s,t,m,n);
	//printdp(m,n);
}
