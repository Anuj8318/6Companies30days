// 1568. Minimum Number of Days to Disconnect Island
// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

class Solution {
public:
    int m, n;

    // Directions for 4-way movement
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // DFS to count islands
    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {
        visited[i][j] = true;
        for (auto [dx, dy] : directions) {
            int ni = i + dx, nj = j + dy;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1 &&
                !visited[ni][nj]) {
                dfs(ni, nj, grid, visited);
            }
        }
    }

    // Function to count the number of islands
    int countIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    islands++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        // Step 1: Check if already disconnected
        if (countIslands(grid) != 1)
            return 0;

        // Step 2: Try removing each land cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; // Remove land
                    if (countIslands(grid) != 1)
                        return 1;   // If disconnected, return 1
                    grid[i][j] = 1; // Restore land
                }
            }
        }

        // Step 3: If no single move works, return 2
        return 2;
    }
};
