class Solution {
public:
    void sortColors(vector<int>& nums) {
        int wcount=0,rcount=0,bcount=0;
        int n=nums.size();
        for(int i:nums){
            if(i==0){
                rcount++;
            }
            else if(i==1){
                wcount++;
            }
        }
        for(int i=0;i<rcount;i++){
            nums[i]=0;
        }

         for(int i=rcount;i<rcount+wcount;i++){
            nums[i]=1;
        }

        for(int i=rcount+wcount;i<n;i++){
            nums[i]=2;
        }

    }
};
