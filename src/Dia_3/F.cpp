#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e9;

void bfs(ll start, vector<vector<ll>>& graph, vector<bool>& visitados) {
    queue<ll> q;
    visitados[start] = 1;
    q.push(start);

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : graph[u]) {
            if (!visitados[v]) {
                visitados[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    vector<pair<ll, ll>> edges;
    ll u, v;
    ll max_node = 0;

    // Leer los pares (u, v) hasta el final de la entrada
    for(int i=0;i<)
    while (cin >> u >> v) {
        edges.push_back({u, v});
        max_node = max(max_node, max(u, v));
    }

    // Ajustar el tamaño del grafo basado en el nodo más grande
    vector<vector<ll>> graph(max_node);
    for (auto edge : edges) {
        u = edge.first;
        v = edge.second;
        u--; v--;  // Ajustar a índices base 0
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visitados(max_node, false); // Inicializa todos los nodos como no visitados
    ll islas = 0;

    for (ll i = 0; i < max_node; i++) {
        if (!visitados[i]) {
            bfs(i, graph, visitados);
            islas++;
        }
    }

    cout << islas << endl;

    return 0;
}
