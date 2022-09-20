#include <bits/stdc++.h>

using namespace std;

//typedef long double ld;
long double x, y;
int i, n, s, sum = 0, buf,
             res = 0;
int di0, dj0, dij;
int m, mcap, wayscnt;


struct route {
    vector<int> v;
    int demand, p, ranc;
};

vector<route> ways;

void craft(int n, vector<int> & need) {
    ways.resize(n);
    for (int i = 1; i < n; i++) {
        ways[i].v = {i};
        ways[i].demand = need[i];
        ways[i].p = i;
        ways[i].ranc = 0;
    }
}

int get_leaf(int u) {
    if (ways[u].p == u) return u;
    return ways[u].p = get_leaf(ways[u].p);
}


void join(int u, int v, int mcap) {
    u = get_leaf(u); v = get_leaf(v);
    if (u == v) return;
    if (ways[u].demand + ways[v].demand > mcap) return;
    wayscnt--;
    if (ways[u].ranc < ways[v].ranc) swap(u, v);
    ways[u].demand += ways[v].demand;
    for (auto r : ways[v].v) {
        ways[u].v.push_back(r);
    }
    ways[v].p = u;
    if (ways[u].ranc == ways[v].ranc) ways[u].ranc++;
}

int tsp(vector<pair<int, int>> & nodes) {
    int n = nodes.size();
    vector<long double> x(n);
    vector<long double> y(n);
    for (int i = 0; i < n; i++) {
        x[i] = nodes[i].first;
        y[i] = nodes[i].second;
    }
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    for (int i = 1; i < n; i++) {
        long double mn = 9999999;
        int ps = i;
        for (int w = i; w < n; w++) {
            long double dst = hypot(x[ans[i - 1]] - x[ans[w]],
                           y[ans[i - 1]] - y[ans[w]]);
            if (dst < mn) {
                mn = dst;
                ps = w;
            }
        }
        swap(ans[i], ans[ps]);
    }
    long double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += hypot(x[ans[i]] - x[ans[(i + 1) % n]], y[ans[i]] - y[ans[(i + 1) % n]]);
    }
    return sum;
}

int main() {
    cin >> n >> m >> mcap;
    wayscnt = n - 1;
    vector<int> need(n);
    vector<pair<int, int>> nodes;
    for (int i = 0; i < n; i++) {
        long double a, b;
        cin >> need[i] >> a >> b;
        nodes.push_back({a, b});
    }
    vector<tuple<long double, int, int>> savings; // save, u, v
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
             di0 = hypot(nodes[0].first  - nodes[i].first,
                         nodes[0].second - nodes[i].second);
             dj0 = hypot(nodes[0].first  - nodes[j].first,
                         nodes[0].second - nodes[j].second);
             dij = hypot(nodes[i].first  - nodes[j].first,
                         nodes[i].second - nodes[j].second);
             s = di0 + dj0 - dij;
            savings.push_back({s, i, j});
        }
    }
    sort(savings.rbegin(), savings.rend());
    craft(n, need);
    for (auto [s, i, j] : savings) {
        join(i, j, mcap);
        if (wayscnt <=  m) break;
    }
    vector<bool> checked(n, false);

    for (int i = 1; i < n; i++) {
        int root = get_leaf(i);
        if (checked[root]) continue;
        vector<pair<int, int>> tnodes;
        tnodes.push_back(nodes[0]);
        for (auto r : ways[root].v) {
            tnodes.push_back(nodes[r]);
        }
        res += tsp(tnodes);
        checked[root] = true;
    }
    cout << res << '\n';
    cin>> s;
}
