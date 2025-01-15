// 331. Verify Preorder Serialization of a Binary Tree
// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution {
public:
    bool isValidSerialization(string preorder) {
    int slots = 1; // Start with one slot for the root node
    stringstream ss(preorder);
    string node;

    while (getline(ss, node, ',')) {
        slots--; // Consume one slot for the current node
        if (slots < 0) {
            return false; // If slots become negative, it's invalid
        }
        if (node != "#") {
            slots += 2; // Non-null node adds two slots
        }
    }

    return slots == 0; // All slots should be consumed
    }
};