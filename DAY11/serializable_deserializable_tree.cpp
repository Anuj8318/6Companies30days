// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// 297. Serialize and Deserialize Binary Tree



// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";

        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                ans += "null,";
            } else {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string value;
        getline(ss, value, ',');

        TreeNode* root = new TreeNode(stoi(value));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (getline(ss, value, ',')) {
                if (value != "null") {
                    node->left = new TreeNode(stoi(value));
                    q.push(node->left);
                }
            }

            if (getline(ss, value, ',')) {
                if (value != "null") {
                    node->right = new TreeNode(stoi(value));
                    q.push(node->right);
                }
            }
        }
        
        return root;
    }
};

// Example usage:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
