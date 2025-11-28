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
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    if (n == 2) {
        cout << 9 << endl;
        return;
    }
    // vector<vector<ll>> M(n, vector<ll>(n));
    // int val = 1;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         M[i][j] = val++;
    //     }
    // }
    ll n2 = n * n;
    ll costInterior = 5 * (n2 - n - 1);
    ll costBottom = 4 * n2 - n - 4;
    cout << max(costInterior, costBottom) << endl;

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