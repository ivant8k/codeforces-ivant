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
using mii = map<int, int>;

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
struct Op {
    int id;
    int val; 
};

void solve() {
    int n, m; 
    ll h;
    cin >> n >> m >> h;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> all_ops(m);
    vector<vector<Op>> ops_by_idx(n);

    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        b--;
        all_ops[i] = {b, c};
        ops_by_idx[b].push_back({i, c});
    }

    vector<int> nxt_crash(m + 1, m);

    for (int i = 0; i < n; i++) {
        ll limit = h - a[i];
        ll current_sum = 0;
        int l = 0;
        
        for (int r = 0; r < ops_by_idx[i].size(); r++) {
            current_sum += ops_by_idx[i][r].val;
            while (current_sum > limit) {
                int start_op = ops_by_idx[i][l].id;
                int crash_op = ops_by_idx[i][r].id;
                
                if (crash_op < nxt_crash[start_op]) {
                    nxt_crash[start_op] = crash_op;
                }

                current_sum -= ops_by_idx[i][l].val;
                l++;
            }
        }
    }

    for (int i = m - 2; i >= 0; i--) {
        nxt_crash[i] = min(nxt_crash[i], nxt_crash[i+1]);
    }

    int current_start = 0;
    while (current_start < m && nxt_crash[current_start] < m) {
        current_start = nxt_crash[current_start] + 1;
    }

    for (int i = current_start; i < m; i++) {
        int idx = all_ops[i].first;
        int val = all_ops[i].second;
        a[idx] += val;
    }

    // Output
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
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