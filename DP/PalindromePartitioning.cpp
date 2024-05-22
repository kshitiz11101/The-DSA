class Solution {
    private:
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void f(int i,string &s,vector<string>&v,vector<vector<string>>&ans){
        int n=s.length();
        if(i==n){
            ans.push_back(v);
            return;
        }
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                string k=s.substr(i,j-i+1);
                v.push_back(k);
                f(j+1,s,v,ans);
                v.pop_back();
            }
        }

    }
public:

    vector<vector<string>> partition(string s) {
       vector<vector<string>>ans;
       vector<string>v;
       f(0,s,v,ans);
       return ans;
    }
};
