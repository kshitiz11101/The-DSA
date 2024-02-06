class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<int> s;
        for(int i=0;i<N;i++){
            if(!s.empty() && color[i]==color[s.top()] && radius[i]==radius[s.top()]){
                s.pop();
            }
            else{
                s.push(i);
            }
        }
        return s.size();
    }
};
