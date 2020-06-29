#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int min_coin(int coin[], int n ,int target, int curr)
{
	if (target==0)
		return 0;
	
	else 
	{
	//cout<<"sum_of_subset("<<sum<<","<<curr<<")\n";
		if (dp[curr][target]!=INT_MAX)
			return dp[curr][target];
		else 
		{
			if (coin[curr-1]<=target&&dp[curr][target-coin[curr-1]]!=INT_MAX)
				dp[curr][target]=min(min_coin(coin,n,target-coin[curr-1],curr)+1,min_coin(coin,n,target,curr-1));
			else 
				dp[curr][target]=min_coin(coin,n,target,curr-1); 	
			return dp[curr][target];
		}
	}
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
	int coin[]={1,2,3},target=5; 				//Target Sum
	intialization_of_dp();
	printdp(n,target);			
	cout<<min_coin(coin,n,target,n)<<endl;
	printdp(n,target);
}
	 
