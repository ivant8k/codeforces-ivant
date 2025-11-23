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
    ll x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    // Boundary -> Fokus kuadran 1 saja karena simetris
    ll X = abs(x);
    ll Y = abs(y);

    int count8 = 0;
    for (char c : s) {
        if (c == '8') {
            count8++;
        }
    }

    // Cek batas paling luar aja
    ll D_max = max(X,Y); // Chebyshev distance
    ll Man_dist = X + Y; // Manhattan distance

    // Kalau D_max > total langkah udah pasti NO
    if (D_max > n){
        cout << "NO" << endl;
        return;
    }

    if (Man_dist <= n + count8) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

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