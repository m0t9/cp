struct LinearSieve {
    vector<int> primes, min_factor;
    int sz;

    void build() {
        for (int i = 2; i <= sz; i++) {
            if (min_factor[i] == 0) {
                min_factor[i] = i;
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && primes[j] <= min_factor[i] && i * primes[j] <= sz; j++) {
                min_factor[i * primes[j]] = primes[j];
            }
        }
    }

    LinearSieve(int n) {
        sz = n;
        min_factor.resize(sz + 1);
        build();
    }

    bool is_prime(int p) {
        return min_factor[p] == p;
    }
};
