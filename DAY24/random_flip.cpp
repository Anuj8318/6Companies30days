// 519. Random Flip Matrix
// https://leetcode.com/problems/random-flip-matrix/
class Solution {
private:
    int m, n, total;
    unordered_map<int, int> flipped;

public:
    // Constructor: Initialize the object with matrix dimensions
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
    }

    // Flip a random 0 to 1
    vector<int> flip() {
        // Pick a random index in the remaining range
        int randIndex = rand() % total;

        // Determine the actual index to flip
        int actualIndex = flipped.count(randIndex) ? flipped[randIndex] : randIndex;

        // Map the picked index to the last available index
        flipped[randIndex] = flipped.count(total - 1) ? flipped[total - 1] : (total - 1);

        // Decrement the total available indices
        total--;

        // Convert the 1D index to 2D coordinates
        return {actualIndex / n, actualIndex % n};
    }

    // Reset the matrix to all 0s
    void reset() {
        total = m * n;
        flipped.clear();
    }
};
