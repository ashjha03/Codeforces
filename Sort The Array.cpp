// BAKHTABAR
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
#define yes  cout<<"yes"<<endl
#define no  cout<<"no"<<endl
#define prt(x)     cout<<x<<endl
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

int main() {
    start;
    // ll t; cin>>t;
    // while(t--){
	    ll n; cin>>n;
	    vll v(n); input(v, n);
	    vll temp = v; sort(all(temp));
	    
	    ll cnt = 0, f = 0, low = 0, high = 0;
    	rep(i, 0, n-1){
    		if(v[i] > v[i+1]){
    			if(!f){
    				if(cnt == 1)	break;
    				f = 1;
    				cnt++;
    				low = i;
    				high = i+1;
    			} else	high = i+1;
    		}
    	}
    	reverse(v.begin()+low, v.begin()+high+1);
    	if(v == temp){
    		yes;
    		cout<<low+1<<" "<<high+1<<endl;
    	}
    	else	no;
    // }
	return 0;
}
