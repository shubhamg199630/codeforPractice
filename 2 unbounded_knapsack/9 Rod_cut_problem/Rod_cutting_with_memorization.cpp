#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int unbounded_knapsack(int profit[],int length[],int n,int m, int curr)
{
	//cout<<"sum_of_subset("<<sum<<","<<curr<<")\n";
	if (m==0||curr==0)
		return 0;
	else 
	{
		if (dp[curr][m]!=-1)
			return dp[curr][m];
		else 
		{
			if (length[curr-1]<=m)
				dp[curr][m]=max(profit[curr-1]+unbounded_knapsack(profit,length,n,m-length[curr-1],curr),unbounded_knapsack(profit,length,n,m,curr-1));    ///diff between knapsack and unboundedknapsack
			else 
				dp[curr][m]=unbounded_knapsack(profit,length,n,m,curr-1);
			return dp[curr][m];
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
			if (j==0||i==0)
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
	int profit[]={40,20,100,10,30};int length[]={1,2,3,4,5};int m=10; 				//m=capacity of bag
	intialization_of_dp();	
	cout<<unbounded_knapsack(profit,length,n,m,n)<<endl;
	//printdp(n,m);
}	
