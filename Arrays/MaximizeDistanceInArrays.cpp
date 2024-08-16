class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int mini=arrays[0][0];
        int maxi=arrays[0].back();
        int diff=0;
        int n=arrays.size();
        for(int i=1;i<n;i++){
            diff=max(diff,abs(arrays[i].back()-mini));
            diff=max(diff,abs(maxi-arrays[i][0]));
            mini=min(mini,arrays[i][0]);
            maxi=max(maxi,arrays[i].back());
        }
        return diff;
    }
};
