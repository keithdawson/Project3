//This is a Project3 by Blake Mizzell for CS101 Spring 2017

#include <iostream>
using namespace std;

/*typedef struct List {           //A special data structure that points to the head and tail nodes of the list.
	// public:
	Node *head;
	Node *tail;
}List;*/
typedef struct Node {           //A node for the doubly linked list
	// public:
	int value = NULL;
	Node *prev;
	Node *next;
}Node;

class zDepthList {

public:
    zDepthList();
    zDepthList(int array[], int l);
    //void out(const char c);
    //void out();

private:
    Node list/*used for temporary node access*/, *head, *tail;      //Node in the zDepthList
    int listIndexer[];                   //The array which holds indices of the list
};

zDepthList :: zDepthList() {            //Default constructor
    head = NULL;
    tail = NULL;
}

zDepthList :: zDepthList(int array[], int l) {        //Constructor with parameters
    Node *nNode, *tempNode;
    if(l == 0)
        cout << "An array of 0 length can't be made." << endl;

    for(int i = 0; i < l; i++) {
	    nNode = new Node;
	    nNode->value = array[i];
	    listIndexer[i] = i;      //Which is the index of the spot that [i] exists within the length of the linked list
	    if(head == NULL) {        //If list is empty
		    head  = nNode;    //The head points to the new node
		    tail  = nNode;    //The tail points to the new node
		    nNode->prev = 0;   //New node doesn't point to anything
		    nNode->next = 0;
		   }

        else if (1==1){
            nNode->prev = tail;     	//Since the node is on the end, the new node points to the former end node
			nNode->next = 0;			//The former end node points to the new node
	        tail->next = nNode;			//new node points to nothing
	        tail = nNode;
                      //The tail points to the new end of the list
        }
   }

}