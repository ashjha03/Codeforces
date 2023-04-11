// BAKHTABAR
#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n)    for(ll i=j; i<n; i++)
#define ll long long
#define int ll
#define ld long double
#define pb push_back
#define mp make_pair
#define vb vector<bool>
#define vi vector<int>
#define vc vector<char>
#define vvc vector<vc>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define pii pair<ll, ll>
#define vpii vector<pii>
#define mpi map<int, int>
#define mpl map<ll, ll>
#define sti set<int>
#define stl set<ll>
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define input(a, n)            \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define output(a, n)           \
    for (ll i = 0; i < n; i++) \
        cout << a[i] << " ";
#define star   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define nl cout << "\n"
#define yes  cout<<"YES"<<endl
#define no  cout<<"NO"<<endl
#define prt(x)     cout<<x<<endl
#define INF 1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
vb sieve(ll n){
	vb is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;

	for(ll i=2; i*i<=n; i++)
		if(is_prime[i])
			for(ll j=i*i; j<=n; j+=i)	is_prime[j] = false;

	return is_prime;}
ll binpow(ll a, ll b){
	if(b == 0)	return 1;
	ll res = binpow(a, b/2);
	if(b&1)	return res*res*a;
	else	return res*res;}
ll binpow(ll a, ll b, ll m){
	a %= m;
	ll res = 1;
	while(b > 0){
		if(b&1)	res = res * a % m;
        a = a * a % m;
        b >>= 1;
	}
	return res;}
ll lcm(ll a, ll b){
	return a*b/__gcd(a, b);}


const int N = 1e5+223;
vvll adj(N);
ll n, m;

vector<bool> visited;
vector<int> tin, low;
vector<pii> IS_BRIDGE;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE.pb({v, to});
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void solve(){
	cin>>n>>m;
	rep(i, 0, m){
		ll a, b; cin>>a>>b;
		adj[a].pb(b); adj[b].pb(a);
	}
	find_bridges();
	if(IS_BRIDGE.size())	prt("BRIDGES IN THE GRAPH ARE : ");
	for(auto x: IS_BRIDGE)
		cout<<x.ff<<' '<<x.ss<<endl;
}






// CODE HERE
signed main() {
    star;
    // ll t; cin>>t; while(t--){solve();}
    solve();
	return 0;
}





