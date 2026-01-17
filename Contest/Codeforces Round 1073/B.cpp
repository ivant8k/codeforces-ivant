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
int mex(const vi& v){
    vector<bool> present(v.size() + 2, false);
    for (int x : v) {
        if (x < present.size()) {
            present[x] = true;
        }
    }
    
    int mex = 0;
    while (present[mex]) {
        mex++;
    }
    return mex;
}
void solve() {
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i < n; i++){
        vi prefix, suffix;
        for(int j = 0; j < i; j++){
            prefix.push_back(arr[j]);
        }
        for(int j = i; j < n; j++){
            suffix.push_back(arr[j]);
        }
        int mex_prefix = mex(prefix);
        int mex_suffix = mex(suffix);

        if (mex_prefix == mex_suffix){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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