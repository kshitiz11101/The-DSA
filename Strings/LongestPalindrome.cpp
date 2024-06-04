class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        bool oddFreq=false;
        int ans=0;
        for(auto j:m){
            int freq=j.second;
            if(freq%2==0){
                ans+=freq;
            }
            else{
                ans+=freq-1;
                oddFreq=true;
            }
        }
        if(oddFreq){
            return ans+1;
        }

        return ans;
    }
};
