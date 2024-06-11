class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        vector<int>rem;
        unordered_map<int,int>m;
        for(int i=0;i<arr2.size();i++){
            m[arr2[i]]=0;
        }
        for(int i=0;i<arr1.size();i++){
            if(m.find(arr1[i])!=m.end()){
                m[arr1[i]]++;
            }
            else{
                rem.push_back(arr1[i]);
            }
        }
        sort(rem.begin(),rem.end());
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<m[arr2[i]];j++){
                ans.push_back(arr2[i]);
            }
       
        }
          for(int i=0;i<rem.size();i++){
            ans.push_back(rem[i]);
         }
        return ans;
    }
};
