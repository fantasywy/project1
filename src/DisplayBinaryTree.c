#include "DisplayBinaryTree.h"
#include "AVLTree.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

static int getNumLength(int num);
static void printNodeLine(AVLNode *root, int isleft, const wchar_t *str,
                          size_t len);
static void dfs(AVLNode *root, bool isleft, const wchar_t *str);

int getNumLength(int num) {
  int len = 0;
  while (num) {
    num /= 10;
    ++len;
  }
  return len;
}

void printNodeLine(AVLNode *root, int isleft, const wchar_t *str, size_t len) {
  wprintf(L"%ls", str);
  if (len) {
    // printf("%s", isleft ? "└" : "┌");
    wprintf(L"%lc", isleft ? L'╰' : L'╭');
  }
  printf("%d", root->val);
  if (root->left || root->right) {
    if (root->left && root->right) {
      wprintf(L"┤");
    } else if (root->left) {
      wprintf(L"┐");
    } else {
      wprintf(L"┘");
    }
  }
  wprintf(L"\n");
}

void dfs(AVLNode *root, bool isleft, const wchar_t *str) {
  if (!root) {
    return;
  }

  size_t preLen = wcslen(str);
  size_t curLen = preLen + getNumLength(root->val) + 1;
  wchar_t curStr[curLen];
  wmemset(curStr, L' ', curLen);
  curStr[preLen ? curLen : curLen - 1] = L'\0';
  for (int i = 0; i < preLen; ++i) {
    curStr[i] = str[i];
  }

  if (preLen) {
    curStr[preLen] = isleft ? L'│' : L' ';
  }
  dfs(root->right, false, curStr);
  printNodeLine(root, isleft, str, preLen);
  if (preLen) {
    curStr[preLen] = !isleft ? L'│' : L' ';
  }
  dfs(root->left, true, curStr);
};

void displayBinaryTree(AVLNode *root) { dfs(root, false, L""); }