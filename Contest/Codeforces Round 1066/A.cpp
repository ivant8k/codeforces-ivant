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
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    map<ll, ll> freq;
    for (ll x : a){
        freq[x]++;
    }
    int total_deletion = 0;

    // Kasus elemen 0
    if (freq.count(0)) {
        total_deletion += freq[0];
        freq.erase(0);
    }

    for (const auto& pair : freq){
        int x = pair.first;
        int freq_x = pair.second;

        if (freq_x >= x){
            int deletions_to_keep_x = freq_x - x;
            total_deletion += deletions_to_keep_x;
        } else {
            total_deletion += freq_x;
        }
    }
    cout << total_deletion << endl;
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