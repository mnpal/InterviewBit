//  https://www.interviewbit.com/problems/reverse-link-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int findLen(ListNode* A) {
    int c = 0;
    while(A!=NULL) {
        c++;
        A = A->next;
    }
    return c;
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    ListNode* prevNode = A;
    
    for(int i=1;i<B-1;i++) {
        prevNode = prevNode->next;
    }
    
    ListNode* nextNode = A;
    for(int i=0;i<C;i++) {
        if(nextNode->next==NULL)
            break;
        nextNode = nextNode->next;
    }
    
    vector<ListNode*> nodes;
    ListNode* temp;
    if(B==1)
        temp = A;
    else
        temp = prevNode->next;
        
    for(int i=B-1;i<C;i++) {
        nodes.push_back(temp);
        if(temp->next==NULL)
            break;
        temp = temp->next;
    }
    
    reverse(nodes.begin(), nodes.end());
    
    int n = C-B;
    int m = findLen(A);
    
    for(int i=0;i<n;i++) {
        nodes[i]->next = nodes[i+1];
    }
    
    if(B==1 && C==m) {
        nodes[n]->next = NULL;
        return nodes[0];
    }
    else if(B==1) {
        nodes[n]->next = nextNode;
        return nodes[0];
    }
    else if(C==m) {
        prevNode->next = nodes[0];
        nodes[n]->next = NULL;
        return A;
    }
    else {
        prevNode->next = nodes[0];
        nodes[n]->next = nextNode;
        return A;
    }
    
    return A;
}

