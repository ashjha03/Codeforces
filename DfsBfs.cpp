const int N = 1e3+2;
ll n;
vector<ll> adj[N];
vb vis(N, false);


void dfs(int node){
	vis[node] = 1;
	cout<<node<<' ';
	for(auto child: adj[node])
		if(!vis[child])	dfs(child);}


vector<int> color;
vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs2(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for(int u : adj[v])
        if(!color[u])	dfs2(u);
    color[v] = 2;
    time_out[v] = dfs_timer++;
}



void bfs(int source){
	queue<int> q;
	q.push(source);
	vi res; res.pb(source); vis[source] = 1;
	vi dist(n+1, 0), parent(n+1, -1);

	while(!q.empty()){
		auto node = q.front(); q.pop();
		for(auto child: adj[node])
			if(!vis[child]){
				res.pb(child); q.push(child); vis[child] = 1; 
				dist[child] = dist[node] + 1;
				parent[child] = node;
			}
	}

	// Output The Results
	output(res, n); nl;
	rep(i, 0, n)	cout<<dist[i+1]<<' '; nl;
	rep(i, 0, n)	cout<<parent[i+1]<<' '; nl;


	// Find Shortest Path from source to Vertex v
	int v = 5;
	if(!vis[v])	prt("No Path");
	else {
		vi path;
		for(auto i = v; i!=-1; i = parent[i])	path.pb(i);
		reverse(all(path));
		output(path, path.size()); nl;
	}}

void countConnectedComponents(){
	int count = 0;
	rep(i, 1, n+1)
		if(!vis[i])	dfs(i), nl, count++;
	prt(count);
}

void solve(){
	ll m; cin>>n>>m;
	while(m--){
		ll a, b; cin>>a>>b;
		adj[a].pb(b); adj[b].pb(a);
	}
	countConnectedComponents();
}
