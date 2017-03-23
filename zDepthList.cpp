//This is a Project3 by Blake Mizzell for CS101 Spring 2017

#include <iostream>
using namespace std;

/*typedef struct List {           //A special data structure that points to the head and tail nodes of the list.
	// public:
	Node *head;
	Node *tail;
}List;*/

class zDepthList {

	typedef struct Node {           //A Node for the doubly linked list
		// public:
		int value;
		Node *prev;
		Node *next;
	}Node;

public:
    zDepthList();
    zDepthList(int array[], int l);
    void out(const char c);
    void out();
	void move(int i, int j, char c);
	void move(int i, int j);
	void movefront(int i);
	void moveback(int i);
	int addback();
	int addfront();
	int at(int i);

private:
    int listLength;
	Node *head, *tail;      //Node in the zDepthList
    int listIndexer[];                   //The array which holds indices of the list
};

zDepthList :: zDepthList() {            //Default constructor
    head = NULL;
    tail = NULL;
}

zDepthList :: zDepthList(int array[], int l) {        //Constructor with parameters
    Node *nNode;
	listLength = l;
    if(l == 0)
        cout << "An array of 0 length can't be made." << endl;

    for(int i = 0; i < l; i++) {
	    nNode = new Node;
	    nNode->value = array[i];
		nNode->next = NULL;
		cout<<nNode->value;
	    if ( i < l ) listIndexer[i] = i;      //Which is the index of the spot that [i] exists within the length of the linked list
	    if(i==0) {        //If list is empty
		    head = nNode;    //The head points  to the new Node
		    tail = nNode;    //The tail points to the new Node
		    nNode->prev = NULL;   //New Node doesn't point to anything
			//cout << tail->value <<' ';
		   }

        else if (1==1){
			nNode->prev = tail;     	//Since the Node is on the end, the new Node points to the former end Node
			nNode->next = 0;			//new Node points to nothing
			tail->next = nNode;			//The former end Node points to the new
	        tail = nNode;				//The tail points to the new end of the list

        }
   }
}

void zDepthList :: out(const char c) {
	Node *currentNode;
	if ( c != 'r'){
		currentNode = head;
		//cout << currentNode->value << ' ';
		for (int i = 0; i < listLength; i++) {
			//currentNode = currentNode->next;
			//cout << currentNode->value << ' ';
		}
		cout << endl;
	}

	/* (c == 'r'){
		cout<< "testr ";
		currentNode = tail;
		cout << currentNode->value << ' ';
		for (int i = 0; i < listLength; i++){
			currentNode = currentNode->prev;
			cout << currentNode->value << ' ';
		}
		cout << endl;
	}*/
}

void zDepthList :: out() {
/*	Node *currentNode = new Node;
	currentNode = head;
	cout << currentNode->value << ' ';
	for (int i = 0; i < listLength; i++) {
		currentNode = currentNode->next;
		cout << currentNode->value << ' ';
	}
	cout << endl;*/
}
void zDepthList :: move(int i, int j, const char c) {
	/*Node *holdIndex = new Node, *indexNode = new Node, *nextIndex = new Node, *prevIndex = new Node;
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
	nextIndex->prev = holdIndex;*/

}
void zDepthList :: move(int i, int j){}
void zDepthList :: movefront(int i){}
void zDepthList :: moveback(int i){}
int zDepthList :: addback(){}
int zDepthList :: addfront(){}
int zDepthList :: at(int i){}