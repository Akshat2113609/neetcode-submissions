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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* right = head;
        ListNode* left = head;
        for(int i=0;i<n;i++){
            right = right->next;
        }
        if(right == nullptr){
            return head->next;
        }
        while(right->next!=nullptr){
            left=left->next;
            right=right->next;
        }
        ListNode* del = left->next;
        left->next=del->next;
        delete del;
        return head;
    }
};
