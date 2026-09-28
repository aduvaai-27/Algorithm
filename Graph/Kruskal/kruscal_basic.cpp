#include<bits/stdc++.h>
using namespace std;
int parent[100],rank1[100];
class EDGE
{
public:
    int u,v,w;
    EDGE(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator<(const EDGE& e)
    {
        return w<e.w;
    }
};

int find(int x)
{
    if(x==parent[x])
    {
        return x;
    }
    return parent[x]=find(parent[x]);
}

void Union(int a,int b)
{
    int parA=find(a);
    int parB=find(b);
    if(parA==parB)
    {
        return ;
    }
    else if(rank1[parA]==rank1[parB])
    {
        parent[parB]=parA;
        rank1[parA]++;
    }
    else if(rank1[parA]>rank1[parB])
    {
        parent[parB]=parA;
    }
    else if(rank1[parA]<rank1[parB])
    {
        parent[parA]=parB;
    }

}

int main()
{
    srand(time(0));
    int cnt=0;
    int node;
    cin>>node;
    vector<EDGE>edges;
    for(int i=0; i<node; i++)
    {
        for(int j=i+1; j<node; j++)
        {
            edges.push_back(EDGE(i,j,rand()%10+1));
        }
        cnt++;


    }

    sort(edges.begin(),edges.end());

    for(int i=0; i<node; i++)
    {
        parent[i]=i;
        rank1[i]=0;
    }
    double mstCost=0;
    vector<EDGE>tree;
    for(int i=0; i<edges.size(); i++)
    {

        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;
        if(find(u)!=find(v))
        {
            Union(u,v);
            mstCost+=w;
            tree.push_back(edges[i]);
        }

    }
    cout<<"MST COST : "<<mstCost<<endl;
    cout<<"Minimum Spanning Tree : "<<endl;
    for(int i=0;i<tree.size();i++){
        cout<<tree[i].u<<" - "<<tree[i].v<<" : "<<tree[i].w<<endl;
    }
}
