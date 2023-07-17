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
 #define ll long long
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Brute Force 1561 Testcases passed
        // ListNode* t1 = l1;
        // ll num1 = 0;
        // while(l1!=NULL){
        //     num1 = num1*10 + l1->val;
        //     l1 = l1->next;
        // }
        // ListNode* t2 = l2;
        // ll num2 = 0;
        // while(l2!=NULL){
        //     num2 = num2*10 + l2->val;
        //     l2 = l2->next;
        // }
        // ListNode* head = new ListNode(0);
        // ListNode* ans = head;
        // ll sum = num1 + num2;
        // while(sum>0){
        //     ListNode* newHead = new ListNode(sum%10);
        //     ans->next = newHead;
        //     ans = newHead;
        //     sum/=10;
        // }
        // // Reversing of the new LinkedList
        // ListNode* prev = NULL;
        // ListNode* curr = head->next;
        // ListNode* nexx ;
        // while(curr!=NULL){
        //     nexx = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nexx;
        // }
        // ListNode* sudo = new ListNode(0);
        // return prev==NULL?sudo:prev;

        // Optimal Approach using two stacks
        stack<int> s1;
        stack<int> s2;
        while(l1!=NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int totalSum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                totalSum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                totalSum += s2.top();
                s2.pop();
            }
            ans->val = totalSum%10;
            carry = totalSum/10;
            ListNode* newNode  = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            totalSum = carry;
        }
        return carry==0?ans->next:ans;

        // Optimal Approach by reversing of the two Linked List
        
    }
};