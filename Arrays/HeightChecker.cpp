class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>exp(heights);
        sort(exp.begin(),exp.end());
        int count=0;
        for(int i=0;i<heights.size();i++){
                if(heights[i] != exp[i]){
                    count++;
                }
        }
        return count;
    }
};
