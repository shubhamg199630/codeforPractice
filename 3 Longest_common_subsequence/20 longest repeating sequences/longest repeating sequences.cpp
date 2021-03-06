#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int lcs(string s , string t){
    int n=t.size(),m=s.size();
    int i,j;
    for (i=1;i<=m;i++){
        for (j=1;j<=n;j++){
                if (s[i-1]==t[j-1]&&i!=j)
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
string reverse_string (string &x){
    int n=x.size()-1;
    int i=0;
    while (i<n){
        swap(x[i],x[n]);
        n--;
        i++;
    }
    return x;
}
void print_lcs(string s, string t){
    int i=s.size(),j=t.size();
    string lcs;
    while (i>0&&j>0){
        if (s[i-1]==t[j-1]&&i!=j){
            lcs.push_back(s[i-1]);
            i--;
            j--;
        }
        else if (dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse_string (lcs);
    cout<<lcs<<endl;
}
void intialization_of_dp(){
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
int main(){
	string s="shubshuam";
	int m=s.size();
	intialization_of_dp();
	cout<<lcs(s,s);
    printdp(m,m);
    print_lcs(s,s);
}

