	#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int coin_change_ways(int coin[], int n ,int target, int curr)
{
	//cout<<"sum_of_subset("<<sum<<","<<curr<<")\n";
	if (target==0)
		return 1;
	else if (curr==0)
		return 0;
	else 
	{
		if (dp[curr][target]!=-1)
			return dp[curr][target];
		else 
		{
			if (coin[curr-1]<=target)
				dp[curr][target]=coin_change_ways(coin,n,target-coin[curr-1],curr)+coin_change_ways(coin,n,target,curr-1);
			else 
				dp[curr][target]=coin_change_ways(coin,n,target,curr-1); 	
			return dp[curr][target];
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
	n=3;
	int coin[]={1,2,3},target=5; 				//Target Sum
	intialization_of_dp();			
	cout<<coin_change_ways(coin,n,target,n)<<endl;
	printdp(n,target);
}
	
