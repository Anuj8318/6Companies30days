


class Solution {
  public:
    string matrixChainOrder(vector<int> &arr) {
           int n = arr.size() - 1; // Number of matrices
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> split(n, vector<int>(n, -1));
        
        // Fill DP table
        for (int len = 2; len <= n; ++len) { // Chain length
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; ++k) {
                    int cost = dp[i][k] + dp[k+1][j] + arr[i] * arr[k+1] * arr[j+1];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }

        // Reconstruct the parenthesized string
        return buildParenthesis(split, 0, n-1);
    }

private:
    string buildParenthesis(vector<vector<int>>& split, int i, int j) {
        if (i == j) {
            return string(1, 'A' + i); // Return matrix name
        }
        int k = split[i][j];
        return "(" + buildParenthesis(split, i, k) + buildParenthesis(split, k+1, j) + ")";
    }
};


/*
1. Understanding the Problem:
Input: An array arr[] of size n, representing dimensions of 

n−1 matrices. The dimensions of the 

i-th matrix are arr[i] * arr[i+1].
Output: The parenthesized order of matrix multiplication (a string) that minimizes the number of scalar multiplications.
Constraints:
n≤26: We can label matrices 

Matrix multiplication is associative but not commutative, so the order of multiplication affects the result.
Goal: Minimize the scalar multiplications while maintaining the correct order of matrices.


2. Intuition:
This is a Dynamic Programming (DP) problem.
State Definition: To find the optimal parenthesization for matrices A[i] to A[j]:
We split the matrices at different positions i≤k<j) and recursively compute the cost for each split.
At each split, compute the cost of multiplying the matrices formed by the two subproblems and the resulting matrix.
Optimal Substructure: The optimal solution for multiplying matrices A[i] to A[j] depends on the 
optimal solutions for multiplying A[i] to A[k] and A[k+1] to A[j].

Key Addition: In this problem, we also track the parenthesization order to generate the string output.



3. Approach:
Step 1: Dynamic Programming Table
We maintain a DP table dp[i][j]:

dp[i][j] represents the minimum cost to multiply matrices A[i] to A[j].
split[i][j]: Tracks the split point k where the cost was minimized, to help reconstruct the parenthesization.

Step 2: Base Case
If there’s only one matrix (i==j), no multiplication is required, so dp[i][j]=0.

Step 3: Recurrence Relation
For i<j: cost of multiplying matrices and 
dp[i][j]=min 
i≤k<j (dp[i][k]+dp[k+1][j]+cost of multiplying matrices A[i:k] and A[k+1:j]) The cost of multiplying two matrices 
A[i:k] and A[k+1:j] is: cost=arr[i−1]×arr[k]×arr[j]

Step 4: Reconstructing the String
Using the split table, recursively build the parenthesized string:

Start with the range A[1] to A[n−1].
At each split point k, wrap the two subranges in parentheses:
Left subrange: A[i:k]
Right subrange: A[k+1:j]




4. Algorithm Steps
Initialize dp and split tables.
Use a bottom-up approach to fill the tables:
Iterate over increasing lengths of matrix chains.
For each length, calculate dp[i][j] and track the optimal split.
Use the split table to reconstruct the parenthesized order.
*/