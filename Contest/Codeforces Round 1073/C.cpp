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
void solve() {
    int n, count0;
    count0 = 0;
    string s;
    cin >> n;
    cin >> s;
    for (char c : s){
        if (c == '0') count0++;
    }

    if(is_sorted(s.begin(), s.end())) {
        cout << "Bob" << endl;
    }
    else {
        cout<< "Alice" << endl;
        vi moves;

        for (int i = 0; i < count0; i++){
            if (s[i] == '1') moves.pb(i);
        }
        for (int i = count0; i < n; i++){
            if (s[i] == '0') moves.pb(i);
        }

        cout << sz(moves) << " " << endl;
        for (int i = 0; i < sz(moves); i++) {
            cout << moves[i] + 1 << (i == sz(moves) - 1 ? "" : " ");
        }
        cout << endl;
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