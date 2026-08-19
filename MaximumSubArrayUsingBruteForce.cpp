#include<bits/stdc++.h>
using namespace std;
int MaxSubArraySum(vector<int>&v){
    int maxSum=INT_MIN;
    for(int i=0;i<v.size()-1;i++){
        int sum=0;
        for(int j=i;j<v.size()-1;j++){
            sum+=v[j];
            maxSum=max(maxSum,sum);
        }
    }
    return maxSum;


}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<MaxSubArraySum(v)<<endl;

}
//9
//-2 1 -3 4 -1 2 1 -5 4