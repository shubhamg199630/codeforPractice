#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int knapsack(int val[],int weight[],int n,int m)
{
	//cout<<"sum_of_subset("<<sum<<","<<curr<<")\n";
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (weight[i-1]<=j)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+val[i-1]);
			else 
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][m];
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
{
		}
	}
}
void printdp(int n, int sum)
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
	int val[]={40,20,100,10,300};int weight[]={10,20,30,40,50};int m=100; 				//m=capacity of bag
	intialization_of_dp();	
	cout<<knapsack(val,weight,n,m)<<endl;
	//printdp(n,m);
}	
