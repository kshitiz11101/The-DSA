class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // BRUTE FORCE
        /*
        int maxlen=0,n=nums.size();
        for(int i=0;i<n;i++){
            int zeroes=0;
            for(int j=i;j<n;j++){
                if(nums[j]==0){
                    zeroes++;
                }
                if(zeroes<=k){
                    int len=j-i+1;
                    maxlen=max(maxlen,len);
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
        */

        /* TC=O(2N)

        int n=nums.size(),l=0,r=0,zeros=0,maxlen=0;
        while(r<n){
            if(nums[r]==0){
                zeros++;

            }
            while(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                    l++;

            }
            if(zeros<=k){
               int len=r-l+1;
               maxlen=max(maxlen,len);
            }
            r++;
        }
        return maxlen;
        */
         int n=nums.size(),l=0,r=0,zeros=0,maxlen=0;
        while(r<n){
            if(nums[r]==0){
                zeros++;
            }
            if(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                    l++;
            }
            if(zeros<=k){
               int len=r-l+1;
               maxlen=max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};
