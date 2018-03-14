//  https://www.interviewbit.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* mergeTwoLists(listnode* A, listnode* B) {

    listnode* result = NULL;
    if(A==NULL)
        return B;
    else if(B==NULL)
        return A;
    if(A->val <= B->val)
    {
        result = A;
        result->next = mergeTwoLists(A->next, B);
    }
    else
    {
        result = B;
        result->next = mergeTwoLists(A, B->next);
    }
    return result;
}

