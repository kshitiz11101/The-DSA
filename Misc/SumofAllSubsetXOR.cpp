class Solution {
public:
int f(vector<int>&nums,int ind,int curr){
    if(ind==nums.size()){
        return curr;
    }
    int withele=f(nums,ind+1,curr^nums[ind]);
    int withoutele=f(nums,ind+1,curr);
    return withele+withoutele;
}
    int subsetXORSum(vector<int>& nums) {
        return f(nums,0,0);
    }
};
