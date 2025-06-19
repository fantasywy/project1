#include "AVLTree.h"
#include "DisplayBinaryTree.h"
#include <limits.h>
#include <locale.h>
#include <stdbool.h>

int main() {
  setlocale(LC_ALL, "");
  AVLTree tree;
  initAVLTree(&tree);
  for (int i = 90; i < 110; i++) {
    insertAVLTree(&tree, i);
  }
  displayBinaryTree(tree.root);
}
