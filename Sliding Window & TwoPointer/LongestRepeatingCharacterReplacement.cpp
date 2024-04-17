class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxf=0,maxlen=0,n=s.size();
        unordered_map<char,int>m;
        while(r<n){
            m[s[r]-'A']++;
            maxf=max(maxf,m[s[r]-'A']);
            if((r-l+1)-maxf>k){
                m[s[l]-'A']--;
                maxf=0;
                l++;
            }
            if((r-l+1)-maxf<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
