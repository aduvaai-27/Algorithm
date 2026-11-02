#include<bits/stdc++.h>
using namespace std;
int main(){
int no_of_coin;
int target;
cin>>no_of_coin;
int coins[no_of_coin];
for(int i=0;i<no_of_coin;i++){
    cin>>coins[i];
}
cin>>target;
int dp[target+1];
for(int i=1;i<=target;i++){
    dp[i]=target+1; //setting max
}
dp[0]=0;
for(int i=1;i<=target;i++){
    for(int j=0;j<no_of_coin;j++){
            if(i>=coins[j]){
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }

    }
}

if(dp[target]==target+1){
    cout<<"-1"<<endl;
}
else{
    cout<<dp[target]<<endl;
}


}
