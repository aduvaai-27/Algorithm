#include<bits/stdc++.h>
using namespace std;
int cross_sum(vector<int>&v,int st,int end,int mid)
{
    int left=INT_MIN;
    int leftSum=0;
    int posl=mid;
    while(posl>=st){
        leftSum+=v[posl];
        left=max(left,leftSum);
        posl--;
    }

    int right=INT_MIN;
    int rightSum=0;
    int posr=mid+1;
    while(posr<=end){
        rightSum+=v[posr];
        right=max(right,rightSum);
        posr++;
    }
    return left+right;
}

int Max_SubArray(vector<int>&v,int st,int end){
    if(st==end) return v[st];
    int mid=(st+end)/2;
    int lss=Max_SubArray(v,st,mid);
    int rss=Max_SubArray(v,mid+1,end);
    int css=cross_sum(v,st,end,mid);
    return max({lss,rss,css});

}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans=Max_SubArray(v,0,n-1);
    cout<<ans<<endl;
    return 0;
}
