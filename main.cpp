// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos

#include <iostream>

using namespace std;
/**
 * Definition for a binary tree node.
*/

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if (root) {
        TreeNode* newLeft = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = newLeft;
      }
      return root;
    }
};


void print(TreeNode* root) {
  if (root) {
    print(root->left);
    cout << root->val << " ";
    print(root->right);
  }
}
/*
     4
   /   \
  2     7
 / \   / \
1   3 6   9

*/


int main() {
  Solution S;

  TreeNode* t1 = new TreeNode(4);
  t1->left = new TreeNode(2);
  t1->left->left = new TreeNode(1);
  t1->left->right = new TreeNode(3);

  t1->right = new TreeNode(7);
  t1->right->left = new TreeNode(6);
  t1->right->right = new TreeNode(9);

  print(t1);
  cout << endl;

  print(S.invertTree(t1));
  cout << endl;

  // delete stuff
  std::cout << "Done\n";
}
