#include<bits/stdc++.h>
using namespace std;
int v[100];
int crossOverSum(int st,int en,int mid)
{
    int leftSum=0;
    int i=mid;
    int sum=0;
    while(i>=st)
    {
        sum+=v[i];
        leftSum=max(leftSum,sum);
        i--;

    }
    int RightSum=0;
    i=mid+1;
    sum=0;
    while(i<=en)
    {
        sum+=v[i];
        RightSum=max(RightSum,sum);
        i++;

    }

    return leftSum+RightSum;


}

int maxSubArraySum(int st,int en)
{
    if(st==en)
    {
        return v[st]; //BaseCase
    }
    else
    {
        int mid=(st+en)/2;
        int left=maxSubArraySum(st,mid);
        int right=maxSubArraySum(mid+1,en);
        int cross=crossOverSum(st,en,mid);
        return max({left,right,cross});
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

    int ans=maxSubArraySum(0,n-1);
    cout<<ans<<endl;


}
