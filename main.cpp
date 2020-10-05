#include <iostream>
#include "SortedLinkedList.h"
#include "ItemType.h"

using namespace std;


int main(int argc, char ** argv) {
  if(argc != 2)
    {
      cout << "Wrong command-line input" << endl;
      return -1;
    }
  fstream fs;
  fs.open(argv[1]);
  SortedLinkedList list;
  int streamInt;
  while(fs >> streamInt)
    {
      ItemType temp;
      temp.initialize(streamInt);
      list.insertItem(temp);
    }
  
  fs.close();

  cout << argv[0] << " " << argv[1] << " Commands:" << endl;
  cout << "(i) - Insert value " << endl;
  cout << "(d) - Delete value" << endl;
  cout << "(s) - Search Value" << endl;
  cout << "(n) - Print next iterator value" << endl;
  cout << "(r) - Reset iterator" << endl;
  cout << "(p) - Print list" << endl;
  cout << "(l) - Print length" << endl;
  cout << "(q) - Quit program" << endl;
  while(true) {
    cout << "Enter a command: ";
    char inp;
    cin >> inp;

    if(inp == 'i')
      {
	list.printList();
	cout << "Enter number: ";
	int itemp;
	cin >> itemp;
	ItemType temp;
	temp.initialize(itemp);
	if(list.searchItem(temp) == -1)
	  list.insertItem(temp);
	else cout << "Sorry. You cannot insert the duplicate item." << endl;
	list.printList();
      }
    else if(inp == 'd')
      {
	list.printList();
	cout << "Enter value to delete: ";
	int itemp;
	cin >> itemp;
	ItemType temp;
	temp.initialize(itemp);
	if(list.length() == 0)
	  cout <<"You cannot delete from an empty list." << endl;
	else if(list.searchItem(temp) != -1)
	  list.deleteItem(temp);
	else cout << "Item not found" << endl;
	list.printList();
      }
    else if(inp == 's')
      {
	cout << "Enter a value to search: ";
	int itemp;
	cin >> itemp;
	ItemType temp;
	temp.initialize(itemp);
	if(list.searchItem(temp) == -1)
	  cout << "Item not found " << endl;
	else cout << "Index " << list.searchItem(temp) << endl;
      }
    else if(inp == 'n')
      {
	if(list.length() == 0)
	  {
	    cout << "List is empty" << endl;
	  }
	else
	  cout << list.GetNextItem().getValue() << endl;
      }
    else if(inp == 'r')
      {
	cout << "Iterator reset." << endl;
	list.ResetList();
      }
    else if(inp == 'p')
      {
	//	list.ResetList();
	//	for(int i = 0; i < list.length(); i++)
	//	  {
	//	    cout << list.GetNextItem().getValue() << " ";
	//	  }
	list.printList();
      }
    else if(inp == 'l')
      {
	cout << "List Length is " <<  list.length() << endl;
      }
    else if(inp == 'q')
      {
	return 0;
      }
    else
      cout << "Invalid command, try again!" << endl;
  }  
  return 0;
	  
}
