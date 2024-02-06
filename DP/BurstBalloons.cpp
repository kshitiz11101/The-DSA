class Solution {
public:
/*
int f(int i,int j,vector<int> &arr, vector<vector<int>>dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini=INT_MIN;
    for(int ind=i;ind<=j;ind++){
        int cost=arr[i-1]*arr[ind]*arr[j+1]+ f(i,ind-1,arr,dp)+f(ind+1,j,arr,dp);
        mini=max(mini,cost);
        
    }
    return dp[i][j]=mini;
    
}
*/
    int maxCoins(vector<int>& nums) {
        int N=nums.size();
         nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(N+2,vector<int>(N+2,0));
        for(int i=N;i>=1;i--){
            
            for(int j=1;j<=N;j++){
                if(i>j){
                continue;
            }
                int mini=INT_MIN;
    for(int ind=i;ind<=j;ind++){
        int cost=nums[i-1]*nums[ind]*nums[j+1]+ dp[i][ind-1]+dp[ind+1][j];
        mini=max(mini,cost);
        
    }
     dp[i][j]=mini;
            }
        }
        return dp[1][N];
    }
};
