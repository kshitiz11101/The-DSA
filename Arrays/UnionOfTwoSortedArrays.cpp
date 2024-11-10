class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        int n=a.size(),m=b.size();
        int i=0,j=0;
        vector<int>ans;
        while(i<n && j<m){
            if(a[i]<b[j]){
                ans.push_back(a[i]);
                i++;
            }
            else if(a[i]>b[j]){
                ans.push_back(b[j]);
                j++;
            }
            else{
                ans.push_back(b[j]);
                i++;
                j++;
            }
           
        }
        while(i<n){
            ans.push_back(a[i]);
            i++;
        }
        while(j<m){
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};
