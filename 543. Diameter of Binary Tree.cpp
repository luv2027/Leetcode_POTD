class Solution
{
public:
  int maxi = INT_MIN;
  int h(TreeNode *root)
  {
    if (root == NULL)
    {
      return 0;
    }
    int l = h(root->left);
    int r = h(root->right);

    maxi = max(maxi, l + r);
    return 1 + max(l, r);
  }

  int diameterOfBinaryTree(TreeNode *root)
  {
    h(root);
    return maxi;
  }
};