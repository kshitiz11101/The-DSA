

// User function Template for Java

class Solution {
    void segregate0and1(int[] arr) {
        // code here
          int n=arr.length;
        int zeroCount=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zeroCount++;
            }
           
        }
        for(int i=0;i<zeroCount;i++){
            arr[i]=0;
        }
        for(int i=zeroCount;i<n;i++){
            arr[i]=1;
        }
    }
}
