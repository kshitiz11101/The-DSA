class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        /*
    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            int third = -(arr[i] + arr[j]);
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    */
        int n=arr.size();
    sort(arr.begin(), arr.end());
    set<vector<int>> st;
    vector<int>temp;
    int sum=0;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                sum=arr[i]+arr[j]+arr[k];
                if(sum==0){
                   temp={arr[i],arr[j],arr[k]};
                   sort(temp.begin(),temp.end());
                   st.insert(temp);
                }
                if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    }
};
