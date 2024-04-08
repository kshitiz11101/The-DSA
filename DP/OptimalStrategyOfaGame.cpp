class Solution{
    public:
    long long f(int left,int right,int n,int arr[], vector<vector<int>>&dp){
        if(left>right)
        return 0;
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        long long takeleft=min(f(left+2,right,n,arr,dp),f(left+1,right-1,n,arr,dp))+arr[left];
        long long takeright=min(f(left,right-2,n,arr,dp),f(left+1,right-1,n,arr,dp))+arr[right];
        return dp[left][right]=max(takeleft,takeright);
        
        
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,n-1,n,arr,dp);
    }
};
