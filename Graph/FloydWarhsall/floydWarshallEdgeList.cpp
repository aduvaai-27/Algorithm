#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int N = 500;
int node, edge;
class EDGE
{
public:
    int u;
    int v;
    int w;
};
vector<EDGE> graph;

int getCost(int u, int v)
{
    int best = INF;

    for (int i = 0; i < edge; i++)
    {
        if (graph[i].u == u && graph[i].v == v)
        {
            best = min(graph[i].w, best);
        }
    }
    return best;
}

void setCost(int u, int v, int w)
{
    for (int i = 0; i < edge; i++)
    {
        if (graph[i].u == u && graph[i].v == v)
        {
            graph[i].w = w;
            return;
        }
    }

    graph.push_back({u, v, w});
    edge++;
    return;
}

int main()
{
    cin >> node >> edge;
    vector<vector<vector<int>>> path(
        node,
        vector<vector<int>>(node));
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
        path[u][v] = {u, v};
    }

    for (int i = 0; i < node; i++)
    {
        path[i][i] = {i};
        setCost(i,i,0);
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
                    if (ik + kj < getCost(i, j))
                    {
                        int w = ik + kj;
                        setCost(i, j, w);
                        path[i][j] = path[i][k];
                        for (int p = 1; p < path[k][j].size(); p++)
                        {
                            path[i][j].push_back(path[k][j][p]);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < node; i++)
        {
            if (getCost(i, i) < 0)
            {
                cout << "Negative Cycle Detected...";
                return -1;
            }
        }
    }

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {

            cout << "Source : " << i << " | Terminal : " << j << " | Cost : ";
            int w = getCost(i, j);
            if (w == INF)
            {
                cout << "INF" << endl;
                continue;
            }
            else
            {
                cout << w << endl;
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

/*INPUT 1:
4 5
0 1 1
1 2 -3
2 3 1
3 1 1
0 3 10
OUTPUT:
Negative Cycle Detected...


INPUT 2 :
5 6
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
Path : 4
*/