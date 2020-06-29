#include<bits/stdc++.h>
using namespace std;
int dp[100][10001];
int subsetsum (int arr[], int n,int sum,int curr)
{
	
	if (sum==0)
		return 1;
	else if (curr==0)
		return 0;
	else 
	{
		if (dp[curr][sum]!=-1)
			return dp[curr][sum];
		else 
		{
			if (arr[curr-1]<=sum)
			dp[curr][sum]=subsetsum(arr,n,sum-arr[curr-1], curr-1)|| subsetsum(arr,n,sum,curr-1);
			else 
				dp[curr][sum]=subsetsum(arr,n,sum,curr-1);
		}
		return dp[curr][sum];
	}
}
int main()
{
	int n=5;
	int arr[]={2,3,8,4,5};
	int sum=14;
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<=sum;i++)
	{
		dp[0][i]=0;
		
	}
	for (int i=0;i<=n;i++)
	{
		dp[i][0]=1;
		
	}
	subsetsum(arr,n,sum,n);
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=sum;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}
