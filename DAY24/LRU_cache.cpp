// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    // Node structure for the doubly linked list
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;  // Maximum capacity of the cache
    unordered_map<int, Node*> cache;  // Hashmap to store key-node pairs
    Node* head;  // Dummy head of the doubly linked list
    Node* tail;  // Dummy tail of the doubly linked list

    // Add a node to the front of the linked list
    void addNodeToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Remove a node from the linked list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Move a node to the front (most recently used)
    void moveToFront(Node* node) {
        removeNode(node);
        addNodeToFront(node);
    }

    // Remove the least recently used node (from the back)
    Node* removeLRUNode() {
        Node* lruNode = tail->prev;
        removeNode(lruNode);
        return lruNode;
    }

public:
    // Constructor to initialize the cache with a given capacity
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);  // Dummy head node
        tail = new Node(-1, -1);  // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }

    // Destructor to free allocated memory
    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    // Get the value associated with a key
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;  // Key not found
        }
        Node* node = cache[key];
        moveToFront(node);  // Mark as most recently used
        return node->value;
    }

    // Put a key-value pair into the cache
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update value and move to front
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            // Key does not exist, create a new node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNodeToFront(newNode);

            // If capacity is exceeded, evict the least recently used node
            if (cache.size() > capacity) {
                Node* lruNode = removeLRUNode();
                cache.erase(lruNode->key);
                delete lruNode;
            }
        }
    }
};
