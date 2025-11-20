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
    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll left = a[0];
    ll right = a[n-1];

    if (left == -1 && right == -1){
        left = 0;
        right = 0;
    } else if (left == -1) {
        left = right;
    } else if (right == -1) {
        right = left;
    }

    vll ans(n);
    ans[0] = left;
    ans[n-1] = right;
    for (int i = 1; i < n-1; i++) {
        if (a[i] == -1)
            ans[i] = 0;
        else
            ans[i] = a[i];
    }
    ll value = llabs(right - left);

    cout << value << endl;
    for (int i = 0; i< n; i++) {
        cout << ans[i] <<(i+1<n?" ":"\n");
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