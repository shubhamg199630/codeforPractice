	#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int sum_of_subset(int arr[], int n ,int sum, int curr)
{
	//cout<<"sum_of_subset("<<sum<<","<<curr<<")\n";
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
				dp[curr][sum]=sum_of_subset(arr,n,sum-arr[curr-1],curr-1)+sum_of_subset(arr,n,sum,curr-1);
			else 
				dp[curr][sum]=sum_of_subset(arr,n,sum,curr-1);
			return dp[curr][sum];
		}
	}
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
	n=5;
	int arr[]={1,4,5,5,10},sum=10; 				//Target Sum
	intialization_of_dp();			
	cout<<sum_of_subset(arr,n,sum,n)<<endl;
	printdp(n,sum);
}
	
