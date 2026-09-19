#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cout << "Number of Nodes : ";
    cin >> node;
    cout << "Numer of Edges : ";
    cin >> edge;
    vector<vector<pair<int, int>>> ADJ_List(node);
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ADJ_List[u].push_back({v, w});
        ADJ_List[v].push_back({u, w});
    }

    int src;
    cout << "Source : ";
    cin >> src;
    vector<int> key(node, INT_MAX);
    vector<int> parent(node, -1);
    vector<bool> visited(node, false);
    key[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
        {
            continue;
        }
        visited[u] = true;
        for (int i = 0; i < ADJ_List[u].size(); i++)
        {
            int v = ADJ_List[u][i].first;
            int w = ADJ_List[u][i].second;
            if (!visited[v] && key[v] > w)
            {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Minimum Spanning Tree : " << endl;
    int totalCost = 0;
    for (int i = 0; i < node; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << "->" << i << "\t" << "Cost : " << key[i] << endl;
            totalCost += key[i];
        }
    }
    cout << "Total Cost : " << totalCost << endl;
}

/*Input :
Number of Nodes : 5
Numer of Edges : 6
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 2
Source : 0

Output:
Minimum Spanning Tree :
0->1    Cost : 2
1->2    Cost : 1
4->3    Cost : 2
2->4    Cost : 3
Total Cost : 8*/
