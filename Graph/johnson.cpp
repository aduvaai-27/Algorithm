#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
struct Edge
{
    int u;
    int v;
    int w;
};

vector<int> bellman(int node, vector<Edge> &edges, int source)
{
    vector<int> dist(node, INF);
    dist[source] = 0;
    for (int i = 0; i < node - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            return {};
        }
    }

    return dist;
}

vector<int> dijkstra(int node, vector<vector<pair<int, int>>> &graph, int source, vector<vector<int>> &path)
{
    vector<int> dist(node, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    path[source] = {source};
    pq.push({0, source});

    while (pq.size() != 0)
    {
        int u = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                path[v] = path[u];
                path[v].push_back(v);
            }
        }
    }

    return dist;
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<Edge> edges(edge);
    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int newSrc = node;
    for (int i = 0; i < node; i++)
    {
        edges.push_back({newSrc, i, 0});
    }

    vector<int> h = bellman(node + 1, edges, node);

    vector<vector<pair<int, int>>> graph(node);

    for (int i = 0; i < edge; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        w = w + h[u] - h[v];
        graph[u].push_back({v, w});
    }

    for (int i = 0; i < node; i++)
    {
        vector<vector<int>> path(node);
        vector<int> dist = dijkstra(node, graph, i, path);

        for (int j = 0; j < node; j++)
        {
            cout << "Source : " << i << " | Terminal : " << j;
            if (dist[j] == INF)
            {
                cout << " | Cost : " << "INF" << endl;
            }
            else
            {
                cout << " | Cost : " << dist[j] - h[i] + h[j] << endl;
                cout << "Path : ";
                for (int p = 0; p < path[j].size(); p++)
                {

                    cout << path[j][p];
                    if (p != path[j].size() - 1)
                    {
                        cout << " -> ";
                    }
                }
            }
        }
    }
}

/*
5 6
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 2
Source : 0 | Terminal : 0 | Cost : 0
Path : 0
Source : 0 | Terminal : 1 | Cost : 2
Path : 0 -> 1
Source : 0 | Terminal : 2 | Cost : 3
Path : 0 -> 1 -> 2
Source : 0 | Terminal : 3 | Cost : 9
Path : 0 -> 1 -> 3
Source : 0 | Terminal : 4 | Cost : 6
Path : 0 -> 1 -> 2 -> 4
Source : 1 | Terminal : 0 | Cost : INF
Source : 1 | Terminal : 1 | Cost : 0
Path : 1
Source : 1 | Terminal : 2 | Cost : 1
Path : 1 -> 2
Source : 1 | Terminal : 3 | Cost : 7
Path : 1 -> 3
Source : 1 | Terminal : 4 | Cost : 4
Path : 1 -> 2 -> 4
Source : 2 | Terminal : 0 | Cost : INF
Source : 2 | Terminal : 1 | Cost : INF
Source : 2 | Terminal : 2 | Cost : 0
Path : 2
Source : 2 | Terminal : 3 | Cost : INF
Source : 2 | Terminal : 4 | Cost : 3
Path : 2 -> 4
Source : 3 | Terminal : 0 | Cost : INF
Source : 3 | Terminal : 1 | Cost : INF
Source : 3 | Terminal : 2 | Cost : INF
Source : 3 | Terminal : 3 | Cost : 0
Path : 3
Source : 3 | Terminal : 4 | Cost : 2
Path : 3 -> 4
Source : 4 | Terminal : 0 | Cost : INF
Source : 4 | Terminal : 1 | Cost : INF
Source : 4 | Terminal : 2 | Cost : INF
Source : 4 | Terminal : 3 | Cost : INF
Source : 4 | Terminal : 4 | Cost : 0
Path : 4*/