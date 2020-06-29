#include<bits/stdc++.h>
using namespace std;
bool dp[100][10001];
bool subsetsum(int arr[], int n,int sum)
{
	//bool dp[n+1][sum+1];
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=sum;j++)
		{	
			if (j==0)
				dp[i][j]=true;
			else if (i==0)
				dp[i][j]=false;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=sum;j++)
		{
			if (arr[i-1]<=j)
				dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
			else 
				dp[i][j]=dp[i-1][j];
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	return dp[n][sum];
}
		
int main()
{
	int n=5;
	int arr[]={2,3,8,4,5};
	int sum=20;
	subsetsum(arr,n,sum);
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=sum;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}
