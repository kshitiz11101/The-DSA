class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
      int i=0,j=0;
      while(i<n && j<n){
          
          if(arr1[i]==arr2[j]){
              i++;
              j++;
          }
          else{
              return i;
          }
      }
        
    }
};
