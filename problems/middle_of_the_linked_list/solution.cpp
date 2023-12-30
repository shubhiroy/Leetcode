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
    ListNode* middleNode(ListNode* head) {
        ListNode *it1 = head, *it2 = head;
        while(it1->next != NULL && it2 != NULL && it2->next != NULL){
            it1 = it1->next;
            it2 = it2->next->next;
        }
        return it1;
    }
};