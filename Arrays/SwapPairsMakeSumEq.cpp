class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int asum=0,bsum=0;
        for(int i=0;i<n;i++){
            asum+=a[i];
        }
         for(int i=0;i<m;i++){
            bsum+=b[i];
        }
        if((asum+bsum)%2!=0){
            return -1;
        }
        set<int>s(a,a+n);
        int target=(asum-bsum)/2;
        for(int i=0;i<m;i++){
            if(s.count(b[i]+target)){
                return 1;
            }
        }
        return -1;
    }
};
