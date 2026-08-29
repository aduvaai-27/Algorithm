#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int N = 100;
int node, edge;
vector<vector<pair<int, int>>> graph(N);

long long getCost(int u, int v)
{
    if (u == v)
        return 0;
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (graph[u][i].first == v)
        {
            return graph[u][i].second;
        }
    }
    return INF;
}

void setCost(int u, int v, int w)
{
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (graph[u][i].first == v)
        {
            graph[u][i].second = w;
            return;
        }
    }
    graph[u].push_back({v, w});
}

int main()
{

    cin >> node >> edge;
    vector<vector<vector<int>>> path(node, vector<vector<int>>(node));

    cout << "Graph Input : " << endl;
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        path[u][v] = {u, v};
    }
    for (int i = 0; i < node; i++)
    {

        path[i][i] = {i};
    }


    for (int k = 0; k < node; k++)
    {
        for (int i = 0; i < node; i++)
        {
            for (int j = 0; j < node; j++)
            {
                int ik = getCost(i, k);
                int kj = getCost(k, j);
                if (ik != INF && kj != INF)
                {
                    if ((ik + kj) < getCost(i, j))
                    {
                        setCost(i, j, ik + kj);
                        path[i][j] = path[i][k];
                        for (int p = 1; p < path[k][j].size(); p++)
                        {
                            path[i][j].push_back(path[i][k][p]);
                        }
                    }
                }
            }
        }
    }

    for(int i=0;i<node;i++){
        if(getCost(i,i)<0){
            cout<<"Negative Cycle Exists..."<<endl;
            return;
        }
    }

    cout << endl;

    for (int i = 0; i < node; i++)
    {

        for (int j = 0; j < node; j++)
        {
            cout << "Source : " << i << " | Terminal : " << j << " | Cost : ";
            int cost = getCost(i, j);
            if (cost == INF)
            {
                cout << " INF " << endl;
                ;
            }
            else
            {
                cout << cost << endl;

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

OUTPUT:

Source : 0 | Terminal : 0 | Cost : 0
Path : 0
Source : 0 | Terminal : 1 | Cost : 2
Path : 0 -> 1
Source : 0 | Terminal : 2 | Cost : 3
Path : 0 -> 1 -> 1
Source : 0 | Terminal : 3 | Cost : 9
Path : 0 -> 1 -> 1
Source : 0 | Terminal : 4 | Cost : 6
Path : 0 -> 1 -> 1 -> 1 -> 1
Source : 1 | Terminal : 0 | Cost :  INF
Source : 1 | Terminal : 1 | Cost : 0
Path : 1
Source : 1 | Terminal : 2 | Cost : 1
Path : 1 -> 2
Source : 1 | Terminal : 3 | Cost : 7
Path : 1 -> 3
Source : 1 | Terminal : 4 | Cost : 4
Path : 1 -> 2 -> 2
Source : 2 | Terminal : 0 | Cost :  INF
Source : 2 | Terminal : 1 | Cost :  INF
Source : 2 | Terminal : 2 | Cost : 0
Path : 2
Source : 2 | Terminal : 3 | Cost :  INF
Source : 2 | Terminal : 4 | Cost : 3
Path : 2 -> 4
Source : 3 | Terminal : 0 | Cost :  INF
Source : 3 | Terminal : 1 | Cost :  INF
Source : 3 | Terminal : 2 | Cost :  INF
Source : 3 | Terminal : 3 | Cost : 0
Path : 3
Source : 3 | Terminal : 4 | Cost : 2
Path : 3 -> 4
Source : 4 | Terminal : 0 | Cost :  INF
Source : 4 | Terminal : 1 | Cost :  INF
Source : 4 | Terminal : 2 | Cost :  INF
Source : 4 | Terminal : 3 | Cost :  INF
Source : 4 | Terminal : 4 | Cost : 0
Path : 4*/
