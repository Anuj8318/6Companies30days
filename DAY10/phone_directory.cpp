// https://www.geeksforgeeks.org/problems/phone-directory4628/1
class Solution{
public:
   // Trie Node definition
struct TrieNode {
    map<char, TrieNode*> children;
    set<string> contacts; // Store unique contacts in lexicographical order
};

// Trie implementation
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a contact into the Trie
    void insert(const string& contact) {
        TrieNode* node = root;
        for (char ch : contact) {
            if (!node->children[ch]) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->contacts.insert(contact);
        }
    }

    // Search for a prefix in the Trie
    vector<string> search(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children[ch]) {
                return {}; // Prefix not found
            }
            node = node->children[ch];
        }
        return vector<string>(node->contacts.begin(), node->contacts.end());
    }
};

// Function to display contacts
vector<vector<string>> displayContacts(int n, string contact[], string s) {
    Trie trie;

    // Insert all contacts into the Trie
    for (int i = 0; i < n; ++i) {
        trie.insert(contact[i]);
    }

    vector<vector<string>> result;
    string prefix = "";

    // Search for each prefix of the query string
    for (char ch : s) {
        prefix += ch;
        vector<string> results = trie.search(prefix);

        if (results.empty()) {
            result.push_back({"0"}); // No match found
        } else {
            result.push_back(results);
        }
    }

    return result;
}