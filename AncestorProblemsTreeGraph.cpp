const int N = 1e3+2;
ll n;
vector<ll> adj[N];
vb vis(N, false);


void dfs(int node){
	vis[node] = 1;
	cout<<node<<' ';
	for(auto child: adj[node])
		if(!vis[child])	dfs(child);}


vector<int> color(N);
vector<int> time_in(N), time_out(N);
int dfs_timer = 0;

void dfs2(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for(int u : adj[v])
        if(!color[u])	dfs2(u);
    color[v] = 2;
    time_out[v] = dfs_timer++;
}



bool checkIsAncestor(int i, int j){
	dfs2(1);
	if(time_in[i] < time_in[j] and time_out[i] > time_out[j])
		return true;
	return false;
}

int lowestCommonAncestor(int i, int j){
	dfs2(1); // O(V + E)
	int res = -1, res_in = INF, res_out = EPS;
	rep(k, 1, n+1){ // O(V)
		if(time_in[k] < time_in[i] and time_in[k] < time_in[j]
			and time_out[k] > time_out[i] 
			and time_out[k] > time_out[j])
				if(res_in > time_in[k] and res_out < time_out[k]){
					res = k;
					res_in = time_in[k];
					res_out = time_out[k];
				}
	}
	return res;
}



void solve(){
	ll m; cin>>n>>m;
	while(m--){
		ll a, b; cin>>a>>b;
		adj[a].pb(b); adj[b].pb(a);
	}
	prt(lowestCommonAncestor(11, 6));
}



 
