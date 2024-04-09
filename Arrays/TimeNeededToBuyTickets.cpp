class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        int n=tickets.size();
        if(tickets[k]==0)
        return 0;
        for(int i=0;i<n;i++){
            if(i<=k)
            ans+=min(tickets[k],tickets[i]);
            else
            ans+=min(tickets[k]-1,tickets[i]);
        }
        return ans;
    }
};
