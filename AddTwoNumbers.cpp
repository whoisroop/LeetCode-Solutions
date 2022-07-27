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
    void recursion(ListNode * ptrA, ListNode * ptrB, ListNode * &ptrC, int carry){
        int sum, newCarry;
        
        if(ptrA == NULL && ptrB == NULL){
            if(carry != 0){
                sum = carry;
                ptrC = new ListNode(sum);
                return;
            }
            
            else    return;
        }
        
        if(ptrA == NULL || ptrB == NULL){
            if(ptrA == NULL && ptrB != NULL){
                sum = (ptrB->val + carry);
                newCarry = sum/10;
                sum = sum%10;
                ptrC = new ListNode(sum);
                recursion(ptrA, ptrB->next, ptrC->next, newCarry);
            }
            
            else{
                sum = (ptrA->val + carry);
                newCarry = sum/10;
                sum = sum%10;
                ptrC = new ListNode(sum);
                recursion(ptrA->next, ptrB, ptrC->next, newCarry);
            }
        }
        
        else{
            sum = ptrA->val + ptrB->val + carry;
            newCarry = sum/10;
            sum = sum%10;

            ptrC = new ListNode(sum);
            recursion(ptrA->next, ptrB->next, ptrC->next, newCarry);
            return;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * sum = NULL;
        recursion(l1, l2, sum, 0);
        return sum;
    }
};