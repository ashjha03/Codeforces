const int N = 1e5 + 2;
int arr[N], tree[4*N];
ll n;

int buildTree(int node, int ss, int se){
    if(ss == se){
        return tree[node] = arr[ss];
    }

    int mid = ss + (se - ss)/2;
    int left = buildTree(2*node, ss, mid);
    int right = buildTree(2*node+1, mid+1, se);
    return tree[node] = max(left, right);
}

int query(int l, int r, int node = 1, int ss = 0, int se = n-1){
    if(l > se or r < ss)    return INT_MIN;
    if(l <= ss and r >= se) return tree[node];

    int mid = ss + (se - ss)/2;
    int left = query(l, r, 2*node, ss, mid);
    int right = query(l, r, 2*node+1, mid+1, se);

    return max(left, right);
}

void update(int idx, int val, int node = 1, int ss = 0, int se = n-1){
    if(ss == se and ss == idx){
        arr[ss] = tree[node] = val;
        return;
    }
    int mid = ss + (se - ss)/2;
    if(idx <= mid)  update(idx, val, 2*node, ss, mid);
    else    update(idx, val, 2*node+1, mid+1, se);

    tree[node] = max(tree[2*node], tree[2*node + 1]);
}

void solve(){
    cin>>n;
    rep(i, 0, n)    cin>>arr[i];
    buildTree(1, 0, n-1);
    // rep(i, 1, 2*n)  cout<<tree[i]<<' ';
    int q; cin>>q;
    while(q--){
        int type; cin>>type;
        if(type == 1){
            int l, r; cin>>l>>r;
            prt(query(l, r));
        } else {
            int idx, val; cin>>idx>>val;
            update(idx, val);
        }
    }
}
