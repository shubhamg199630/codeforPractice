#include<bits/stdc++.h>
using namespace std;
bool dp[1001][1001];
bool subset_sum(int arr[], int n ,int sum)
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
				dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
			else 
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][sum];	
}
void intialization_of_dp()
{
	memset(dp,false,sizeof(dp));
	for (int i=0;i<=1000;i++)
	{
		for (int j=0;j<=1000;j++)
		{
			if (j==0)
				dp[i][j]=true;
			else if (i==0)
				dp[i][j]=false;
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
int min_diff_partition_subset(int arr[], int n)
{
	int range=0;
	for (int i=0;i<n;i++)
		range=range+arr[i];
	subset_sum(arr,n, range);
	int mi=INT_MAX;
	for (int i=0;i<=range;i++)
		if(dp[n][i]==true)
			mi=min(mi,abs(range-2*i));
	return mi;
}	
int main()
{
	int n;
	n=6;
	int arr[]={8, 4, 5, 7, 6, 2 };//sum=10; 				//Target Sum
	intialization_of_dp();			
	cout<<min_diff_partition_subset(arr,n)<<endl;
	//printdp(n,sum);
}
	
