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
    ListNode* solve(ListNode* head) {
        if(head->next == NULL || head->next->next == NULL) return head;
        ListNode *curr = NULL, *mid = NULL, *last = NULL;
        mid = head->next;
        curr = head;
        while(curr->next->next != NULL) curr = curr->next;
        last = curr->next;
        curr->next = NULL;
        last->next = solve(mid);
        head->next = last;
        return head;
    }
    void reorderList(ListNode* head) {
        head = solve(head);
    }
};