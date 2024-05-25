class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int xorans=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second==2){
            xorans^=i.first;    
            }
            }
        return xorans;
    }
};
