/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//  #include <stack>
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> l1, l2;
        ListNode *h1 = headA, *h2=headB;
        while(h1 != NULL || h2 != NULL){
            if(h1!=NULL){
                l1.push(h1);
                h1 = h1->next;
            }
            if(h2!=NULL){
                l2.push(h2);
                h2 = h2->next;
            }
        }
        ListNode *intersecNode = NULL;
        while(!l1.empty() && !l2.empty()){
            if(l1.top() != l2.top()){
                return intersecNode;
            }
            intersecNode = l1.top();
            l1.pop();
            l2.pop();
        }
        return intersecNode;
    }
};