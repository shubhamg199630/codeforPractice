#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int min_coin(int coin[], int n ,int target)
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=target;j++)
		{
			if (coin[i-1]<=j&&dp[i][j-coin[i-1]]!=INT_MAX)
				dp[i][j]=min(dp[i][j-coin[i-1]]+1,dp[i-1][j]);
			else 
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][target];
}
void intialization_of_dp()
{
	memset(dp,INT_MAX,sizeof(dp));
	for (int i=0;i<=1000;i++)
	{
		for (int j=0;j<=1000;j++)
		{
			if (j==0)
				dp[i][j]=0;
			else 
				dp[i][j]=INT_MAX;
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
	int coin[]={1,4,5},target=8; 				//Target Sum
	intialization_of_dp();
	//printdp(n,target);			
	cout<<min_coin(coin,n,target)<<endl;
	//printdp(n,target);
}
	
