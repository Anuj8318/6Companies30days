// 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Count word frequencies
        map<string, int> mp;
        for (string s : words) {
            mp[s]++;
        }

        // Custom comparator for the priority queue
        auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
            // Compare by frequency (descending), then by lexicographical order (ascending)
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        };

        // Priority queue to store top k frequent elements
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        for (auto& it : mp) {
            pq.push({it.second, it.first});
        }

        // Extract the top k elements
        vector<string> ans;
        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
