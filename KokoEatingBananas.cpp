class solution{
public:
bool solveKoko(vector<int> &piles,int H,int mid){
int hours=0;
  for(auto i:piles){
          int d=i/mid;
          hours+=d;
          if(i%mid!=0){
              hours++;
          }
      }
      if(hours<=H){
          return true;
      }
      else{
          return false;
      }
}
int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int s=1,e=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(solveKoko(piles,H,mid)){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};