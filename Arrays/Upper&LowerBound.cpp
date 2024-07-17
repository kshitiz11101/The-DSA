



int lower(int arr[], int n, int x){
    sort(arr,arr+n);
        int s=0,e=n-1;
        int index=-1;
        if(x<arr[0]){
            return -1;
        }
        while(s<=e){
            int mid=s+(e-s)/2;
          
            if(arr[mid]<=x){
                index=arr[mid];
                s=mid+1;
            }
          
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
            
        }
        return index;
}
int upper(int arr[], int n, int x){
    sort(arr,arr+n);
     int s=0,e=n-1;
        int index=-1;
        if(x>arr[n-1]){
            return -1;
        }
        while(s<=e){
            int mid=s+(e-s)/2;
          
            if(arr[mid]>=x){
                index=arr[mid];
                e=mid-1;
            }
           
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
            
        }
        return index;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    
    pair<int,int>ans;
    int fl=lower(arr,n,x);
    int cl=upper(arr,n,x);
    
   ans.first=fl;
   ans.second=cl;
    return ans;
    
}
