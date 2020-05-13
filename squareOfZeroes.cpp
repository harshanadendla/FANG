#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define mset multiset
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define dbg(x) cerr<<x<<"\n"
#define bug(x) cout<<"hi"<<x<<endl

bool squareOfZeroes(vector<vector<int>> m) {
	int n=m.size();
	vvi h(n,vi(n,0)),v(n,vi(n,0));
	
	int cur=0;
	for (int i=0;i<n;i++) {
		cur=0;
		for (int j=0;j<n;j++) {
			if (m[i][j]) {
				cur=0;
			} else {
				cur++;
			}
			h[i][j]=cur;
		}
	}
	
	cur=0;
	for (int i=0;i<n;i++) {
		cur=0;
		for (int j=0;j<n;j++) {
			if (m[j][i]) {
				cur=0;
			} else {
				cur++;
			}
			v[j][i]=cur;
		}
	}
	
	for (int i=1;i<n;i++) {
		for (int j=1;j<n;j++) {
			int len=min(h[i][j],v[i][j]);
			if (len<=1) {
				continue;
			}
			for (int k=1;k<len;k++) {
				if (i>=k && j>=k && h[i-k][j]>=len && v[i][j-k]>=len) {
					return true;
				}
			}
		}
	}
  return false;
}