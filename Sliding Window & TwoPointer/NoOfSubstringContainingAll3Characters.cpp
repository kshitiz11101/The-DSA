class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>lastseen(3,-1);
        int cnt=0,n=s.size();
        for(int i=0;i<n;i++){
            lastseen[s[i]-'a']=i;
            if( lastseen[0]!=-1 &&  lastseen[1]!=-1 &&  lastseen[2]!=-1){
                cnt=cnt+(1+min(lastseen[0],min( lastseen[1], lastseen[2])));
            } 
        }
    return cnt;
    }
};
