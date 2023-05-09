/*
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.

Implement the CBTInserter class:

CBTInserter(TreeNode root) Initializes the data structure with the root of the complete binary tree.
int insert(int v) Inserts a TreeNode into the tree with value Node.val == val so that the tree remains complete, and returns the value of the parent of the inserted TreeNode.
TreeNode get_root() Returns the root node of the tree.

Example:
Input
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
Output
[null, 1, 2, [1, 2, 3, 4]]

Explanation
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // return 1
cBTInserter.insert(4);  // return 2
cBTInserter.get_root(); // return [1, 2, 3, 4]
*/


#include "essentials.h"

class CBTInserter {
public:
  CBTInserter(TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      auto* node = q.front();
      q.pop();
      nodes.push_back(node);
      auto* left = node->left;
      if (left != nullptr) q.push(left);
      auto* right = node->right;
      if (right != nullptr) q.push(right);
    }
    commons::print(nodes);
  }

  int insert(int val) {
    TreeNode* node = new TreeNode(val);
    int i = nodes.size();
    int pi = (i - 1) / 2;
    auto* p = nodes[pi];
    commons::print(i, pi, p);
    if (i % 2 == 1) {
      p->left = node;
    } else {
      p->right = node;
    }
    nodes.push_back(node);
    commons::print(nodes);
    return p->val;
  }

  TreeNode* get_root() {
    return nodes[0];
  }

private:
  std::vector<TreeNode*> nodes;
};


int main() {
  TreeNode* root = new TreeNode({1, INT_MIN, 2});
  CBTInserter cBTInserter(root);
  std::cout << cBTInserter.insert(3) << std::endl;  // return 1
  std::cout << cBTInserter.insert(4) << std::endl;  // return 2
  std::cout << *cBTInserter.get_root() << std::endl; // return [1, 2, 3, 4]
}

