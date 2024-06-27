#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
      solve(root, 0);
      return root;
    }

    int solve(TreeNode* root, int sumToAddToNode) {
      int rightSideVal = 0, leftSideVal = 0;
      if (root->right != nullptr) {
        rightSideVal = solve(root->right, sumToAddToNode);
      }
      root->val = root->val + (rightSideVal == 0 ? sumToAddToNode : rightSideVal);
      if (root->left != nullptr) {
        leftSideVal = solve(root->left, root->val);
      }
      return max(root->val, leftSideVal);
    }
};

int main() {
  Solution sol;
  // vector<int> nums = {8,2,4,7};
  int ret = sol.longestSubarray(nums, 63);
	printf("hey %d\n", ret);
	return 0;
}
