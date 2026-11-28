class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

        // If head itself needs to be deleted
        if(len == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int ans = len - n - 1;

        ListNode* del = head;

        for(int i = 0; i < ans; i++) {
            del = del->next;
        }

        ListNode* nodeToDelete = del->next;
        del->next = del->next->next;
        delete nodeToDelete;

        return head;
    }
};
