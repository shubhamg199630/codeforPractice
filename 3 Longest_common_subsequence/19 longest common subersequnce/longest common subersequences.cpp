#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int lcs(string s, string t){
    int m=s.size();
    int n=t.size();
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (s[i-1]==t[j-1])
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
string find_lcsuper(string s, string t)
{
    int i=s.size(),j=t.size();
    string lcsuper_value;
    while (i>0||j>0){
        if (j!=0&&i!=0&&s[i-1]==t[j-1]){
            lcsuper_value.push_back(s[i-1]);
            i--;
            j--;
        }
        else if (dp[i-1][j]>dp[i][j-1]||j==0){
            lcsuper_value.push_back(s[i-1]);
            i--;
        }
        else{
            lcsuper_value.push_back(t[j-1]);
            j--;
        }
    }
    lcsuper_value=reverse_string(lcsuper_value);
    return lcsuper_value;
}
/*void print_supersequence(string s, string t , string lcs){
    int i=0,j=0,k=0;
    string ans;
    while (i!=s.size()||j!=t.size()||k!=lcs.size()){
            if (k!=lcs.size()){
                if (s[i]==t[j]&&t[j]==lcs[k]){
                    ans.push_back(s[i]);
                    i++;
                    j++;
                    k++;
                }
                else if (s[i]==lcs[k]){
                    ans.push_back(t[j]);
                    j++;
                }
                else{
                   ans.push_back(s[i]);
                   i++;
                }
            }
            else {
                if (i!=s.size()){
                    ans.push_back(s[i]);
                    i++;
                }
                else {
                    ans.push_back(t[j]);
                    j++;
                }
            }
    }
    cout<<ans;
}*/
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
	string s="shubham",t="winner";
	intialization_of_dp();
	lcs(s,t);
    //printdp(m,n);
	string lcs_value=find_lcsuper(s,t);
	cout<<lcs_value;
}
