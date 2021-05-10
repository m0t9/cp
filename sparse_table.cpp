vector<vector<ll>> generate_sparse_table(const vector<ll>& array) {
    vector<vector<ll>> sparse_table;
    sparse_table.push_back(array);

    vector<ll> powers = {1};
    for (ll i = 1; i <= array.size(); i++) {
        powers.push_back(powers.back() * 2);
    }

    for (ll i = 1; i <= log2(array.size()); i++) {
        vector<ll> new_row;
        for (ll j = 0; j <= array.size() - powers[i]; j++) {
            new_row.push_back(min(sparse_table[i - 1][j], sparse_table[i - 1][j + powers[i - 1]]));
        }
        sparse_table.emplace_back(new_row);
    }
    return sparse_table;
}

ll get_answer(ll left, ll right, const vector<vector<ll>>& sparse_table) {
    if (left == right) {
        return sparse_table[0][left];
    }
    right++;
    int power = __lg(right - left);
    return min(sparse_table[power][left], sparse_table[power][right - (1 << power)]);
}
