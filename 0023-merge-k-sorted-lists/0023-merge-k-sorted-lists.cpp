class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            ListNode *temp=lists[i];
            while(temp!=NULL){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* start=new ListNode(-1);
        ListNode* x=start;
        while(!pq.empty()){
            ListNode* y=new ListNode(pq.top());
            x->next=y;
            x=x->next;
            pq.pop();


         }
       
        return start->next;
    }
};
