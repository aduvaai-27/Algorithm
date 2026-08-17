#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<vector<pair<int, int>>> graph(node + 1);

    cout << "Graph Input: " << endl;
    for (int i = 1; i <= edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cin >> source;
    vector<int> dist(node + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (pq.size() != 0)
    {
        int u = pq.top().second;
        pq.pop();
        for (auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Graph Output: " << endl;
    for (int i = 1; i <= node; i++)
    {
        cout << i << " ->" << " ";
        for (auto edge : graph[i])
        {
            cout << "(" << edge.first << " " << edge.second << ")";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Shortest Path: " << endl;
    for (int i = 1; i <= node; i++)
    {
        cout << source << "-> " << i << " " << "Cost: ";
        if (dist[i] == INT_MAX)
        {
            cout << "INFINITY" << endl; // NO_WAY_TO_GO
        }
        else
        {
            cout << dist[i] << endl;
        }
    }
}