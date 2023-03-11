class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         vector<int>ans;
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(nums1[i]);
        }
        for(int i=0; i<nums2.size(); i++){
            ans.push_back(nums2[i]);
        }
        if(ans.size()==1)return ans[0];
        int n=ans.size();
        sort(ans.begin(), ans.end());
        
        if(n%2!=0){
            return ans[(n)/2];
        }
        else{
         
            return double(ans[(n/2)-1]+ans[(n/2)])/2;
        }
    
    }
};