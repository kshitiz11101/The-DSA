class Solution {
public:
    int maxScore(string s) {
        int score=0,n=s.size();
        for(int i=0;i<n-1;i++){
            int curr=0;
            for(int j=0;j<=i;j++){
                if(s[j]=='0'){
                    curr++;
                }
            }
            for(int j=i+1;j<n;j++){
                if(s[j]=='1'){
                    curr++;
                }
            }
            score=max(score,curr);
        }
        return score;
    }
};
