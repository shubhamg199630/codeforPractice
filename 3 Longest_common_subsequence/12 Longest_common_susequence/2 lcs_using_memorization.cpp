#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int lcs(string s, string t, int m,int n)
{
	if (n==0||m==0)
		return 0;
	else if (dp[m][n]!=-1)
		return dp[m][n];
	else 
	{
		if (s[m-1]==t[n-1])
		dp[m][n]=1+lcs(s,t,m-1,n-1);
		else 
		dp[m][n]=max(lcs(s,t,m-1,n),lcs(s,t,m,n-1));
		return dp[m][n];
	}
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
	string t="sbusbam"; 
	int m=7,n=7;
	intialization_of_dp();
	cout<<lcs(s,t,m,n);
	printdp(m,n);
}
