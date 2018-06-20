//https://www.interviewbit.com/problems/level-order/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> a;
    queue<pair<TreeNode*,int>> q;
    if(A==NULL)
        return a;
    TreeNode *temp = A;
    int l=0;
    vector<int> t;
    q.push(make_pair(temp,l));
    while(!q.empty()){
        TreeNode* temp = q.front().first;
        l=q.front().second;
        if(a.size()!=l+1)
            a.push_back(t);
        a[l].push_back(temp->val);
        l++;
        if(temp->left!=NULL)
            q.push(make_pair(temp->left,l));
        if(temp->right!=NULL)
            q.push(make_pair(temp->right,l));
        q.pop();
    }
    return a;
}
