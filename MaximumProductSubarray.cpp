class Solution {
public:
int fun(int mid, vector<int>& nums){
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += (nums[i]/mid) + ((nums[i] % mid) != 0);
        }
        
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
         int lo = 1, hi = 1e9, ans = 0;
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(fun(mid, nums) <= threshold){
                ans = mid;
                hi = mid - 1;  
            }
            else{
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};