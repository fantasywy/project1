#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode, *Tree;

void insertTree(TreeNode **root, int val);

void preOrder(TreeNode *root);

void inOrder(TreeNode *root);

void postOrder(TreeNode *root);

void destroyTree(TreeNode *root);
#endif