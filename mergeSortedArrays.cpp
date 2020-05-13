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

vector<int> mergeSortedArrays(vector<vector<int>> a) {
	int n=a.size();
	vi idx(n,1);
	mset<pii> m;
	for (int i=0;i<n;i++) {
		m.insert(mp(a[i][0],i));
	}
	vi ans;
	while (m.size()) {
		pii p=*m.begin();
		m.erase(m.begin());
		ans.pb(p.f);
		if (idx[p.s]<a[p.s].size()) {
			m.insert(mp(a[p.s][idx[p.s]],p.s));
			idx[p.s]++;
		}
	}
  return ans;
}