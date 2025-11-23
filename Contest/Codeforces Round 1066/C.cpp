#include <bits/stdc++.h>
#ifdef LOCAL
#include <sys/resource.h>
#endif
using namespace std;

// --- Type Aliases ---
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

// --- Macros ---
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define endl '\n'

// --- Constants ---
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// --- Solution ---
void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<tuple<int, int, int>> queries(q);
    vector<bool> is_type1(n + 1, false);
    vector<bool> is_type2(n + 1, false);

    for (int i = 0; i < q; i ++){
        int c, l, r;
        cin >> c >> l >> r;
        queries[i] = make_tuple(c, l, r);
        for (int j = l; j <= r; j++){
            if (c == 1) {
                is_type1[j] = true;
            } else {
                is_type2[j] = true;
            }
        }
    }
    vi a(n+1);
    for (int i = 1; i <= n; i++){
        if (is_type1[i] && is_type2[i]){
            a[i] = k + 1;
        } else if (is_type1[i]){
            a[i] = k;
        } else {
            a[i] = 1e9; // Kosong
        }
    }

    for (const auto& qry : queries){
        auto [c, l, r] = qry;
        if (c == 2) {
            for (int val = 0; val < k; val++){
                bool exists = false;
                for (int j = l; j <= r; j++){
                    if (a[j] == val){
                        exists = true;
                        break;
                    }
                }
                if (!exists){
                    for (int j = l; j <= r; j++){
                        if (!is_type1[j] && a[j] == 1e9){
                            a[j] = val;
                            break;
                        }
                    }
                }
            }
        }
    }
    // Cleanup
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1e9) a[i] = k + 1;
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << endl;
}

// --- Debug ---
void print_debug() {
#ifdef LOCAL
    struct rusage r;
    getrusage(RUSAGE_SELF, &r);
    cerr << "\n-----------------------------------" << endl;
    cerr << "Time   : " << (double)clock() / CLOCKS_PER_SEC << " s" << endl;
    cerr << "Memory : " << r.ru_maxrss / 1024.0 << " MB" << endl;
    cerr << "-----------------------------------" << endl;
#endif
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef LOCAL
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    print_debug();
    return 0;
}