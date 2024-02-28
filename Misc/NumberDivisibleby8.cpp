class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n=s.size();
        if(n<=3){
            return stoi(s)%8==0?1:-1;
        }
        else{
            return stoi(s.substr(n-3,n))%8==0?1:-1;
        }
    }
};
