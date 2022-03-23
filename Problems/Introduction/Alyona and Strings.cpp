/*
	Writer : ADITYA PATEL
*/

#include "bits/stdc++.h"
using namespace std;
#define int long long

inline void IO_LOCAL(){
	#ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif
}

inline void Fast_IO(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
}

int dp[1005][1005][2][11];
int n,m,k;
string s1,s2;

int recur(int i1,int i2,bool on,int curr){
	if(curr < 0) return INT_MIN;
	if(i1==n || i2==m){
		return curr==0 ? 0 : INT_MIN; 
	}

	if(dp[i1][i2][on][curr]!=-1) return dp[i1][i2][on][curr];

	dp[i1][i2][on][curr] = max( {recur(i1+1,i2,false,curr) , recur(i1,i2+1,false,curr) });

	if(s1[i1]==s2[i2]){
		if(on){
			dp[i1][i2][on][curr] = max( { dp[i1][i2][on][curr] , 1+recur(i1+1,i2+1,true,curr) , 1+recur(i1+1,i2+1,true,curr-1) } );
		}else{
			dp[i1][i2][on][curr] = max( dp[i1][i2][on][curr]  , 1+recur(i1+1,i2+1,true,curr-1));
		}
	}

	return dp[i1][i2][on][curr];
}

void solve(int cTc){
	memset(dp,-1,sizeof dp);
	cin>>n>>m>>k;
	cin>>s1>>s2;

	cout<< recur(0,0,0,k) <<"\n";

}

signed main(){
	IO_LOCAL();
	Fast_IO();

	int tc=1;
	// cin>>tc;
	for(int cTc=1;cTc<=tc;++cTc){
		solve(cTc);
	}

	return EXIT_SUCCESS;
}
