#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int sum_of_subset(int arr[], int n ,int sum, int curr)
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
				dp[curr][sum]=sum_of_subset(arr,n,sum-arr[curr-1],curr-1)||sum_of_subset(arr,n,sum,curr-1);
			else 
				dp[curr][sum]=sum_of_subset(arr,n,sum,curr-1);
			return dp[curr][sum];
		}
	}
}
int main()
{
	int n;
	n=2;
	int arr[]={1,1},sum=0;
	for (int i=0;i<n;i++)
	{
		sum=sum+arr[i];
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=sum;j++)
		{
			if (j==0)
				dp[i][j]=1;
			else if (i==0)
				dp[i][j]=0;
			else 
				dp[i][j]=-1;
		}
	}			
	if (sum%2==1)
		cout<<false;
	else 
		cout<<sum_of_subset(arr,n,sum/2,n);
	/*for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=sum;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
}
	
