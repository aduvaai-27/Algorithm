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
    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
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

    for (int i = 0; i <= node; i++)
    {
        cout << source << "->" << i << ": ";
        if (dist[i] == INT_MAX)
            cout << "INFINITY" << endl;
        else
        {
            cout << dist[i] << "| Path :";
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