#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> p;

    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        p[a] = b;
        return true;
    }
};

// Prim's Algorithm
int prim(int n, vector<vector<pair<int,int>>> &adj) {
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    vector<bool> vis(n, false);
    pq.push({0, 0});

    int ans = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;

        vis[u] = true;
        ans += w;

        for (auto [v, wt] : adj[u]) {
            if (!vis[v])
                pq.push({wt, v});
        }
    }

    return ans;
}

// Kruskal's Algorithm
int kruskal(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.w < b.w;
         });

    DSU dsu(n);
    int ans = 0;

    for (auto [u, v, w] : edges) {
        if (dsu.unite(u, v))
            ans += w;
    }

    return ans;
}

int main() {
    int n = 5;

    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    vector<vector<pair<int,int>>> adj(n);

    for (auto [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "Prim MST = " << prim(n, adj) << endl;
    cout << "Kruskal MST = " << kruskal(n, edges) << endl;

    return 0;
}
