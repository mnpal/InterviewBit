//  https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A==NULL || A->next==NULL)
        return A;
    ListNode* prev = A;
    ListNode* curr = A->next;
    ListNode* prevPrev;
    
    prev->next = curr->next;
    curr->next = prev;
    A = curr;
    
    if(prev->next == NULL || prev->next->next==NULL)
        return A;
    
    prevPrev = prev;
    prev = prev->next;
    curr = prev->next;
    
    
    while(1) {
        prev->next = curr->next;
        curr->next = prev;
        prevPrev->next = curr;
        if(prev->next==NULL || prev->next->next==NULL)
            break;
        prevPrev = prev;
        prev = prev->next;
        curr = prev->next;
    }
    return A;
}

