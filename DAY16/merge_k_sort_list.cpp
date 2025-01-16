// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class compare {
 public:
 bool operator()(ListNode*a,ListNode*b)
 {
    return a->val > b->val;
 }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*,vector<ListNode*>,compare> pq;
       int k = lists.size();
       if(k ==0)
       {

        return nullptr;
       }
        // step 1:
        for(int i =0;i<k;i++)
        {
            if(lists[i]!=nullptr)
            {
                pq.push(lists[i]);
            }
        } 


        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while(pq.size()!=0)
        {
           ListNode* top = pq.top();
           pq.pop();

           if(top->next!=nullptr)
           {
            pq.push(top->next);
           }

           if(head==nullptr)
           {
            // answer list agar null hai
              head = top;
              tail = top; 
           }
           else
           {
            // list agar empty nahi hai to 
            tail->next = top ;
            tail = top;
           }
        }
        return head;
    }
};