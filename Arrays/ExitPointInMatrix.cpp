class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        // vector<int>ans;
        int i=0,j=0,dir=1;
        while(i>=0 && i<n && j>=0 && j<m){
            if(matrix[i][j]==1){
                matrix[i][j]=0;
                dir=(dir%2)+1;
            }
            if(dir==1){
                j++;
            }
            else if(dir==2){
                i++;
            }
            else if(dir==3){
                j--;
                }
                else{
                    i--;
                }
        }
        if(dir==1){
            j--;
        }
        else if(dir==2){
            i--;
        }
        else if(dir==3){
            j++;
        }
        else{
            i++;
        }
        return {i,j};
        
    }
};
