class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        // while(s<e){
            
        // }
        // sort(a.begin(),a.end());
        // return a[n-1];
        
        int n=a.size(),peak=0;
       for(int i=0;i<n;i++){
           if(peak<a[i]){
               peak=a[i];
           }
       }
       return peak;
    }
};
