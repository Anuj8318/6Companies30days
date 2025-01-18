// 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/


#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin(),g.end());
      sort(s.begin(),s.end());
      int cookies =0;
      int child =0;
      while(child<g.size() && cookies< s.size())
      {
        if(g[child]<=s[cookies])
        {
            child++;
        }
        cookies++;
      }
      return child;
    }
};
