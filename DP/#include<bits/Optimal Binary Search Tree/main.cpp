#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double p[n];
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    double PS[n];
    PS[0]=p[0];
    for(int i=1; i<n; i++)
    {
        PS[i]=PS[i-1]+p[i];
    }
    double C[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        C[i][i-1]=0;
    }
    int root[n+1][n+1];
    for(int len=1; len<=n; len++)
    {
        for(int i=0; i+len-1<n; i++)
        {
            int j=i+len-1;
            double w=PS[j];
            if(i>0)
            {
                w-=PS[i-1];
            }

            C[i][j]=INT_MAX;
            for(int r=i; r<=j; r++)
            {
                double cost=C[i][r-1] + C[r+1][j] + w;
                if(cost<C[i][j])
                {
                    C[i][j]=cost;
                    root[i][j]=r;
                }


            }
        }
    }

    cout<<"Minimum Cost: "<<C[0][n-1]<<endl;
    cout<<"Root : "<<root[0][n-1]<<endl;



}
