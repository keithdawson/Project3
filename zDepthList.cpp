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
	int value;
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
    int listLength;
	Node *head = new Node, *tail = new Node;      //Node in the zDepthList
    int listIndexer[];                   //The array which holds indices of the list
};

zDepthList :: zDepthList() {            //Default constructor
    head = NULL;
    tail = NULL;
}

zDepthList :: zDepthList(int array[], int l) {        //Constructor with parameters
    Node *nNode, *tempNode;
	listLength = l;
    if(l == 0)
        cout << "An array of 0 length can't be made." << endl;

    for(int i = 0; i <= l; i++) {
	    nNode = new Node;
	    nNode->value = array[i];
	    cout << tail->value;
	    if ( i != l ) listIndexer[i] = i;      //Which is the index of the spot that [i] exists within the length of the linked list
	    cout <<" ind " <<listIndexer[i];
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

void zDepthList :: out(const char c) {
	Node *currentNode = new Node;
	if ( c != 'r'){
		currentNode = head;
		cout << currentNode->value << ' ';
		for (int i = 0; i < listLength; i++) {
			currentNode = currentNode->next;
			cout << currentNode->value << ' ';
		}
		cout << endl;
	}
	if (c == 'r'){
		currentNode = tail;
		cout << currentNode->value << ' ';
		for (int i = 0; i < listLength; i++){
			currentNode = currentNode->prev;
			cout << currentNode->value;
		}
		cout << endl;
	}
}

void zDepthList :: out() {
	Node *indexNode = new Node;
	currentNode = head;
	cout << currentNode->value << ' ';
	for (int i = 0; i < listLength; i++) {
		currentNode = currentNode->next;
		cout << currentNode->value << ' ';
	}
	cout << endl;
}
void zDepthList :: move(int i, int j, const char c) {
	Node *holdIndex = new Node, *indexNode = new Node, *nextIndex = new Node, *prevIndex = new Node;
	indexNode = head;
	int location;
	location = listIndexer[i];
	for (int k=0; k < location; k++ ){
		indexNode = indexNode->next;
	}
	holdIndex = indexNode;
	prevIndex = indexNode->prev;
	nextIndex = indexNode->next;
	nextIndex->prev = prevIndex;
	prevIndex->next = nextIndex;
	if (c != 'r'){
		for (int k = 0; k < j; k++){
			indexNode = indexNode->next;
		}
	}
	if (c == 'r'){
		for (int k = 0; k < j; k++){
			indexNode = indexNode->prev;
		}
	}
	else cout << "Invalid char entry"<<endl;
	nextIndex = indexNode->next;
	indexNode->next = holdIndex;
	nextIndex->prev = holdIndex;

}