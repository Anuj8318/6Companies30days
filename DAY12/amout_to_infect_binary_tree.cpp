//2385. Amount of Time for Binary Tree to Be Infected
//https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/



class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        if (root == nullptr) return 0;
        
        // Step 1: Build a graph representation (adjacency list) for the tree
        unordered_map<int, vector<int>> graph;
        buildGraph(root, nullptr, graph);
        
        // Step 2: Perform BFS from the start node
        queue<int> q;
        unordered_set<int> visited;
        
        q.push(start);
        visited.insert(start);
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();
                
                for (int neighbor : graph[curr]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            if (!q.empty()) ++time; // Increment time if there's another layer to process
        }
        
        return time;
    }

private:
    void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& graph) {
        if (!node) return;
        if (parent) {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }
        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }
};
