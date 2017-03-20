//This is a Project3 by Blake Mizzell for CS101 Spring 2017

#include <iostream>

using namespace std;

typedef struct Node {           //A node for the doubly linked list
	// public:
	int value;
	Node *previous;
	Node *next;
}Node;

typedef struct List {           //A special data structure that points to the head and tail nodes of the list.
	// public:
	Node *head;
	Node *tail;
}List;

class zDepthList {

public:
    zDepthList();
    zDepthList(int array[], int l);
    //void out(const char c);
    //void out();

private:
    List *list;                         //Node in the zDepthList
    Node **listArray;                   //The array which holds indices of the list
};


zDepthList :: zDepthList() {            //Default constructor
    list->head = NULL;
    list->tail = NULL;
}

zDepthList :: zDepthList(int array[], int l) {        //Constructor with parameters
    Node *tempNode, *newNode;
    if(l == 0)
        cout << "An array can't be made with length 'zero' " << endl;

    for(int i = 0; i < l; i++) {
	    newNode = new Node;
	    newNode->value = array[i];
	   // listArray[i] = newNode;       //This is the p art that isn't working
	    if(list->head == 0) {        //If list is empty
		    list->head = newNode;    //The head points to the new node
		    list->tail = newNode;    //The tail points to the new node
		    newNode->previous = 0;   //New node doesn't point to anything
		    newNode->next = 0;
		   }

        else if (1==1){
            newNode->previous = list->tail;     //Since the node is on the end, the new node points to the former end node
            tempNode = list->tail;              //The former end node points to the new node
	        //cout <<tempNode->value;
	        //tempNode->next = newNode;
	        newNode->next = 0;                  //new node points to nothing
            //list->tail = newNode;               //The tail points to the new end of the list
        }
   }

}