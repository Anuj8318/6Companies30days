// 299. Bulls and Cows
// https://leetcode.com/problems/bulls-and-cows/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
      int a =0;
      int b =0;
       map<char,int>count;
      for(int i =0;i<secret.length();i++)
      {
        if(secret[i]==guess[i])
        {
            a++;
        }
        else {
                count[secret[i]]++;
            }
        }
        // Second pass: Calculate cows
        for (int i = 0; i < guess.length(); i++) {
            if (secret[i] != guess[i] && count[guess[i]] > 0) {
                b++;
                count[guess[i]]--;
            }
        }
      string s = to_string(a) + "A" + to_string(b)+ "B";
      return s;
       
    }
};