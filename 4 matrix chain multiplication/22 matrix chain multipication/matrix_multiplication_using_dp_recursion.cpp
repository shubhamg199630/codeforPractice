#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int matrix_multiplication(vector <int> a,int i, int j){
	if (i>=j)
		return 0;
	else {
		if (dp[i][j]!=-1)
			return dp[i][j];
		else {
			int mi=INT_MAX;
			for (int k=i;k<j;k++){
				int temp=matrix_multiplication(a,i,k)+matrix_multiplication(a,k+1,j)+a[i-1]*a[k]*a[j];
				mi=min(temp,mi);
			}
			dp[i][j]=mi;
		return mi;
		}
	}
}
void intialization_of_dp(){
	memset(dp,-1,sizeof(dp));
}
void printdp(int m, int n)
{
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	vector <int> a={10,30,5,60};
	int n=a.size();
	int j=n-1,i=1;
	intialization_of_dp();
	cout<<matrix_multiplication(a,1,j);
	printdp(n,n);
}
