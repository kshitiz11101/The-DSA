class Solution {
public:
    int maxDepth(string s) {
        int maxi=INT_MIN,c=0;
        for(auto ch:s){
            if(ch=='('){
                c++;
            }
            else if(ch==')'){
                c--;
            }
            maxi=max(maxi,c);
        }
    return maxi;
    }
};
