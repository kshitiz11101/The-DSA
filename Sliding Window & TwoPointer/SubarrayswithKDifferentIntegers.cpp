class Solution {
public:
int f(vector<int>&nums,int k){
            map<int, int>m;
        int l = 0,ans= 0,n=nums.size();
        for (int r = 0; r < n; r++) {
            m[nums[r]]++;
            while (m.size() > k) {
                m[nums[l]]--;
                if (m[nums[l]] == 0) 
                    m.erase(nums[l]);
                l++;
            }
            ans += (r-l+ 1);
        }
        return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return f(nums,k)-f(nums,k-1);
    }
};
