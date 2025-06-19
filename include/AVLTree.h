#pragma once

typedef struct AVLNode {
  int val;
  int height;
  struct AVLNode *left;
  struct AVLNode *right;
} AVLNode;

typedef struct AVLTree {
  AVLNode *root;
} AVLTree;

void initAVLTree(AVLTree *tree);

int getHeight(AVLNode *node);

void insertAVLTree(AVLTree *tree, int val);

void inOrderAVLTree(AVLTree *tree);