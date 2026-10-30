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
        ListNode* curr = head;
        int total =0;
        while(curr!=nullptr){
            total++;
            curr= curr->next;
        }
        
        if (n == total) {
            return head->next;
        }
        int remove = total-n;
        curr= head;
        for(int i =1;i<total;i++){
            if(i == remove){
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};
