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
class Solution {
public:
    ListNode* removeNthFromStart(ListNode* head, int n) {
        ListNode *prev = NULL, *curr = NULL;
        int len = 0;
        while(len!=n) {
            len++;
            prev = curr;
            if(!curr) curr = head;
            else curr = curr->next;
        }
        if(!prev) return head->next;
        prev->next = curr->next;
        return head;
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;
        while(curr!=NULL) {
            len++;
            curr = curr->next;
        }
        return removeNthFromStart(head, len-n+1);
    }
};