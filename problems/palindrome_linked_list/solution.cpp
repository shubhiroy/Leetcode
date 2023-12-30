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
    bool isPalindrome(ListNode* head) {
        stack<int> myStack;
        ListNode *it1 = head, *it2 = head;
        while(it1->next != NULL && it2 != NULL && it2->next != NULL){
            myStack.push(it1->val);
            it1 = it1->next;
            it2 = it2->next->next;
        }
        if(it2!=NULL){
            it1 = it1->next;
        }
        while(it1!=NULL && !myStack.empty()){
            if(it1->val != myStack.top()){
                return false;
            }
            myStack.pop();
            it1 = it1->next;
        }
        if(it1 != NULL || !myStack.empty()){
            return false;
        }
        return true;
    }
};