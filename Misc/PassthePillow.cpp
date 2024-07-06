class Solution {
public:
    int passThePillow(int n, int time) {
       
        int direcn=1,ind=1;
        int currentTime=0;
      while(currentTime<time){
        if(ind+direcn>0 && ind+direcn<=n){
            ind+=direcn;
            currentTime++;
        }
        else{
            direcn*=-1;
        }
      }
        return ind;
    }
};
