#include<bits/stdc++.h>
using namespace std;
int v[100];

int partion(int st,int en)
{
    int pivot=v[st];
    int i=st;
    int j=en;
    while(i<=j)
    {
        while(i<=en && v[i]<=pivot)
        {
            i++;
        }

        while(v[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(v[i],v[j]);
        }




    }

    swap(v[st],v[j]);
    return j;

}

void quickSort(int st,int en)
{
    if(en>st)
    {
        int p=partion(st,en);
        quickSort(st,p-1);
        quickSort(p+1,en);


    }

}




int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    quickSort(0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;


}
