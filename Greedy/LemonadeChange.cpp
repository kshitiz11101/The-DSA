class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // sort(bills.begin(),bills.end());
        int n=bills.size();
        int change5=0,change10=0;
        for(int i=0;i<n;i++){
                if(bills[i]==5){
                    change5++;
                }
                else if(bills[i]==10){
                  
                    change5--;
                    change10++;
                }
                else if(change10>0){
                    change10--;
                    change5--;
                }
                else{
                    change5-=3;
                }

                if(change5<0 ){
                    return false;
                }
        }
        return true;
    }
};
