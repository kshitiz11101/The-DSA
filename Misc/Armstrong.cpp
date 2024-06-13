class Solution {
  public:
    string armstrongNumber(int n){
        // code here
       int sum=0;
       int x=n;
        while(n>0){
            int digit=n%10;
            n=n/10;
            sum+=pow(digit,3);
        }
        if(sum==x){
            return "Yes";
        }
       else{
           return "No";
       }
        
    }
};
