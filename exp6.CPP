#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    const int INF = 1e9;
    vector<int> dist(V, INF);

    dist[src] = 0;

    // Relax all edges V - 1 times
    for (int i = 0; i < V - 1; i++) {
        bool updated = false;

        for (auto &edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }

        // Early termination if no distance changes
        if (!updated) break;
    }

    // Check for a negative-weight cycle
    for (auto &edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Negative weight cycle detected\n";
            return;
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << '\n';
    }
}

int main() {
    int V = 5, E = 8;

    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int src = 0;

    bellmanFord(V, E, edges, src);

    return 0;
}




