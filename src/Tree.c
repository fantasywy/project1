#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <vadefs.h>

void initNode(TreeNode **root, int val) {
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->left = NULL;
  node->right = NULL;
  node->val = val;
  *root = node;
}

TreeNode *insert(TreeNode *root, int val) {
  if (root == NULL) {
    TreeNode *node = NULL;
    initNode(&node, val);
    return node;
  }

  if (val < root->val) {
    root->left = insert(root->left, val);
  } else if (val > root->val) {
    root->right = insert(root->right, val);
  }

  return root;
}

void insertTree(TreeNode **root, int val) { *root = insert(*root, val); }

void preOrder(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->val);
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  inOrder(root->left);
  printf("%d ", root->val);
  inOrder(root->right);
}