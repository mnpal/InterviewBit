//  https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL)
        return A;
    ListNode* temp = A;
    ListNode* dup_node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* next_next, *prev_node = NULL;
    next_next = (ListNode*)malloc(sizeof(ListNode));
    while(temp->next != NULL)
    {
        if(temp->val == temp->next->val)
        {
            while(temp->val == temp->next->val)
            {
                next_next = temp->next->next;
                free(temp->next);
                temp->next = next_next;
                if(temp->next == NULL)
                    break;
            }
            if(temp->next==NULL && prev_node==NULL)
            {
                A = NULL;
                break;
            }
            else if(temp->next == NULL && prev_node!=NULL)
            {
                //free(temp);
                prev_node->next = temp->next;
            }
            else
            {
                dup_node = temp;
                temp = temp->next;
                free(dup_node);
                if(prev_node != NULL)
                    prev_node->next = temp;
                else
                    A = temp;
            }
        }
        else
        {
            prev_node = temp;
            temp = temp->next;
        }
    }
    return A;
}

