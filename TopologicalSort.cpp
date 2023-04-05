void dfs(int node){
	vis[node] = 1;
	time_in[node] = dfs_timer++;
	for(auto child: adj[node])
		if(!vis[child])	dfs(child);
	time_out[node] = dfs_timer++;
}

void topoSort(){
	rep(i, 1, n+1)
		if(!vis[i])	dfs(i);
	vector<pii> res;
	rep(i, 1, n+1)	res.pb({time_out[i], i});
	sort(rall(res));
	rep(i, 0, n)	cout<<res[i].ff<<' '<<res[i].ss<<' '<<endl;
}
