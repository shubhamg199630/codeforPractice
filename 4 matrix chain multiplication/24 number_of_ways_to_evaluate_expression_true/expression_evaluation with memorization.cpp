#include<bits/stdc++.h>
using namespace std;
map<string , int > dp;
int expression_partition(string s,int i, int j, bool istrue){
	//cout<<"expression_partition("<<i<<","<<j<<","<<istrue<<" )";
	if (i>j)
		return 0;
	else if (i==j){
		if (istrue==true&&s[i]=='T')
			return 1;
		else
			return 0;
		if (istrue==false&&s[i]=='F')
			return 1;
		else 
			return 0;
	}
	else 
	{
		string temp,space=" ";
		temp=temp+(char)i;
		temp=temp+space;
		temp=temp+(char)j;
		temp=temp+space;
		temp=temp+(char)istrue;
		auto itr=dp.find(temp);
		if (itr!=dp.end())
			return itr->second;
		int ans=0;
		for (int k=i+1;k<j;k=k+2) {
			int lt=expression_partition(s,i,k-1,true);
			int lf=expression_partition(s,i,k-1,false);
			int rt=expression_partition(s,k+1,j,true);
			int rf=expression_partition(s,k+1,j,false);
			if (s[k]=='&') {
				if (istrue==true) 
					ans=ans+lt*rt;
				else 
					ans=ans+lf*rt+lf*rf+lt*rt;
			}
			else if (s[k]=='|') {
				if (istrue==true)
					ans=ans+lt*rt+lt*rf+lf*rt;
				else
					ans=ans+lf*rf;
			}
			else {
				if (istrue==true)
					ans=ans+lt*rf+lf*rt;
				else 
					ans=ans+lf*rf+lt*rt;
			}
		}
		dp.insert({temp,ans});
		return ans;
	}
}

int main()
{
	string s="T&T&T&T";
	int n=s.size();
	int j=n-1;
	//intialization_of_dp();
	cout<<expression_partition(s,0,j,true);
	//printdp(n,n);
}
