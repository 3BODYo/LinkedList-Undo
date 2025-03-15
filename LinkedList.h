#pragma once
#define LINKEDLIST_H
#include <assert.h>
using namespace std;
// Note: I started the position counting from 1 not 0 for better tracking


template <class T>//Node class instead of struct Node
class Node
{
	public:
	Node<T>* next;
	T value;

	Node();
	Node(T val);
};


template <class T>//undo struct to save data of last operation
struct undo {
	string type;
	int at;
	T DeleteValue;//Used only when undo deletion
};


template <class T>
class LinkedList
{
	int count;
	stack < undo<T> > UndoStack;
	Node<T>* head;
	Node<T>* tail;

	//Helping methods of Undo
	void UndoDeleteAt(int pos);
	void UndoInsertAt(int pos, T val);
	void UndoAppend(T value);

public:
	LinkedList();
	int Length();
	T At(int);
	void InsertAt(int,T);
	void Append(T);
	void DeleteAt(int);
	~LinkedList();
	void Undo();
};



//Implementations
template<class T>
Node<T>::Node():next(nullptr),value(0) {
}

template<class T>
Node<T>::Node(T val):value(val),next(nullptr) {
}

template<class T>
LinkedList<T>::LinkedList():head(nullptr),tail(nullptr),count(0) {

}

template<class T>
int LinkedList<T>::Length() {
	return count;
}

template<class T>
T LinkedList<T>::At(int pos) {
	assert(pos>0&&pos<=count);
	Node<T>* n=head;

		for(int i=1;i<pos;i++) {
			n=n->next;
		}

	return n->value;
}

template<class T>
void LinkedList<T>::InsertAt(int pos, T val) {
	if (pos==count+1) {
		this->Append(val);
		return;
	}

	assert(pos>0&&pos<=count);
	undo<T> currentUndo;
	currentUndo.type = "add";
	currentUndo.at = pos;
	UndoStack.push(currentUndo);
	Node<T>* temp = new Node<T>(val);
	Node<T>* n=head;
	if (pos==1) {
		temp->next=n;
		head=temp;
	}else {
		for(int i=1;i<pos-1;i++) {
			n=n->next;
		}
		temp->next=n->next;
		n->next=temp;
	}
	count++;
}


template<class T>
void LinkedList<T>::Append(T value) {
	Node<T>* temp = new Node<T>(value);
	undo<T> currentUndo;
	currentUndo.type = "add";
	currentUndo.at = count+1;
	UndoStack.push(currentUndo);

	if (count==0) {
		head=tail=temp;
	}else{
		tail->next=temp;
		tail=temp;
	}
	count++;

}


template<class T>
void LinkedList<T>::DeleteAt(int pos) {
	assert(pos > 0 && pos <= count);
	Node<T>* del = nullptr;
	undo<T> currentUndo;
	currentUndo.type = "del";
	currentUndo.at = pos;

	if (pos == 1) {
		del = head;
		head = head->next;
	} else {
		Node<T>* n = head;
		for (int i = 1; i < pos - 1; i++) {
			n = n->next;
		}
		del = n->next;
		n->next = del->next;
		if (pos == count) {
			tail = n;
		}
	}

	currentUndo.DeleteValue = del->value;
	UndoStack.push(currentUndo);

	delete del;
	count--;
}


template<class T>
LinkedList<T>::~LinkedList()
{
	while(!UndoStack.empty())
		UndoStack.pop();

	while(count!=0)
		DeleteAt(1);

}


//Undo logic
template<class T>
void LinkedList<T>::Undo() {//Checks last operation saved in the stack
	if (UndoStack.empty()) {
		cout<<"Undo stack is empty make an operation first"<<endl;
	}else if (UndoStack.top().type == "add") {
		UndoDeleteAt(UndoStack.top().at);
		UndoStack.pop();
	}else if (UndoStack.top().type == "del") {
		UndoInsertAt(UndoStack.top().at, UndoStack.top().DeleteValue);
		UndoStack.pop();
	}
}



template<class T>
void LinkedList<T>::UndoDeleteAt(int pos) {//Used to undo insert operations
	assert(pos > 0 && pos <= count);
	Node<T>* del = nullptr;
	if (pos == 1) {
		del = head;
		head = head->next;
	} else {
		Node<T>* n = head;
		for (int i = 1; i < pos - 1; i++) {
			n = n->next;
		}
		del = n->next;
		n->next = del->next;
		if (pos == count) {
			tail = n;
		}
	}
	delete del;
	count--;
}


 template<class T>
void LinkedList<T>::UndoInsertAt(int pos, T val) {//Used to undo delete operations
	if (pos==count+1) {
		UndoAppend(val);
		return;
	}
	assert(pos>0&&pos<=count);
	Node<T>* temp = new Node<T>(val);
	Node<T>* n=head;
	if (pos==1) {
		temp->next=n;
		head=temp;
	}else {
		for(int i=1;i<pos-1;i++) {//
			n=n->next;
		}
		temp->next=n->next;
		n->next=temp;
	}
	count++;
}


template<class T>
void LinkedList<T>::UndoAppend(T value) {//Not necessary but used if undoing deletion at the end of the list
	Node<T>* temp = new Node<T>(value);
	if (count==0) {
		head=tail=temp;
	}else{
		tail->next=temp;
		tail=temp;
	}
	count++;
}