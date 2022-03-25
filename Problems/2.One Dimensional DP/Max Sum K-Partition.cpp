#include<bits/stdc++.h>
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


signed main(){
	IO_LOCAL();
	Fast_IO();

	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(auto &c:v) 
		cin>>c;
	
	int m1=INT_MIN,m2=INT_MIN,idx=-1;
	for(int i=0;i<min(n,k);++i){
		if(v[i] > m1){
			m2 = m1;
			m1 = v[i];
			idx = i;
		}else if(v[i]>m2){
			m2 = v[i];
		}
	}


	for(int i=k;i<n;i+=k){
		for(int j=i;j<min(n,i+k);++j){
			if(j-idx==k){
				v[j] = max(v[j] , v[j] + m2 ); 
			}else{
				v[j] = max(v[j] , v[j] + m1 );
			}
		}

		for(int j=i;j<min(n,i+k);++j){
			if(v[j] > m1){
				m2 = m1;
				m1 = v[j];
				idx = j;
			}else if(v[j] <= m1 && v[j]>m2){
				m2 = v[j];
			}
		}
	}

	cout<< m1<<endl;
	return 0;
}