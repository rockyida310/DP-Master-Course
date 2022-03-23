#include<iostream>
using namespace std;
#define int long long

int dp[101];

int F(int N){
	if(N<=1) return 1;
	int ans = 0;

	if(dp[N]) return dp[N];

	for(int i=1;i<=N;++i){
		ans += F(i-1) * F(N-i);
	}

	return dp[N] = ans;
}

signed main() {
	int n;
	cin>>n;

	cout<< F(n);

	return 0;
}