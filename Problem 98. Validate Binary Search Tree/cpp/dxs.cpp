/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        
        return isValid(root, (long long)0x7FFFFFFFFFFFFFFF, (long long)0x8000000000000000);
    }
private:
    bool isValid(TreeNode* root, long long i32Up, long long i32Low) 
    {
        if (!root)return true;
        //cout<<root->val<<" "<<i32Up<<" "<<i32Low<<endl;
        if(root->val<=i32Low||root->val>=i32Up)return false;
        if(!isValid(root->left, min(i32Up,root->val), i32Low))return false;
        if(!isValid(root->right, i32Up, max(i32Low, root->val)))return false;
        
        return true;
    }
    long long min(long long a, long long b)
    {
        return a>b?b:a;
    }
    long long max(long long a, long long b)
    {
        return a>b?a:b;
    }
};