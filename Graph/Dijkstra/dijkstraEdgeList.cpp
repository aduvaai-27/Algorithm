#include <bits/stdc++.h>

using namespace std;
class Edge
{
public:
    int u;
    int v;
    int w;
};

int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<Edge> graph(edge);
    cout << "Graph Input:" << endl;
    for (int i = 0; i < edge; i++)
    {
        cin >> graph[i].u >> graph[i].v >> graph[i].w;
    }
    vector<int> dist(node, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<int>> path(node);

    int src;
    cout << "Source : ";
    cin >> src;
    dist[src] = 0;
    path[src].push_back(src);
    pq.push({0, src});
    while (pq.size() != 0)
    {
        int s = pq.top().second;
        pq.pop();
        for (int i = 0; i < edge; i++)
        {
            if (graph[i].u != s)
            {
                continue;
            }
            else
            {
                int e = graph[i].v;
                int w = graph[i].w;
                if (dist[s] + w < dist[e])
                {
                    dist[e] = dist[s] + w;
                    pq.push({dist[e], e});
                    path[e] = path[s];
                    path[e].push_back(e);
                }
            }
        }
    }

    cout << "Given Graph : " << endl;
    for (int i = 0; i < edge; i++)
    {
        cout << graph[i].u << " -> " << graph[i].v << " | Weight :" << graph[i].w << endl;
    }

    cout << "Shortest Distance & Path :" << endl;
    cout << "Source : " << src << endl;

    for (int i = 0; i < node; i++)
    {
        if (dist[i] != INT_MAX)
        {
            cout << "Terminal :" << i << " | Cost : " << dist[i] << endl;
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
            cout << "Terminal :" << i << " | Cost : " << "INF" << endl;
        }
    }
    return 0;
}

/*5 6
Graph Input:
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 2
Source : 0*/
