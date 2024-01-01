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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sumListHead = NULL, *prevNode = NULL, *num1 = l1, *num2 = l2;
        int carry =0;
        bool isHeadNode = true;
        while(num1!=NULL || num2!=NULL || carry){
            int sum = 0;
            if(num1 != NULL){
                sum += num1->val;
                num1 = num1->next;
            }
            if(num2 != NULL){
                sum += num2->val;
                num2 = num2->next;
            }
            if(carry != 0){
                sum += carry;
            }
            carry = sum/10;
            ListNode *newNode = new ListNode(sum%10);
            if(isHeadNode){
                sumListHead = newNode;
                prevNode = newNode;
                isHeadNode = false;
            }else{
                prevNode->next = newNode;
                prevNode = newNode;
            }
        }
        return sumListHead;
    }
};