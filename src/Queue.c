#include "Queue.h"
#include "LinkList.h"
#include <stdlib.h>

Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->list = createLinkList();
  return queue;
}

void pushQueue(Queue *queue, int val) {
  if (!queue) {
    return;
  }
  pushLinkList(queue->list, val);
}

int popQueue(Queue *queue) { return popFirstLinkList(queue->list); }

int sizeQueue(Queue *queue) { return queue->list->size; }

void destroyQueue(Queue *queue) {
  destroyLinkList(queue->list);
  free(queue);
}