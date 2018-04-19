//  https://www.interviewbit.com/problems/least-common-ancestor/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool find(TreeNode* A, int val) {
    if(!A)
        return false;
    if(A->val==val)
        return true;
    if((A->left && find(A->left, val)) || (A->right && find(A->right, val)))
        return true;
    return false;
}
TreeNode* LCA(TreeNode* A, int B, int C) {
    if(!A)
        return A;
    if(A->val==B || A->val==C)
        return A;
    auto L = LCA(A->left, B, C);
    auto R = LCA(A->right, B, C);
    if(L&&R)
        return A;
    return (L?L:R);
}
int Solution::lca(TreeNode* A, int B, int C) {
    
    if(!find(A, B) || !find(A, C))
        return -1;
        
    auto ancestor = LCA(A, B, C);
    if(ancestor)
        return ancestor->val;
    return -1;
}
