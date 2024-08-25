class Solution {
  public:
  int f(int val,vector<int>&brr){
      int s=0,e=brr.size()-1,index=-1;
      while(s<=e){
          int mid=s+(e-s)/2;
          if(brr[mid]<=val){
              index=mid;
              s=mid+1;
          }
          else{
              e=mid-1;
          }
      }
      return index;
  }
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        long long ans=0;
        sort(brr.begin(),brr.end());
        int one=0,two=0,threeFour=0;
        int n=brr.size();
        for(auto i:brr){
            if(i==1){
                one++;
            }
            else if(i==2)
            two++;
            else if(i==3 || i==4){
                threeFour++;
            }
        }
        for(auto i:arr){
            if(i!=1){
                ans+=one;
                if(i==2) ans-=threeFour;
                if(i==3) ans+=two;
                int index=f(i,brr);
                ans+=n-index-1;
            }
        }
        return ans;
    }
};
