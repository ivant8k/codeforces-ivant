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
    vll p(n);
    for (int i = 0; i<n; i++){
        cin>>p[i];
    }
    vll suff_max(n);
    suff_max[n-1] = p[n-1];
    for (int i = n-2; i>=0; i--){
        suff_max[i] = max(suff_max[i+1], p[i]);
    }

    ll curr_min = p[0];
    bool possible = true;

    for (int i = 0; i < n - 1; i++){
        curr_min = min(curr_min, p[i]);
        if (curr_min > suff_max[i+1]){
            possible = false;
            break;
        }
    }
    if (possible){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;}
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