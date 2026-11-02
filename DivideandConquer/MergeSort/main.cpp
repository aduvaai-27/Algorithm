#include<bits/stdc++.h>
using namespace std;
int v[100];
int n;
void merge(int st,int mid,int ed)
{
    int i=st;
    int j=mid+1;
    int temp[n];
    int k=0;
    while(i<=mid && j<=ed)
    {
        if(v[i]<v[j])
        {
            temp[k]=v[i];
            i++;
            k++;
        }
        else
        {
            temp[k++]=v[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=v[i++];
    }
    while(j<=ed)
    {
        temp[k++]=v[j++];
    }

    for(int i=st,j=0; i<=ed; i++,j++)
    {
        v[i]=temp[j];
    }

}

void mergeSort(int st,int ed)
{
    int mid=(st+ed)/2;
    if(st>=ed) return;
    mergeSort(st,mid);
    mergeSort(mid+1,ed);
    merge(st,mid,ed);



}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    mergeSort(0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }

}



