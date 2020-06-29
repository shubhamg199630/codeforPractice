	#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int coin_change_ways(int coin[], int n ,int target)
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=target;j++)
		{
			if (coin[i-1]<=j)
				dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
			else 
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][target];
}
void intialization_of_dp()
{
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<=1000;i++)
	{
		for (int j=0;j<=1000;j++)
		{
			if (j==0)
				dp[i][j]=1;
			else if (i==0)
				dp[i][j]=0;
		}
	}
}
void printdp(int n, int sum)
{
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=sum;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	n=3;
	int coin[]={1,2,3},target=5; 				//Target Sum
	intialization_of_dp();			
	cout<<coin_change_ways(coin,n,target)<<endl;
	printdp(n,target);
}
	
