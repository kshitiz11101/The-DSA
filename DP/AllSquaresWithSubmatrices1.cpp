class Solution {
  public:
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        // code here
        vector<vector<int>>dp(N,vector<int>(M,0));
        for(int j=0;j<M;j++){
            dp[0][j]=matrix[0][j];
            
        }
         for(int i=0;i<N;i++){
            dp[i][0]=matrix[i][0];
            
        }
        for(int i=1;i<N;i++){
              for(int j=1;j<M;j++){
            if(matrix[i][j]==0){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            }
        }
        }
      int sum=0;
      for(int i=0;i<N;i++){
          for(int j=0;j<M;j++){
              sum+=dp[i][j];
          }
      }
        return sum;
    }
};
