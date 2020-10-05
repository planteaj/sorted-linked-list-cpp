#include "SortedLinkedList.h"
#include "ItemType.h"
#include <iostream>

SortedLinkedList::SortedLinkedList(){
  head = NULL;
}

SortedLinkedList::~SortedLinkedList()
{
  ListNode* temp;

  while ( head != NULL)
    {
      temp = head;
      head = head->next;
      delete temp;
    }
}

int SortedLinkedList::length() const{
  ListNode * tmp;
  tmp = head;
  int l = 0;
  while(tmp != NULL)
    {
      l++;
      tmp = tmp->next;
    }
  return l;
}

void SortedLinkedList::insertItem(ItemType item)
{
  ListNode* newNode;
  ListNode* oldNode;
  ListNode* current;
  bool search;

  current = head;
  oldNode = NULL;
  search = (current != NULL);

  while(search){
    switch(item.compareTo(current->item))
      {
      case GREATER: oldNode = current;
	current = current -> next;
	search = (current != NULL);
	break;
      case LESS: search = false;
	break;
      }
  }

  newNode = new ListNode;
  newNode ->item = item;

  if(oldNode == NULL)
    {
      newNode ->next = head;
      head = newNode;
    }
  else
    {
      newNode -> next = current;
      oldNode ->next = newNode;
    }
  currentPos = head;
}


void SortedLinkedList::deleteItem(ItemType item)
{
  ListNode * current = head;
  ListNode * tempLoc;

  if (item.compareTo(head->item) == EQUAL)
    {
      tempLoc = current;
      head = head->next;
    }

  else
    {
      while (item.compareTo(current->next->item) !=EQUAL)
	current = current->next;

      tempLoc = current->next;
      current -> next = (current->next)->next;
    }
  delete tempLoc;
  currentPos = head;
}


int SortedLinkedList::searchItem(ItemType item)
{
  bool search;
  ListNode* current;
  int index = 0;
  current = head;
  search = (current != NULL);
  bool found = false;
  while(search && !found)
    {
      switch(item.compareTo(current->item))
	{
	case GREATER:
	  current = current->next;
	  search = (current!=NULL);
	  index ++;
	  break;
	case EQUAL:
	  found = true;
	  return index;
	  break;
	case LESS:
	  search = false;
	  break;
	}
    }
  return -1;
}

ItemType SortedLinkedList::GetNextItem()
{
  ItemType item;

  if(currentPos == NULL)
    currentPos = head;
  item = currentPos->item;
  currentPos = currentPos -> next;
  return item;

}

void SortedLinkedList::ResetList()
{
  currentPos = NULL;
}

void SortedLinkedList::printList()
{
  ListNode * tmp;
  tmp = head;
  while(tmp != NULL)
    {
      std::cout << tmp->item.getValue() << " ";
      tmp = tmp->next;
    }
  std::cout <<"\n";
}
