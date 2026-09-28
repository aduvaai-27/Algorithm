#include<bits/stdc++.h>
using namespace std;

int n, e;
int graph[100][100];
int originalGraph[100][100];
bool visited[100];

bool dfs(int u, int sink, int parent[]) {
    if (u == sink) return true;

    visited[u] = true;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && graph[u][v] > 0) {
            parent[v] = u;
            if (dfs(v, sink, parent)) {
                return true;
            }
        }
    }
    return false;
}

int FordFulkerson(int source, int sink) {
    int maxFlow = 0;
    int parent[100];

    while (true) {
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        bool found = dfs(source, sink, parent);
        if (found == false) break;

        int flow = INT_MAX;
        int v = sink;
        while (v != source) {
            int u = parent[v];
            flow = min(graph[u][v], flow);
            v = u;
        }

        v = sink;
        while (v != source) {
            int u = parent[v];
            graph[u][v] -= flow;
            graph[v][u] += flow;
            v = u;
        }

        maxFlow += flow;
    }

    return maxFlow;
}

void printFlow() {
    cout << "\nFlow on each edge:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (originalGraph[i][j] > 0) {
                int flowUsed = originalGraph[i][j] - graph[i][j];
                if (flowUsed > 0) {
                    cout << i << " -> " << j << " : " << flowUsed << "/" << originalGraph[i][j] << endl;
                }
            }
        }
    }
}

int main() {
    cin >> n >> e;
    srand(time(0));

    int cnt = 0;
    while (cnt < e) {
        int u = rand() % n;
        int v = rand() % n;

        if (u == v || originalGraph[u][v] != 0) {
            continue;
        }

        int cap = rand() % 10 + 1;
        originalGraph[u][v] = cap;
        graph[u][v] = cap;
        cnt++;
    }

    cout << "Max Flow: " << FordFulkerson(0, n - 1) << endl;
    printFlow();

    return 0;
}
