class Solution {
public:
bool f(int ind,int sum,vector<int>&nums,vector<vector<int>>&dp){
    if(sum==0){
        return true;
    }
    if(ind==0){
        return nums[ind]==sum;
    }
    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
    bool notTake=f(ind-1,sum,nums,dp);
    bool take=false;
    if(nums[ind]<=sum){
        take=f(ind-1,sum-nums[ind],nums,dp);
    }

    return dp[ind][sum]=take || notTake;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
    else{
        int k=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return f(n-1,k,nums,dp);
    }
    }
};
