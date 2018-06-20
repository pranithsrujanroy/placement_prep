/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<TreeNode*> generate_trees_util(int start,int end){
    vector<TreeNode*> root;
    if(start>end){
        root.push_back(NULL);
        return root;
    }
    for(int i=start;i<=end;i++){
        vector<TreeNode*> leftsubtrees = generate_trees_util(start,i-1);
        vector<TreeNode*> rightsubtrees= generate_trees_util(i+1,end);
        for(int j=0;j<leftsubtrees.size();j++){
            TreeNode *leftsubtree = leftsubtrees[j];
            for(int k=0;k<rightsubtrees.size();k++){
                TreeNode *rightsubtree = rightsubtrees[k];
                TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode*));
                node->val = i;
                node->left=leftsubtree;
                node->right=rightsubtree;
                root.push_back(node);
            }
        }
    }
    return root;
 }
vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return generate_trees_util(1,A);
}
