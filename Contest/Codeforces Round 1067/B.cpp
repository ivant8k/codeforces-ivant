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
    int N = 2 * n;
    // int odd = 0;
    // int even = 0;
    vector<int> freq(N + 1, 0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    int odd = 0, even = 0;
    for (int i = 1; i <= N; i++) {
        if (freq[i] == 0) continue;
        if (freq[i] & 1) {
            odd++;
        } else {
            even++;
        }
    }
    int v = min(even, n);
    if (odd == 0 & ((v & 1) != (n&1))){
        v--;
    }
    cout << odd + 2 * v << endl;
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