class Solution {
public:
void f(vector<int>& nums,vector<vector<int>>&ans,int ind,int n, vector<int>&temp){
    ans.push_back(temp);
    for(int i=ind;i<n;i++){
        temp.push_back(nums[i]);
        f(nums,ans,i+1,n,temp);
        temp.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        f(nums,ans,0,n,temp);
        return ans;
    }
};
