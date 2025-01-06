
// Delete N nodes after M nodes of a linked list
// GFG PROBLEM -https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
         Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        // Skip `m` nodes
        for (int i = 0; i < m && temp != nullptr; i++) {
            prev = temp;
            temp = temp->next;
        }

        // Delete `n` nodes
        for (int i = 0; i < n && temp != nullptr; i++) {
            Node* nodeToDelete = temp;
            temp = temp->next;
            delete nodeToDelete;
        }

        // Connect the remaining list after deletion
        if (prev != nullptr) {
            prev->next = temp;
        }
    }

    return head;
    }
};