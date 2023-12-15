template<int MOD>
class mint {
private:
    template<int MOD2>
    friend istream& operator>>(istream&, mint<MOD2>&);
    template<int MOD2>
    friend ostream& operator<<(ostream&, const mint<MOD2>&);

    ll val;

    ll modpow(ll x, ll p) {
        if (p == 0) {
            return 1LL;
        }
        ll hp = modpow(x, p / 2);
        ll res = (hp * hp) % MOD;
        if (p % 2 == 0) {
            return res;
        }
        return (res * x) % MOD;
    }

public:
    mint() : val(0LL) {}

    mint(const mint<MOD>& other) = default;

    mint(ll val) : val(val % MOD) { }

    mint<MOD> operator+=(const mint<MOD>& other) {
        val = (val + other.val) % MOD;
        return *this;
    }

    mint<MOD> operator-=(const mint<MOD>& other) {
        val = (val - other.val + MOD) % MOD;
        return *this;
    }

    mint<MOD> operator*=(const mint<MOD>& other) {
        val = (val * other.val) % MOD;
        return *this;
    }

    mint<MOD> operator/=(const mint<MOD>& other) {
        auto inv = modpow(other.val, MOD - 2);
        val = (val * inv) % MOD;
        return *this;
    }

    mint<MOD> operator+(const mint<MOD>& other) const {
        auto c(*this);
        c += other;
        return c;
    }

    mint<MOD> operator-(const mint<MOD>& other) const {
        auto c(*this);
        c -= other;
        return c;
    }

    mint<MOD> operator*(const mint<MOD>& other) const {
        auto c(*this);
        c *= other;
        return c;
    }

    mint<MOD> operator/(const mint<MOD>& other) const {
        auto c(*this);
        c /= other;
        return c;
    }
};

template<int MOD>
ostream& operator<<(ostream& out, const mint<MOD>& md) {
    return out << md.val;
}

template<int MOD>
istream& operator>>(istream& in, mint<MOD>& md) {
    return in >> md.val;
}
