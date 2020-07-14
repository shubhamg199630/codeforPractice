#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
bool check_palindrome(string s ,int i,int k){
	while (i<k){
		if (s[i]!=s[k])
			return false;
		i++;
		k--;
	}
	return true;
}		
int string_partition_palindrome(string s,int i, int j){
	if (i>j)
		return 0;
	else 
	{
		if (dp[i][j]!=-1)
			return dp[i][j];
		else {
			if (check_palindrome(s,i,j)) {
				dp[i][j]=0;
				return 0;
			}
			int temp=INT_MAX,mi=INT_MAX;
			for (int k=i;k<j;k++) {
				if (check_palindrome(s,i,k))
				{
					temp=string_partition_palindrome(s,i,k)+string_partition_palindrome(s,k+1,j)+1;
				}
				mi=min(mi,temp);
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
	string s="ueokcxsxomszsnsnhmlqlggkrnarwtkszaebxw";
	int n=s.size();
	int j=n-1,i=1;
	intialization_of_dp();
	cout<<string_partition_palindrome(s,0,j);
	//printdp(n,n);
}
