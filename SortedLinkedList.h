#include "ItemType.h"
#include "ListNode.h"

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

class SortedLinkedList
{
 public:
  SortedLinkedList();
  ~SortedLinkedList();

  int length() const;
  void insertItem(ItemType item);
  void deleteItem(ItemType item);
  int searchItem(ItemType item);
  ItemType GetNextItem();
  void ResetList();
  void printList();
 private:
  ListNode *head;
  ListNode * currentPos;
};

#endif
