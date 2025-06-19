#include "AVLTree.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static AVLNode *rotateL(AVLNode *root);
static AVLNode *rotateR(AVLNode *root);
static void initNode(AVLNode *root);
static AVLNode *createNode(int val);
static int getBalance(AVLNode *root);
static void updateHeight(AVLNode *root);
static AVLNode *rebalance(AVLNode *root);
static AVLNode *insert(AVLNode *root, int val);
static void inOrder(AVLNode *root);

AVLNode *rotateL(AVLNode *root) {
  AVLNode *right = root->right;
  root->right = right->left;
  right->left = root;
  updateHeight(root);
  updateHeight(right);
  return right;
}

AVLNode *rotateR(AVLNode *root) {
  AVLNode *left = root->left;
  root->left = left->right;
  left->right = root;
  updateHeight(root);
  updateHeight(left);
  return left;
}

void initNode(AVLNode *root) {
  root->val = 0;
  root->height = 0;
  root->left = NULL;
  root->right = NULL;
}

AVLNode *createNode(int val) {
  AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
  initNode(node);
  node->val = val;
  return node;
}

int getBalance(AVLNode *root) {
  return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(AVLNode *root) {
  root->height = (int)fmax(getHeight(root->left), getHeight(root->right)) + 1;
}

AVLNode *rebalance(AVLNode *root) {
  updateHeight(root);
  int bf = getBalance(root);
  if (bf > 1 && getBalance(root->left) >= 0) {
    root = rotateR(root);
  } else if (bf > 1 && getBalance(root->left) < 0) {
    root->left = rotateL(root->left);
    root = rotateR(root);
  } else if (bf < -1 && getBalance(root->right) <= 0) {
    root = rotateL(root);
  } else if (bf < -1 && getBalance(root->right) > 0) {
    root->right = rotateR(root->right);
    root = rotateL(root);
  }
  return root;
}

AVLNode *insert(AVLNode *root, int val) {
  if (!root) {
    return createNode(val);
  }
  if (val < root->val) {
    root->left = insert(root->left, val);
  } else if (val > root->val) {
    root->right = insert(root->right, val);
  }
  return rebalance(root);
}

void initAVLTree(AVLTree *tree) { tree->root = NULL; }

int getHeight(AVLNode *node) { return node ? node->height : 0; }

void insertAVLTree(AVLTree *tree, int val) {
  tree->root = insert(tree->root, val);
}

void inOrder(AVLNode *root) {
  if (!root) {
    return;
  }
  inOrder(root->left);
  printf("%d ", root->val);
  inOrder(root->right);
}

void inOrderAVLTree(AVLTree *tree) {
  inOrder(tree->root);
  printf("\n");
}