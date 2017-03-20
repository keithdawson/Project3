//This is a Project3 by Blake Mizzell for CS101 Spring 2017

#include <iostream>

using namespace std;

typedef struct Node {           //A node for the doubly linked list
	// public:
	int value = NULL;
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
    int listIndexer[];                   //The array which holds indices of the list
};

zDepthList :: zDepthList() {            //Default constructor
    list->head = NULL;
    list->tail = NULL;
}

zDepthList :: zDepthList(int array[], int l) {        //Constructor with parameters
    Node *tempNode, *nextNode;
    if(l == 0)
        cout << "An array of 0 length can't be made." << endl;

    for(int i = 0; i < l; i++) {
	    nextNode = new Node;
	    nextNode->value = array[i];
	    listIndexer[i] = i;      //Which is the index of the spot that [i] exists within the length of the linked list
	    if(list->head == 0) {        //If list is empty
		    list->head = nextNode;    //The head points to the new node
		    list->tail = nextNode;    //The tail points to the new node
		    nextNode->previous = 0;   //New node doesn't point to anything
		    nextNode->next = 0;
		   }

        else if (1==1){
            nextNode->previous = list->tail;     //Since the node is on the end, the new node points to the former end node
            tempNode = list->tail;              //The former end node points to the new node
	        //if (i == 0 ){cout <<tempNode->value;}
	        tempNode->next = nextNode;
	        nextNode->next = 0;                  //new node points to nothing
            //list->tail = nextNode;               //The tail points to the new end of the list
        }
   }

}