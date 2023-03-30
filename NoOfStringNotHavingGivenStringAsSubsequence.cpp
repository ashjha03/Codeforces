// BAKHTABAR
#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n)    for(ll i=j; i<n; i++)
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define vb vector<bool>
#define vi vector<int>
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
#define yes  cout<<"Yes"<<endl
#define no  cout<<"No"<<endl
#define prt(x)     cout<<x<<endl
#define INF (int)1e9
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



// No. Of String of length N, not having 0100 as a subsequence

ll n;
int dp[100010][5];
ll rec(ll level, ll match){
	// Pruning
	if(match == 4)	return 0;
	// Base Case
	if(level == n)	return 1;

	// Cache Check
	if(dp[level][match] != -1)	return dp[level][match];

	// Compute
	ll res = rec(level+1, match) + rec(level+1, match+1);

	// Save and Return
	return dp[level][match] = res;
}



void solve(){
	cin>>n;
	memset(dp, -1, sizeof(dp));
	prt(rec(0, 0));
}
 
 
 

 
 
 
 
// CODE HERE
signed main() {
    star;
    ll t; cin>>t; while(t--){solve();}
    // solve();
	return 0;
}
