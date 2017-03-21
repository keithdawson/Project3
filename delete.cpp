//Mary Katherine Wesson
//11531006
//Project 3
//#include <iostream>
using namespace std;

class zDepthList {

	typedef struct Node {           //A node for the doubly linked list
		// public:
		int data;
		Node *previous;
		Node *next;
	}Node;

	typedef struct List {           //A special data structure that points to the head and tail nodes of the list.
		// public:
		Node *head;
		Node *tail;
	}List;


public:
	zDepthList();
	zDepthList(int array[], int l);
	void out(const char c);
	void out();
	void move(int i, int n, char c);
	void movefront(int i);
	void moveback(int i);
	int addback();
	int addfront();
	int at(int i);

private:
	List *list;                         //Node in the zDepthList
	//       int list[];                        //The array which holds indices of the list
};

zDepthList :: zDepthList() { //Default constructor
	list->head = 0;
	list->tail = 0;
}

zDepthList :: zDepthList(int array[], int l) {  //Constructor with parameters
	// cout << "The size of the array is: " << l << endl;

	Node **arrayOfPointers[l];
	//arrayOfPointers = new Node*[l];
	for(int m = 0; m < l; ++m) {
		arrayOfPointers[m] = NULL;
	}

	Node *newnode;
	if(l == 0)
		cout << "An array cannot be made with length 'zero' " << endl;

	for(int i = 0; i < l; i++) {
		newnode = new Node;
		newnode->data = array[i];

		if(list->head == 0) {           //If list is empty
			list->head = newnode;       //The head points to the new node
			list->tail = newnode;       //The tail points to the new node
			newnode->previous = 0;      //New node dosn't pont to anything
			newnode->next = 0;
		}

		else {
			newnode->previous = list->tail;     //Since the node is on the end, the new node points to the former end node
			newnode->next = 0;                  //new node points to nothing
			list->tail->next = newnode;         //The former end node points to the new node
			list->tail = newnode;               //The tail points to the new end of the list
		}
	}

}

void zDepthList :: out(const char c) {              //Traverses the list, 'f' for forward, 'r' for reverse
	if(c == 'f') {
		Node *currnode = new Node;
		currnode = list->head;
		while(currnode != 0) {
			cout << currnode->data << " ";
			currnode = currnode->next;
		}
		cout << endl;
	}
	if(c == 'r') {
		Node *currnode = list->tail;
		while(currnode != 0) {
			cout << currnode->data << " ";
			currnode = currnode->previous;
		}
		cout << endl;
	}
}

void zDepthList :: out(){
	Node *currnode = new Node;
	currnode = list->head;
	while(currnode != 0) {
		cout << currnode->data << " ";
		currnode = currnode->next;
	}
	cout << endl;
}



void zDepthList :: move(int i, int n, char c){  //Moves an item in the list: index, number of steps, 'f' or 'r'
	// index = getindex(i);
	Node *currnode = new Node;
	Node *tempnode = new Node;
	currnode = list->head;
	while(currnode != 0){
		if(currnode->data == i){
			//cout << "The index is " << currnode->data << endl;
			tempnode->data = currnode->data;
			if(c == 'f'){
				currnode->previous->next = currnode->next;
				currnode->next->previous = currnode->previous;
				for(int m = 0; m <= n; m++){
					currnode = currnode->next;
					if(m = n){
						currnode = currnode->next;
						tempnode->next = currnode->next;
						currnode->next = tempnode;
						tempnode->previous = currnode;
						currnode = currnode->next;
						currnode->previous = tempnode;


					}
				}


			}
			if(c == 'r'){
				currnode->previous->next = currnode->next;
				currnode->next->previous = currnode->previous;
				for(int p = 0; p <= (i-n); p++){
					currnode = currnode->previous;
					if(p = i - n){
						currnode = currnode->previous;
						tempnode->next = currnode->next;
						currnode->next = tempnode;
						tempnode->previous = currnode;
						currnode = currnode->next;
						currnode->previous = tempnode;
					}

				}
			}
		}
		currnode = currnode->next;
	}
}

void zDepthList :: movefront(int i){
	Node *currnode = new Node;
	Node *tempnode = new Node;
	currnode = list->head;
	while(currnode != 0){
		if(currnode->data == i){
			tempnode->data = currnode->data;
			currnode = list->head;
			tempnode->next = currnode->next;
			currnode->next = tempnode;
			tempnode->previous = list->head;
			currnode = currnode->next;
			currnode->previous = tempnode;
		}
	}

}

void zDepthList :: moveback(int i){

}
int zDepthList :: addback(){}
int zDepthList :: addfront(){}
int zDepthList :: at(int i){}

// void movefront(int i);              //Moves an item at inded 'i' to the front of the list (closest)
//void moveback(int i);               //Moves an item at index 'i' to the back of the list (farthest)
//int at(int i);                      //Returns the index of the item at position 'i' in the zDepthList

//This is a Project3 by Blake Mizzell for CS101 Spring 2017

#include <iostream>

using namespace std;

typedef struct dllnode
{
	int value;
	struct dllnode *prev;

	struct dllnode *next;
} dllnode;

typedef struct dll
{
	dllnode *head;
	dllnode *tail;
	int size;
} dll;

static dll *newDLL();

void insertDLL(dll *items, int index, int value);

int sizeDLL(dll *items) {
	return items->size;
}

class zDepthList {

private:


public:
	zDepthList();
	zDepthList(int [], int);
	//void out(const char);
	//void move(int, int, char);
	//void movefront(int);
	//void moveback(int);
	//int at(int);
	//int addback();
	//int addfront();
};
static dll *list = NULL;

static dll *newDLL() {

	list->head = 0;
	list->tail = 0;
	list->size = 0;
	return list;
}

void insertDLL(dll *items,int index,int value) {
	dllnode *newNode;
	dllnode *curr;
	newNode->value = value;
	//insert at head
	if (index == 0) {
		newNode->prev = NULL;
		newNode->next = items->head;
		//if there is things already in the list
		if (items->head) {
			items->head->prev = newNode;
		}
		items->head = newNode;
		if (items->head->next == NULL)
			items->tail = newNode;
	}
		//insert at end
	else if (index == items->size) {
		if (items->tail)
			items->tail->next = newNode;
		newNode->next = NULL;
		newNode->prev = items->tail;
		items->tail = newNode;
	}
		//insert at index starting from tail
	else if (index > (items->size / 2)) {
		curr = items->tail;
		int i;
		for(i=sizeDLL(items)-index; curr; i--) {
			//break if you reach index
			if (i == 1)
				break;
			curr = curr->prev;
		}
		newNode->next = curr;
		newNode->prev = curr->prev;
		//if there is another thing in the list
		if (curr->prev)
			newNode->prev->next = newNode;
		curr->prev = newNode;
	}
	else {
		curr = items->head;
		int i;
		for(i=index; curr; i--) {
			//break if you reach index
			if (i == 1)
				break;
			curr = curr->next;
		}
		newNode->prev = curr;
		newNode->next = curr->next;
		//if there is another thing in the list
		if (curr->next)
			newNode->next->prev = newNode;
		curr->next = newNode;
	}
	items->size++;
}

zDepthList :: zDepthList() {}
zDepthList :: zDepthList(int a[], int l) {
	dll *list;
	list =  newDLL();
	for (int i=0; i < l; i++){
		insertDLL(list, i, a[i]);
	}
}
void zDepthList :: out(const char c){
	dllnode index;
	if (c != 'r') {
		index = *list->head;
		for (int i = 0; i <= list->size; i++) {
			cout << index.value << endl;
			index = *index.next;
		}
	}
	else if (c == 'r') {
		index = *list->tail;
		for (int i = 0; i <= list->size; i++) {
			cout << index.value << endl;
			index = *index.prev;
		}
	}
}
void zDepthList :: move(int i, int j, const char c){
	dllnode index, previndex, postindex, moverindex;
	index = *list->head;
	for (int k = 0; k < i; k++) {
		index = *index.next;
	}
	moverindex = index;
	previndex = *index.prev;
	previndex.next = index.next;
	postindex = *index.next;
	*postindex.prev = previndex;
	if (c != 'r'){
		for (int k = 0; k < j; k++){
			moverindex = *moverindex.next;
		}
	}
	else if (c == 'r') {
		for (int k = 0; k < j; k++) {
			moverindex = *moverindex.prev;
		}
	}
	index.prev = moverindex.prev;
	*index.next = moverindex;
	previndex = *moverindex.prev;
	*previndex.next = index;
	*moverindex.prev = index;
}


