// 187.Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       map<string,int>mp;
       int start = 0;
       int end = 0;
        string str;
        vector<string>ans;
        if (s.length() < 10) return ans; 
        
        for (int i = 0; i <= s.length() - 10; i++) {
            string str = s.substr(i, 10); 
            mp[str]++;
        }
        for(auto it:mp){
         if(it.second>1)
         {
            ans.push_back(it.first);
         }
        }
        return ans;
    }
};

