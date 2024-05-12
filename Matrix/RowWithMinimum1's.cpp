class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
          int maxi=INT_MAX;
       int cnt;
       int flag;
       for(int i=0;i<n;i++){
           cnt=0;
           for(int j=0;j<m;j++){
               if(a[i][j]==1){
                   cnt++;
               }
           }
           if(cnt<maxi){
               maxi=cnt;
               flag=i+1;
           }
       }
       return flag;
    }
};
