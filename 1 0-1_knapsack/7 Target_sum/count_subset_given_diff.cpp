#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
bool subset_sum(int arr[], int n ,int sum)
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
				dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
			else 
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][sum];	
}
void intialization_of_dp()
{
	memset(dp,0,sizeof(dp));
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
int count_partition_given_diff(int arr[], int n,int diff)
{
	int range=0;
	for (int i=0;i<n;i++)
		range=range+arr[i];
	subset_sum(arr,n, range);
	if ((range+diff)%2==1)
		return 0;
	else 
		return dp[n][(diff+range)/2];
}	
int main()
{
	int n;
	n=5;
	int arr[]={1,2,10,5,5};//sum=10; 
	int diff=7;				//Target diff
	intialization_of_dp();			
	cout<<count_partition_given_diff(arr,n,diff)<<endl;
	//printdp(n,13);
}
	
