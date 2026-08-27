#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<vector<pair<int, int>>> graph(node + 1);

    cout << "Graph Input: " << endl;
    for (int i = 0; i < edge; i++)
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
    vector<vector<int>> path(node);
    path[source].push_back(source);

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
                path[v] = path[u];
                path[v].push_back(v);
            }
        }
    }

    cout << "Graph Output: " << endl;
    for (int i = 0; i < node; i++)
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
    for (int i = 0; i < node; i++)
    {
        cout << source << "-> " << i << " " << "Cost: ";
        if (dist[i] == INT_MAX)
        {
            cout << "INFINITY" << endl; // NO_WAY_TO_GO
        }
        else
        {
            cout << dist[i] << endl;
            cout << "Path : ";
            for (int j = 0; j < path[i].size(); j++)
            {
                cout << path[i][j];
                if (j != (path[i].size() - 1))
                {
                    cout << "->";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

/*5 6
Graph Input: 
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 2
Source: 0*/
