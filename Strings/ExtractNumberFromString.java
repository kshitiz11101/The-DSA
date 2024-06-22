

// User function Template for Java

class Solution {
    long ExtractNumber(String s) {
        // code here
       
        String []arr =s.split("\\s+");
        long largeN=-1;
        
        for(int i=0;i<arr.length;i++){
            if(Character.isDigit(arr[i].charAt(0)) && !arr[i].contains("9")){
                long currN=Long.parseLong(arr[i]);
                if(largeN<currN){
                    largeN=currN;
                }
            }
        }
        return largeN;
    }
}
