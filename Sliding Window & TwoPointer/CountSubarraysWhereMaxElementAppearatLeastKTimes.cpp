class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxlen=0;
        int l=0,r=0,n=nums.size();
        int maxele=*max_element(nums.begin(),nums.end());
        while(r<n){
            if(nums[r]==maxele){
                k--;
            }
            while(!k){
                if(nums[l]==maxele){
                    k++;
                }
                l++;
            }
            maxlen+=l;
            r++;
        }
        return maxlen;
    }
};
