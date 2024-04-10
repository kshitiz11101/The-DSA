class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(),deck.end());
        deque<int>dq;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            dq.push_back(i);
        }
        int reveal=0,flip=0;
        while(!dq.empty()){
            if(flip==0){
              ans[dq.front()]=deck[reveal];
              reveal++;
              dq.pop_front();
            }
            else{
                dq.push_back(dq.front());
                dq.pop_front();
            }
            flip^=1;
        }
        return ans;
    }
};
