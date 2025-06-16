#pragma once

typedef struct LinkList LinkList;

typedef struct Queue {
  LinkList *list;
  int size;
} Queue;

Queue *createQueue();

void pushQueue(Queue *queue, int val);

int popQueue(Queue *queue);

int sizeQueue(Queue *queue);

void destroyQueue(Queue *queue);