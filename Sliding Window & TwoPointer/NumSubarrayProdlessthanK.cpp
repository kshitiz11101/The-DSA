class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int ans=0,l=0,r=0,n=nums.size();
        int prod=1;
        while(r<n){
            prod=prod*nums[r];
            while(prod>=k){
                prod/=nums[l];
                l++;
            }
                ans+=r-l+1;
                r++;
        }
        return ans;
    }
};
