// 419. Battleships in a Board
// https://leetcode.com/problems/battleships-in-a-board/



class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Check if the current cell is 'X' and not part of another
                // battleship
                if (board[i][j] == 'X' &&
                    (i == 0 || board[i - 1][j] != 'X') && // No 'X' above
                    (j == 0 || board[i][j - 1] != 'X')) { // No 'X' to the left
                    count++;
                }
            }
        }

        return count;
    }
};