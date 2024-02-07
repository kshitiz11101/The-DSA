class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int f(int *arr,int n){
	     int prev1=arr[0];
   int prev2=0;
   for(int i=1;i<n;i++){
       int take=arr[i];
       if(i>1){
           take+=prev2;
       }
       int notTake=0+prev1;

       int curr=max(take,notTake);
       prev2=prev1;
       prev1=curr;
   }

return prev1;
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    return f(arr,n);
	}
};
