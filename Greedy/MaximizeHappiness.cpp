// #include<bits/stdc++.h>
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum=0;
        int n=happiness.size();
        int turns=0;
        sort(happiness.begin(),happiness.end(),greater<int>());
        // sum=happiness[0];
        // int maxi=INT_MIN;
        for(int i=0;i<k;i++){
          sum+=max(happiness[i]-turns,0);
           turns++;
        }
        return sum;
    }
};
