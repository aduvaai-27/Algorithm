#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    int profit[n+1];
    for(int i=1; i<=n; i++) cin>>profit[i];

    int dp[n+1];
    dp[0]=0 ; //length 0 = No cutting = 0 Profit - Base Case
    for(int len=1; len<=n; len++)
    {
        dp[len]=0;
        for(int i=1; i<=len; i++)
        {
            dp[len]=max(dp[len],profit[i]+dp[len-i]);
        }
    }

    cout<<"Maximum Profit : "<<dp[n]<<endl;

}
