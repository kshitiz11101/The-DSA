// User function template for C++
class Solution {
  public:
    vector<int>f(vector<int> &arr){
         vector<int>pos,neg;
        for(auto a:arr){
            if(a>=0){
                pos.push_back(a);
            }
            else{
                neg.push_back(a);
            }
        }
        int n=arr.size();
        int p=pos.size();
        int m=neg.size();
        vector<int>ans;
        int posi=0,negi=0;
        for(int i=0;i<n;i++){
            if(posi<p){
                ans.push_back(pos[posi]);
                posi++;
            }
            if(negi<m){
                ans.push_back(neg[negi]);
                negi++;
            }
        }
        return ans;
        
    }
    void rearrange(vector<int> &arr) {
        // code here
       arr=f(arr);
        
    }
};
