// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        int count=0;
        int n=arr.size();
        /*
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
        */
        unordered_map<int,int>m;
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            if(currSum==k){
                count++;
            }
            if(m.find(currSum-k)!=m.end()){
                count+=m[currSum-k];
            }
            m[currSum]++;
        }
        return count;
    }
};
