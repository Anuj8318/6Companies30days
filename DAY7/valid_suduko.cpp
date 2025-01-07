// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/


#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            std::unordered_set<char> rowSet;
            std::unordered_set<char> colSet;
            std::unordered_set<char> subgridSet;
            
            for (int j = 0; j < 9; j++) {
                // Check rows
                if (board[i][j] != '.' && rowSet.count(board[i][j]) > 0) {
                    return false;
                }
                rowSet.insert(board[i][j]);
                
                // Check columns
                if (board[j][i] != '.' && colSet.count(board[j][i]) > 0) {
                    return false;
                }
                colSet.insert(board[j][i]);
                
                // Check 3x3 subgrids
                int subgridRow = 3 * (i / 3);
                int subgridCol = 3 * (i % 3);
                if (board[subgridRow + j / 3][subgridCol + j % 3] != '.' &&
                    subgridSet.count(board[subgridRow + j / 3][subgridCol + j % 3]) > 0) {
                    return false;
                }
                subgridSet.insert(board[subgridRow + j / 3][subgridCol + j % 3]);
            }
        }
        
        return true; // The board is valid if all checks pass
    }
};