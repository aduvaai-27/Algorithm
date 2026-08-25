#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int main()
{
    int node;
    int edge;
    cin >> node >> edge;
    vector<vector<int>> dist(node, vector<int>(node, INF));
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w; // input for matrix
    }
    for (int i = 0; i < node; i++)
    {
        dist[i][i] = 0;
    }
    for (int k = 0; k < node; k++)
    { // k is the intermediate node
        for (int i = 0; i < node; i++)
        { // i is the source node
            for (int j = 0; j < node; j++)
            {                                                          // j is the destination node
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // relaxation
            }
        }
    }
    for (int i = 0; i < node; i++)
    {
        if (dist[i][i] < 0)
        {
            cout << "Negative Weigted Cycle is Detected" << endl;
            return -1;
        }
    }
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
