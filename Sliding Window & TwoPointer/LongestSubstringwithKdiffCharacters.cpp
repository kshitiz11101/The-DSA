#include<bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    // Write your code here
    unordered_map<char,int>m;
    int l=0,r=0,n=str.size(),maxlen=0;
    while(r<n){
        m[str[r]]++;
        if(m.size()>k){
            m[str[l]]--;
            if(m[str[l]]==0){
                m.erase(str[l]);
            }
            l++;
        }
        if(m.size()<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}


