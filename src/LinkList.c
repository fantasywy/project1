#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

static LinkNode *createNode(int val);

LinkNode *createNode(int val) {
  LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
  node->val = val;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

LinkList *createLinkList() {
  LinkList *list = (LinkList *)malloc(sizeof(LinkList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void insertFirstLinkList(LinkList *list, int val) {
  if (!list) {
    return;
  }
  LinkNode *head = list->head;
  LinkNode *node = createNode(val);
  node->next = head;
  list->head = node;
  if (head) {
    head->prev = node;
  }
  if (!list->tail) {
    list->tail = node;
  }
  list->size++;
}

void pushLinkList(LinkList *list, int val) {
  if (!list) {
    return;
  }
  LinkNode *tail = list->tail;
  LinkNode *node = createNode(val);
  if (!list->head) {
    list->head = node;
  }
  node->prev = tail;
  if (tail) {
    tail->next = node;
  }
  list->tail = node;
  list->size++;
}

int popFirstLinkList(LinkList *list) {
  LinkNode *node = list->head;
  list->head = node->next;
  if (list->head) {
    list->head->prev = NULL;
  }
  list->size--;
  int val = node->val;
  free(node);
  return val;
}

void removeLinkList(LinkList *list, int val) {
  LinkNode *node = searchLinkList(list, val);
  if (!node) {
    return;
  }
  node->prev->next = node->next;
  node->next->prev = node->prev;
  list->size--;
  free(node);
}

LinkNode *searchLinkList(LinkList *list, int val) {
  if (!list) {
    return NULL;
  }
  LinkNode *head = list->head;
  while (head) {
    if (head->val == val) {
      return head;
    }
    head = head->next;
  }
  return NULL;
}

void destroyLinkList(LinkList *list) {
  if (!list) {
    return;
  }
  LinkNode *head = list->head;
  while (head) {
    LinkNode *node = head;
    head = head->next;
    free(node);
  }
  free(list);
}