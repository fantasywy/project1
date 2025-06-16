#include "AVLTree.h"
#include "Queue.h"
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  AVLTree tree;
  initAVLTree(&tree);
  for (int i = 0; i < 20; i++) {
    insertAVLTree(&tree, i);
  }
  displayAVLTree(&tree);
}
