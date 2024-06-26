class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int coverage=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int delrow[]={0,-1,0,1};
        int delcol[]={-1,0,1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                   for(int k=0;k<4;k++){
                       int nrow=i+delrow[k];
                       int ncol=j+delcol[k];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && matrix[nrow][ncol]==1){
                    coverage++;
                }   
                   }
                }
            }
        }
        return coverage;
    }
};
