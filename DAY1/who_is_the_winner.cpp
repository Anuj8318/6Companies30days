// 1823. Find the Winner of the Circular Game
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// first solution
// Approach 1: Simulation with List
// Intuition
// To simulate this elimination game, we can start by representing the n 
//friends using a list data structure. Initially, this list contains all 
//the friends labeled from 1 to n. The idea is to repeatedly count to the 
//k-th friend in the list and remove them from the game. By continually removing 
//every k-th friend and adjusting our starting point after each removal, 
//we can narrow down the group until only one friend remains. This final remaining friend is the winner of the game
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> friends(n);
        for (int i = 0; i < n; i++)
        {
            friends[i] = i + 1;
        }

        int current = 0;

        while (friends.size() > 1)
        {
            current = (current + k - 1) % friends.size();
            friends.erase(friends.begin() + current);
        }

        return friends[0];
    }
};

// second solution
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            q.push(i + 1);
        }
        while (q.size() > 1)
        {
            // process first k-1 element without eliminating them
            for (int i = 0; i < k - 1; i++)
            {

                q.push(q.front());
                q.pop();
            }
            // eliminate the k element
            q.pop();
        }
        return q.front();
    }
};

// third solution
class Solution
{
    int fun(int n, int k)
    {
        if (n == 1)
            return 0;
        return (fun(n - 1, k) + k) % n;
    }

public:
    int findTheWinner(int n, int k)
    {
        return fun(n, k) + 1;
    }
};