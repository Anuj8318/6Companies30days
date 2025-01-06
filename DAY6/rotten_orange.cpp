// 994. Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int countmin =0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>ans(n,vector<int>(m,0));
        int countFresh =0;
        for(int i =0;i<grid.size();i++)
        {
            for(int j =0;j<grid[0].size();j++)
            {
              
              if(grid[i][j]==1)
              {
                countFresh++;
              }
              if(grid[i][j]==2)
              {
                q.push({{i,j},0});
                ans[i][j]=2;
              }
            }
        }
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            for(int i =0;i<4;i++)
            {
              int nrow = delrow[i]+row;
              int ncol = delcol[i]+col;
              if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==0 && grid[nrow][ncol]==1)
              {
                q.push({{nrow,ncol},time+1});
                ans[nrow][ncol] =2;
                countFresh--;
              }
            }
            countmin = max(countmin,time);
        }
        if(countFresh!=0)
        {
          return -1;
        }
        return countmin;
    }
};