#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int main()
{
    int node;
    int edge;
    cin >> node >> edge;
    vector<vector<int>> dist(node, vector<int>(node, INF));
    vector<vector<vector<int>>> path(node, vector<vector<int>>(node));
    cout << "Graph Input : " << endl;

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w; // input for matrix
        path[u][v] = {u, v};
    }
    for (int i = 0; i < node; i++)
    {
        dist[i][i] = 0;
        path[i][i] = {i};
    }
    for (int k = 0; k < node; k++)
    { // k is the intermediate node
        for (int i = 0; i < node; i++)
        { // i is the source node
            for (int j = 0; j < node; j++)
            {
                if ((dist[i][k] != INF && dist[k][j] != INF) && (dist[i][j] > dist[i][k] + dist[k][j]))
                {
                    dist[i][j] = dist[i][k] + dist[k][j]; // relaxation

                    path[i][j] = path[i][k];

                    for (int p = 1; p < path[j][k].size(); p++)
                    {

                        path[i][j].push_back(path[k][j][p]);
                    }

                } // j is the destination node
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

    cout << "Distance : " << endl;
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

    cout << "Path Printing : " << endl;
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            if (dist[i][j] != INF)
            {
                cout << "Source :" << i << " | Destination : " << j << " | Cost : " << dist[i][j] << endl;

                cout << "Path : ";

                for (int k = 0; k < path[i][j].size(); k++)
                {
                    cout << path[i][j][k];
                    if (k != path[i][j].size() - 1)
                    {
                        cout << " -> ";
                    }
                }
                cout << endl;
            }
            else
            {
                cout << "Source :" << i << " | Destination : " << j << " | Cost : " << "INF" << endl;
            }
        }
    }
    return 0;
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

OUTPUT: 
Distance : 
0 2 3 9 6 
INF 0 1 7 4 
INF INF 0 INF 3 
INF INF INF 0 2 
INF INF INF INF 0 
Path Printing : 
Source :0 | Destination : 0 | Cost : 0
Path : 0
Source :0 | Destination : 1 | Cost : 2
Path : 0 -> 1
Source :0 | Destination : 2 | Cost : 3
Path : 0 -> 1
Source :0 | Destination : 3 | Cost : 9
Path : 0 -> 1
Source :0 | Destination : 4 | Cost : 6
Path : 0 -> 1
Source :1 | Destination : 0 | Cost : INF
Source :1 | Destination : 1 | Cost : 0
Path : 1
Source :1 | Destination : 2 | Cost : 1
Path : 1 -> 2
Source :1 | Destination : 3 | Cost : 7
Path : 1 -> 3
Source :1 | Destination : 4 | Cost : 4
Path : 1 -> 2
Source :2 | Destination : 0 | Cost : INF
Source :2 | Destination : 1 | Cost : INF
Source :2 | Destination : 2 | Cost : 0
Path : 2
Source :2 | Destination : 3 | Cost : INF
Source :2 | Destination : 4 | Cost : 3
Path : 2 -> 4
Source :3 | Destination : 0 | Cost : INF
Source :3 | Destination : 1 | Cost : INF
Source :3 | Destination : 2 | Cost : INF
Source :3 | Destination : 3 | Cost : 0
Path : 3
Source :3 | Destination : 4 | Cost : 2
Path : 3 -> 4
Source :4 | Destination : 0 | Cost : INF
Source :4 | Destination : 1 | Cost : INF
Source :4 | Destination : 2 | Cost : INF
Source :4 | Destination : 3 | Cost : INF
Source :4 | Destination : 4 | Cost : 0
Path : 4*/
