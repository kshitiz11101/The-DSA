#include <iostream>
#include <bits/stdc++.h>
#include<vector>
 bool knows(vector<vector<int>>&M,int a,int b,int n){
        if(M[a][b]==1){
            return true;
        }
        else{
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        // Step-1: push all elements in stack
        for(int i=0;i<n;i++){
            s.push(i);
        }
        // Step-2:
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int candidate=s.top();
        // Step-3: single element in stack is "Potential Celebrity"
        // so verify it.
        bool rowCheck=false;
        int ZeroCount=0;
        for(int i=0;i<n;i++){
            if(M[candidate][i]==0){
                ZeroCount++;
            }
        }
        // all zeroes
        if(ZeroCount==n){
            rowCheck=true;
            }
            
           bool colCheck=false;
           int OneCount=0;
            for(int i=0;i<n;i++){
            if(M[i][candidate]==1){
                OneCount++;
            }
        }
        if(OneCount==n-1){
            colCheck=true;
        }
        if(rowCheck==true && colCheck==true){
            return candidate;
        }
        else{
            return -1;
        }
        }