class Solution{
public:
    int fib(int N){
        //code here
        vector<int>dp(N+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=N;i++){
            dp[i]=(dp[i-1]+dp[i-2])%10;
        }
        return dp[N];
    }
};
