#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int T;
    char S[1000];
    cout << "Enter the no. of test cases" << endl;
    cin >> T;
    cout<<"Enter the string S"<<endl;
    cin.getline(S,1000);

    char r[1000] = S.substr(1000, 3);

    while (T--)
    {
        int len = r.length();
        if (len > 2)
        {
            cout << "HAppy" << endl;
        }
        else
        {
            cout << "Sad" << endl;
        }
    }
    return 0;
}
