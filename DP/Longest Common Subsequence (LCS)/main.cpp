#include<bits/stdc++.h>
using namespace std;
int main()
{
    string string1,string2;
    cin>>string1>>string2;
    int n=string1.size();
    int m=string2.size();
    int L[n+1][m+1];
    for(int i=0; i<=n; i++)
    {
        L[i][0]=0;
    }
    for(int i=0; i<=m; i++)
    {
        L[0][i]=0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(string1[i-1]==string2[j-1])
            {
                L[i][j]=L[i-1][j-1]+1;
            }
            else
            {
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
        }
    }

    string subsequence="";
    int i=n;
    int j=m;
    while(i>0 && j>0)
    {
        if(string1[i-1]==string2[j-1])
        {
            subsequence+=string1[i-1];
            i--;
            j--;
        }
        else if( L[i-1][j]>L[i][j-1] )
        {
            i--;

        }
        else
        {
            j--;
        }
    }

    cout<<L[n][m]<<endl;
    reverse(subsequence.begin(),subsequence.end());
    cout<<subsequence<<endl;


}


