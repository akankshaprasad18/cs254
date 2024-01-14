#include <iostream>
using namespace std;

int knapsack(int W,int wt[],int val[],int n){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }for(int j=0;j<=W;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n=5;
    int W=10;
 int val[] = {10,20,15,7,5};
 int wt[]={2,5,7,3,1};
	
 cout<<knapsack(W,wt,val,n)<<endl;
	
 return 0;
}