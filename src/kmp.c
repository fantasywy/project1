#include "kmp.h"
#include <string.h>

void computeNext(const char *pattern, int next[]) {
  int len = strlen(pattern);
  next[0] = -1;
  int i = 0;
  int j = -1;
  while (i < len - 1) {
    if (j == -1 || pattern[i] == pattern[j]) {
      i++;
      j++;
      next[i] = pattern[i] == pattern[j] ? next[j] : j;
    } else {
      j = next[j];
    }
  }
}

int kmpSerarch(const char *text, const char *pattern) {
  int Tlen = strlen(text);
  int Plen = strlen(pattern);
  int next[Plen];
  computeNext(pattern, next);
  int i = 0;
  int j = 0;
  while (i < Tlen && j < Plen) {
    if (j == -1 || text[i] == pattern[j]) {
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  return j == Plen ? i - j : -1;
}