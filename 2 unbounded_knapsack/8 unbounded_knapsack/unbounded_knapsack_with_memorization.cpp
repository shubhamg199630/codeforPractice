#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int knapsack(int val[],int weight[],int n,int m, int curr)
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
			if (weight[curr-1]<=m)
				dp[curr][m]=max(val[curr-1]+knapsack(val,weight,n,m-weight[curr-1],curr),knapsack(val,weight,n,m,curr-1));    ///diff between knapsack and unboundedknapsack
			else 
				dp[curr][m]=knapsack(val,weight,n,m,curr-1);
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
	int val[]={40,20,100,10,300};int weight[]={10,20,30,40,45};int m=100; 				//m=capacity of bag
	intialization_of_dp();	
	cout<<knapsack(val,weight,n,m,n)<<endl;
	//printdp(n,m);
}	
