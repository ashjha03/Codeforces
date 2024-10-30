ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int MOD = 1e9 + 7;

vector<vector<int>> multiplyMatrices(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    for(int k = 0; k < n; k++)
        res[i][j] = mod_add(res[i][j], mod_mul(a[i][k], b[k][j], MOD), MOD);
    
    return res;
}

vector<vector<int>> matrixEponentiation(vector<vector<int>> &a, int b) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)  res[i][i] = 1;

    while(b > 0) {
        if(b & 1)   res = multiplyMatrices(res, a);
        a = multiplyMatrices(a, a);
        b = b >> 1;
    }
    return res;
}
