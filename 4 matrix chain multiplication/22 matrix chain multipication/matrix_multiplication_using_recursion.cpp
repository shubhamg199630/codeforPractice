#include<bits/stdc++.h>
using namespace std;
int matrix_multiplication(vector <int> a,int i, int j){
	if (i>=j)
		return 0;
	else {
		int mi=INT_MAX;
		for (int k=i;k<j;k++){
			int temp=matrix_multiplication(a,i,k)+matrix_multiplication(a,k+1,j)+a[i-1]*a[k]*a[j];
			mi=min(temp,mi);
		}
		return mi;
	}
}			
int main()
{
	vector <int> a={10,30,5,60};
	int n=a.size();
	int j=n-1,i=1;
	cout<<matrix_multiplication(a,1,j);
}
