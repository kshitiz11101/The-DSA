class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        // code here
        
        double len=(double)(perimeter-sqrt(perimeter*perimeter-24*area))/12;
        double height=(perimeter/4)-(2*len);
        double vol=len*len*height;
        return vol;
        
    }
};
