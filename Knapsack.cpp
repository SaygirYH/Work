#include <bits/stdc++.h>

#define st string
#define pb push_back
#define vec vector
#define all(a) a.begin(), a.end()
#define int long long
#define ld long double
#define ff first
#define ss second

using namespace std;

using vl = vec<int>;
using vi = vec<int>;
using vvi = vec<vi>;
using pi = pair<int, int>;
using vpi = vec<pi>;
using vvvi = vec<vvi>;

void solve() {
  int n, W; cin >> n >> W;
  vi w(n);
  vi p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i]; //reversed p and w
    cin >> w[i];
  }
  int ans = 0;
  vi parents;
  for (int i = 0; i < (1 << n); i++) {
    bitset<20> b = i;
    int nowProfit = 0, nowW = 0;
    for (int j = 0; j < 20; j++) {
      if (b[j] == 1) {
        nowProfit += p[j];
        nowW += w[j];
      }
    }
    if (nowW <= W && nowProfit > ans) {
      ans = nowProfit;
      parents = {};
      for (int j = 0; j < 20; j++) {
        if (b[j]) {
          parents.pb(j);
        }
      }
    }
    else if (nowW <= W && nowProfit == ans) {
      vi pars;
      for (int j = 0; j < 20; j++) {
        if (b[j]) {
          pars.pb(j);
        }
      }
      if (pars.size() < parents.size()) {
        parents = {};
        for (auto u : pars) {
          parents.pb(u);
        }
      }
      else if (pars.size() != 0 && pars.size() == parents.size() && pars[0] < parents[0]) {
        parents = {};
        for (auto u : pars) {
          parents.pb(u);
        }
      }
    }
  }
  cout << parents.size() << " " << ans << endl;
  for (auto u : parents) {
    cout << u + 1 << " ";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
