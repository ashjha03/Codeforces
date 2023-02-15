#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n)    for(ll i=j; i<n; i++)
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define pii pair<int, int>
#define mpi map<int, int>
#define mpl map<ll, ll>
#define sti set<int>
#define stl set<ll>
#define all(v) v.begin(), v.end()
#define input(a, n)            \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define output(a, n)           \
    for (ll i = 0; i < n; i++) \
        cout << a[i] << " ";
        
#define start   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define nl cout << "\n"
#define yes  cout<<"YES"<<endl
#define no  cout<<"NO"<<endl
#define prt(x)     cout<<x<<endl
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

int main() {
    start;
// 	ll t;
// 	cin>>t;
// 	while(t--){
	ll n, m; cin>>n>>m;
	map<int, int> color;
	rep(i, 0, m){
	    ll a, b, c; cin>>a>>b>>c;
	    if(!color[a] and !color[b] and !color[c])   color[a] = 1, color[b] = 2, color[c] = 3;
	    else if(color[a]){
	        if(color[a] == 1)   color[b] = 2, color[c] = 3;
	        else if(color[a] == 2)  color[b] = 1, color[c] = 3;
	        else color[b] = 1, color[c] = 2;
	    } else if(color[b]){
	        if(color[b] == 1)   color[a] = 2, color[c] = 3;
	        else if(color[b] == 2)  color[a] = 1, color[c] = 3;
	        else color[a] = 1, color[c] = 2;
	    } else if(color[c]){
	        if(color[c] == 1)   color[b] = 2, color[a] = 3;
	        else if(color[c] == 2)  color[b] = 1, color[a] = 3;
	        else color[b] = 1, color[a] = 2;
	    }
	}
	rep(i, 1, n+1)    cout<<color[i]<<" ";
// 	}
	return 0;
}
