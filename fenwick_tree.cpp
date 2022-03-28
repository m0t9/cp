struct FenwickTree {
    vector<int> t;
    int n;

    FenwickTree(int _n) {
        n = _n;
        t.resize(n, 0);
    }

    int sum(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += t[r];
        }
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void inc(int i, int x) {
        for (; i < n; i = (i | (i + 1))) {
            t[i] += x;
        }
    }

    FenwickTree(vector<int>& a) {
        n = a.size();
        t.resize(n);
        for (int i = 0; i < n; i++) {
            inc(i, a[i]);
        }
    }
};