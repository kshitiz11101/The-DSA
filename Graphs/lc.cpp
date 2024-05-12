#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
      vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        // code here
        int m = edges.size();
        sort(disappear.begin(), disappear.end());
        long long int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1];
            if (dp[u] == -1 || dp[v] == -1 || dp[u] > dp[v])
                dp[u] = dp[v] + 1;
            else
                dp[v] = dp[u] + 1;
        }
        
        vector<int> res(n);
        for (int i = 1; i <= n; ++i) {
            res[i - 1] = dp[i];
        }
        return res;

       
    }
};