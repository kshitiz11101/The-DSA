
class Solution{
bool Search(int N, vector<int>& A, int Key) {
        // Code here
          int s=0,e=N-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(A[mid]==Key){
                return true;
            }
            if(A[s]==A[mid] && A[e]==A[mid]){
                s++;
                e--;
            }
             if(A[s]<=A[mid]){
                if(Key>=A[s] && Key<=A[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(Key>=A[mid] && Key<=A[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return false;
    }
};