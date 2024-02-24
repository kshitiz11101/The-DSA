class Solution{	
public:

	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	     int n=nums.size();
        
         vector<int>dp1(n,1),dp2(n,1);
       
       for(int i=0;i<n;i++){
           for(int prev=0;prev<i;prev++){
               if(nums[prev]<nums[i] && dp1[i]<1+dp1[prev]){
                   dp1[i]=1+dp1[prev];
               }
           }
       }
     
       
       for(int i=n-1;i>=0;i--){
           for(int prev=n-1;prev>i;prev--){
               if(nums[prev]<nums[i] && dp2[i]<1+dp2[prev]){
                   dp2[i]=1+dp2[prev];
               }
           }
       }
       int maxi=1;
       for(int i=0;i<n;i++){
           maxi=max(maxi,dp1[i]+dp2[i]-1);
       }
       return maxi;
	}
};
