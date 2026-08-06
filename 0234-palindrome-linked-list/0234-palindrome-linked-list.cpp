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
        ListNode* temp = head;
        stack<int> st;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        ListNode* front = head;
        while(front!=NULL){
            if(front->val!=st.top()){
                return false;
            }
            st.pop();
            front = front->next;
        } 
        return true;
    }
};