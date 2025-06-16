#pragma once

typedef struct LinkNode {
  int val;
  struct LinkNode *prev;
  struct LinkNode *next;
} LinkNode;

typedef struct LinkList {
  LinkNode *head;
  LinkNode *tail;
  int size;
} LinkList;

LinkList *createLinkList();

void insertFirstLinkList(LinkList *list, int val);

void pushLinkList(LinkList *list, int val);

int popFirstLinkList(LinkList *list);

void removeLinkList(LinkList *list, int val);

LinkNode *searchLinkList(LinkList *list, int val);

void destroyLinkList(LinkList *list);