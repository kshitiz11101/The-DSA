
class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
       int lb=lower_bound(arr,arr+n,k)-arr;
       if(arr[lb]==k){
           return arr[lb];
       }
       if(lb>0){
           if(k-arr[lb-1]<arr[lb]-k){
               return arr[lb-1];
           }
           else{
               return arr[lb];
           }
           
           
       }
       return arr[lb];
       
    } 
};
