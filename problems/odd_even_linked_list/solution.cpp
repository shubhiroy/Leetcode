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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *it1 = head, *it2 = head;
        while(it2->next != NULL && it2->next->next != NULL){
            it2 = it2->next->next;
        }
        ListNode *oddLastNode = it2, *evenLastNode = NULL;
        if(it2->next!=NULL){
            // oddLastNode = it2;
            evenLastNode = it2->next;
        }
        while(it1 != oddLastNode){
            ListNode *temp = it1->next;
            it2->next = temp;
            it2 = temp;
            it1->next = temp->next;
            it2->next = NULL;
            it1=it1->next;
        }
        it2->next = evenLastNode;
        return head;
    }
};