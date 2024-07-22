class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // vector<string>ans;
        // sort(heights.begin(),heights.end(),greater<int>());
        // for(int i=0;i<names.size();i++){
        //     ans.push_back(names[i]);
        // }
        // return ans;
        int n=names.size();
        vector<pair<int,string>>ans(n);
        for(int i=0;i<n;i++){
            ans[i]={heights[i],names[i]};
        }
        sort(ans.begin(),ans.end(),greater<>());
        for(int i=0;i<n;i++){
            names[i]=ans[i].second;
        }
        return names;

    }
};
