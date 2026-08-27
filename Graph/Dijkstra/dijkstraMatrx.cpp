#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<vector<int>> graph(node, vector<int>(node, 0));
    cout << "Graph Input: " << endl;
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    vector<int> dist(node, INT_MAX);
    cout << "Source : ";
    int src;
    cin >> src;
    dist[src] = 0;
    vector<vector<int>> path(node);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    path[src].push_back(src);
    while (pq.size() != 0)
    {
        int st = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[st].size(); i++)
        {
            if (graph[st][i] != 0)
            {
                int v = i;
                int u = st;
                int w = graph[u][v];
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                    path[v] = path[u];
                    path[v].push_back(v);
                }
            }
        }
    }

    cout << "Given Graph : " << endl;
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            if (graph[i][j] > 0)
            {
                cout << i << " -> " << j << " | Weight :" << graph[i][j] << endl;
            }
        }
    }

    cout << "Shortest Distance & Path :" << endl;
    cout << "Source : " << src << endl;
    cout << endl;
    for (int i = 0; i < node; i++)
    {
        if (dist[i] != INT_MAX)
        {
            cout << "Terminal : " << i << " | Cost : " << dist[i] << endl;
            cout << "Path : ";
            for (int j = 0; j < path[i].size(); j++)
            {
                cout << path[i][j];
                if (j < path[i].size() - 1)
                {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
        else
        {
            cout << "Terminal : " << i << " | Cost : " << "INF" << endl;
        }
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
Source : 0
Given Graph : 
0 -> 1 | Weight :2
0 -> 2 | Weight :4
1 -> 0 | Weight :2
1 -> 2 | Weight :1
1 -> 3 | Weight :7
2 -> 0 | Weight :4
2 -> 1 | Weight :1
2 -> 4 | Weight :3
3 -> 1 | Weight :7
3 -> 4 | Weight :2
4 -> 2 | Weight :3
4 -> 3 | Weight :2
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