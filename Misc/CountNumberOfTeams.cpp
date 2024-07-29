class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int teams=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int k=j;k<n;k++){
                    if(rating[i]<rating[j] && rating[j]<rating[k] && rating[i]<rating[k]){
                        teams++;
                    }
                    else if(rating[i]>rating[j] && rating[j]>rating[k] && rating[i]>rating[k]){
                        teams++;
                    }
                }
            }
        }
        return teams;
    }
};
