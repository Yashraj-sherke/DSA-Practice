class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // ListNode* curr = head;
        //BRUTE
        // while(curr != NULL && curr->next != NULL) {
        //     if(curr->val == curr->next->val) {
        //         ListNode* temp = curr->next;
        //         curr->next = curr->next->next;
        //         delete temp;
        //     } else {
        //         curr = curr->next;
        //     }
        // }

        // return head;

        if(head==NULL)
        {
            return head;

        }

        ListNode*slow=head;
        ListNode*fast=head->next;

        while(fast!=NULL)
        {
            if(slow->val==fast->val)
            {
                slow->next=fast->next;
                delete fast;
                fast=slow->next;
            }
            else
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        return head;


    }
};
