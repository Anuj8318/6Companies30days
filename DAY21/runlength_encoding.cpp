// Run Length Encoding
// https://www.geeksforgeeks.org/problems/run-length-encoding/1

class Solution {
  public:
    string encode(string s) {
        // code here
        int st =0;
        int e=0;
        string ans="";
        while(e<s.length())
        {
            int count =0;
            while(e<s.length() &&s[e]==s[st] )
            {
                count++;
                e++;
            }
            ans+= s[st] + to_string(count);
        
            st = e;
            
        }
        return ans;
    }
};