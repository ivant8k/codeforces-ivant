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
    cin>>n;
    vll a(n);
    vll b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    // for (int i = 0; i < n; i++){

    // }
    int XA = 0;
    int XB = 0;
    int last = -1;
    for (int i = 0; i < n; i++){
        XA ^= a[i];
        XB ^= b[i];
        if (a[i] != b[i]){
            last = i+1;
        }
    }
    if (last == -1){
        if (XA > XB) cout << "Ajisai" << endl;
        else if (XA < XB) cout << "Mai" << endl;
        else cout << "Tie" << endl;
    } else {
        if (XA == XB) {
            cout << "Tie" << endl;
        }
        else {
            if (last % 2 == 1) cout << "Ajisai" << endl;
            else cout << "Mai" << endl;
        }
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