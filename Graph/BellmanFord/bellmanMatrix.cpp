#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<vector<int>> graph(node, vector<int>(node, 0));
    cout << "Graph Input : " << endl;
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;
    cout << "Source :";

    cin >> source;

    cout << "Given Graph : " << endl;

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            if (graph[i][j] != 0)
            {
                cout << i << " <-> " << j << " | Weight : " << graph[i][j] << endl;
            }
        }
    }
    vector<int> dist(node, INT_MAX);
    vector<vector<int>> path(node);
    dist[source] = 0;
    path[source].push_back(source);
    for (int i = 0; i < node - 1; i++)
    {

        for (int j = 0; j < node; j++)
        {
            int u = j;
            for (int k = 0; k < node; k++)
            {
                int v = k;
                int w = graph[j][k];
                if (w != 0)
                {
                    if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                    {
                        dist[v] = dist[u] + w;
                        path[v] = path[u];
                        path[v].push_back(v);
                    }
                }
            }
        }
    }

    for (int j = 0; j < node; j++)
    {
        int u = j;
        for (int k = 0; k < node; k++)
        {
            int v = k;
            int w = graph[j][k];
            if (w = 0)
            {
                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = INT_MIN;
                }
            }
        }
    }

    cout << "Shortest Distance & Path : " << endl;

    cout << "Source : " << source << endl;

    for (int i = 0; i < node; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "Terminal : " << i << " | Cost : " << "INF" << endl;
        }
        else if (dist[i] == INT_MIN)
        {
            cout << "Terminal : " << i << " | Cost : " << "Negative Cycle Detected." << endl;
        }
        else
        {
            cout << "Terminal : " << i << " | Cost : " << dist[i] << endl;
            cout << "Path : ";
            for (int j = 0; j < path[i].size(); j++)
            {
                cout << path[i][j];
                if (j != path[i].size() - 1)
                {
                    cout << " -> ";
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
Source :0

OUTPUT:
Given Graph : 
0 <-> 1 | Weight : 2
0 <-> 2 | Weight : 4
1 <-> 0 | Weight : 2
1 <-> 2 | Weight : 1
1 <-> 3 | Weight : 7
2 <-> 0 | Weight : 4
2 <-> 1 | Weight : 1
2 <-> 4 | Weight : 3
3 <-> 1 | Weight : 7
3 <-> 4 | Weight : 2
4 <-> 2 | Weight : 3
4 <-> 3 | Weight : 2
Shortest Distance & Path : 
Source : 0
Terminal : 0 | Cost : 0
Path : 0
Terminal : 1 | Cost : 2
Path : 0 -> 1
Terminal : 2 | Cost : 3
Path : 0 -> 1 -> 2
Terminal : 3 | Cost : 8
Path : 0 -> 1 -> 2 -> 4 -> 3
Terminal : 4 | Cost : 6
Path : 0 -> 1 -> 2 -> 4*/