// 1686. Stone Game VI

// https://leetcode.com/problems/stone-game-vi/
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        
        // Create a vector to store the combined value and the index
        vector<pair<int, int>> valueDiff(n);
        for (int i = 0; i < n; ++i) {
            valueDiff[i] = {aliceValues[i] + bobValues[i], i};
        }
        
        // Sort in descending order of combined value
        sort(valueDiff.rbegin(), valueDiff.rend());
        
        int aliceScore = 0, bobScore = 0;
        
        // Simulate the game
        for (int turn = 0; turn < n; ++turn) {
            int index = valueDiff[turn].second;
            if (turn % 2 == 0) { // Alice's turn
                aliceScore += aliceValues[index];
            } else { // Bob's turn
                bobScore += bobValues[index];
            }
        }
        
        // Determine the winner
        if (aliceScore > bobScore) {
            return 1; // Alice wins
        } else if (bobScore > aliceScore) {
            return -1; // Bob wins
        } else {
            return 0; // Draw
        }
    }
};