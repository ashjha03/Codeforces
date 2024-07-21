vector<long long> hash, p_powers;
void compute_hash(string &s, long long p = 31, long long m = 1e9 + 9) {
    hash.resize(n + 1, 0); p_powers.resize(n + 1, 0);
    p_powers[0] = 1;
    for (int i = 1; i < n; ++i)
        p_powers[i] = (p_powers[i - 1] * p) % m;
    
    for (int i = 0; i < n; ++i)
        hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * p_powers[i]) % m;
}

long long substring_hash(int l, int r, long long m = 1e9 + 9) {
    long long hash_value = (hash[r + 1] - hash[l] + m) % m;
    hash_value = (hash_value * p_powers[hash.size() - 2 - l]) % m;
    return hash_value;
}
