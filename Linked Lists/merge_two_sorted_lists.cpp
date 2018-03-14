//  https://www.interviewbit.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    ListNode* tA = A;
    ListNode* tB = B;
    
    if(tA==NULL)
        return B;
    if(tB==NULL)
        return A;
    
    ListNode* head, *temp;
    
    if(tA->val < tB->val) {
        head = tA;
        tA = tA->next;
    }
    else {
        head = tB;
        tB = tB->next;
    }
    temp = head;
    while(tA!=NULL && tB!=NULL) {
        if(tA->val < tB->val) {
            temp->next = tA;
            temp = tA;
            tA = tA->next;
        }
        else {
            temp->next = tB;
            temp = tB;
            tB = tB->next;
        }
    }
    if(tB==NULL) {
        while(tA!=NULL) {
            temp->next = tA;
            temp = tA;
            tA = tA->next;
        }
    }
    if(tA==NULL) {
        while(tB!=NULL) {
            temp->next = tB;
            temp = tB;
            tB = tB->next;
        }
    }
    return head;
}


