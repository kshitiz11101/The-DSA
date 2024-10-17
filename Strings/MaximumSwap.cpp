class Solution {
public:
    int maximumSwap(int num) {
      string numString=to_string(num);
      int n=numString.size();
      int maxNum=num;
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(numString[i],numString[j]);
            int newNum=stoi(numString);
            maxNum=max(maxNum,newNum);
              swap(numString[i],numString[j]);
        }
      }  
      return maxNum;
    }
};
