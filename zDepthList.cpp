#include <iostream>

using namespace std;

typedef struct dllnode
{
	void *value;
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

void insertDLL(dll *items, int index, void *value);

int sizeDLL(dll *items) {
	return items->size;
}

class zDepthList {

private:



public:
	zDepthList();
	zDepthList(int [], int);
	void out(const char);
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

void insertDLL(dll *items,int index,void *value) {
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
		insertDLL(list, i, &a[l]);
	}
}
void zDepthList :: out(const char c){
	if (c == 'f') {
		dllnode index;
		index = *list->head;
		for (int i = 0; i <= list->size; i++) {
			cout << index.value;
			index = *index.next;
		}
	}
	else if (c == 'r') {
		dllnode index;
		index = *list->tail;
		for (int i = 0; i <= list->size; i++) {
			cout << index.value;
			index = *index.prev;
		}
	}
}



