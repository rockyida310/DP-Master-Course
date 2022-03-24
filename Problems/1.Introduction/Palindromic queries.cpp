#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;

	bool dp[n][n];
	memset(dp,false,sizeof dp);

	for(int i=0;i<n;++i){
		//odd
		int l=i,r=i;
		while(l>=0 && r<n && s[l]==s[r]){
			dp[l][r] = true;
			--l,++r;
		}

		//even 
		l=i,r=i+1;
		while(l>=0 && r<n && s[l]==s[r]){
			dp[l][r] = true;
			--l,++r;
		}
	}

	int m;
	cin>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		if(dp[l-1][r-1])
			cout<<"YES\n";
		else cout<<"NO\n";
	}

}