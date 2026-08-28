#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u;
    int v;
    int weight;
};

int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<Edge> edges(edge);
    cout << "Graph Input : " << endl;
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }
    int source;
    cout << "Source : ";
    cin >> source;
    vector<int> dist(node + 1, INT_MAX);

    dist[source] = 0;
    vector<vector<int>> path(node + 1);
    path[source].push_back(source);
    for (int i = 0; i < node - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                path[v] = path[u];
                path[v].push_back(v);
            }
        }
    }
    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            dist[v] = -1;
        }
    }

    for (int i = 0; i < node; i++)
    {
        cout << source << "->" << i << " | Cost : " << ": ";
        if (dist[i] == INT_MAX)
            cout << "INFINITY" << endl;
        else
        {
            cout << dist[i] << "| Path : ";
            for (int j = 0; j < path[i].size(); j++)
            {
                cout << " " << path[i][j] << " ";
                if (j != path[i].size() - 1)
                {
                    cout << "->";
                }
            }
            cout << endl;
        }
    }
}

/*
INPUT:
5 6
Graph Input :
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 2
Source : 0
OUTPUT:
0->0 | Cost : : 0| Path :  0
0->1 | Cost : : 2| Path :  0 -> 1
0->2 | Cost : : 3| Path :  0 -> 1 -> 2
0->3 | Cost : : 8| Path :  0 -> 1 -> 2 -> 4 -> 3
0->4 | Cost : : 6| Path :  0 -> 1 -> 2 -> 4 */
