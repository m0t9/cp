struct Dsu {
    vector<int> p, sz;
    
    Dsu(int n) {
        p.resize(n, 1);
        sz.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int get(int v) {
        if (p[v] != v) {
            p[v] = get(p[v]);
        }
        return p[v];
    }

    void join(int v, int u) {
        v = get(v);
        u = get(u);
        if (v == u) {
            return;
        }
        if (sz[v] > sz[u]) {
            swap(v, u);
        }
        sz[u] += sz[v];
        p[v] = u;
    }

    bool in_same(int v, int u) {
        return get(v) == get(u);
    }
}