class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap storing ListNode pointers
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            function<bool(ListNode*, ListNode*)>
        > pq(
            [](ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        );

        // Put first node of every list into heap
        for (auto head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        // Dummy node helps us build the answer
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            // Get smallest node
            ListNode* node = pq.top();
            pq.pop();

            // Add it to answer
            tail->next = node;
            tail = tail->next;

            // Push next node from the same list
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};