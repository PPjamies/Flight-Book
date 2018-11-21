/*
 * LinkedList.h
 *
 *  Created on: Oct 22, 2018
 *      Author: Pazuz
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node* next;
};

template <class T>
class LinkedList{
	private:
		LinkedList(const LinkedList&)=delete; //copy constructor
	protected:
		int count;
		node<T> *head;
		node<T> *last;
	public:
		LinkedList();	//constructor
		bool isEmpty();
		int length();
		T front();
		T back();
		void inserFirst(T&);
		void inserLast(T&);
		T search(T&);
		void deleteNode(T&);
		void destroylist();
		virtual void copylist(LinkedList<T>&);
		virtual LinkedList<T>& operator=(LinkedList<T>&);	//assignment operator
		template <class U>
			friend ostream& operator<<(ostream& os, LinkedList<U>& list);
			virtual~LinkedList();	//destructor
};
//***************************************************************************************************************************************************//
template <class T>
LinkedList<T>::LinkedList(){
	head = last = NULL;
	count = 0;
}

template <class T>
bool LinkedList<T>::isEmpty(){
	return head == NULL;
}

template <class T>
int LinkedList<T>::length(){
	return count;
}

template <class T>
T LinkedList<T>::front(){
	return head->data;
}

template <class T>
T LinkedList<T>::back(){
	return last->data;
}
//***************************************************************************************************************************************************//
//Inserts a new node in front of LinkedList
template <class T>
void LinkedList<T>::inserFirst(T& item){
	node<T> *temp = new node<T>;
	temp->data = item;
	temp->next = head;
	head = temp;
	count++;
	if(last==NULL)
		last = temp;
}

//Inserts a new node to the back of LinkedList
template <class T>
void LinkedList<T>::inserLast(T& item){
	node<T> *newnode = new node<T>;
	newnode->data = item;
	newnode->next = NULL;
	if(head==NULL){
		head = last = newnode;
	}else{
		last->next = newnode;
		last = newnode;
	}
	count++;
}
//****************************************************************************************************************************************************//
template <class T>
T LinkedList<T>::search(T& item){
	if(head == NULL){
		cerr<<"empty list";
	}else{
		node<T>* p = head;
		while(p != NULL && p->data != item){
			p = p->next;
		}
		if(p==NULL){
			cerr<<"item not found";
		}else{
			return p->data;
		}
	}
}
//***************************************************************************************************************************************************//
template <class T>
void LinkedList<T>::deleteNode(T& item){
	if(head == NULL)
		cerr<<"null";
	else{
		if(head->data == item){
			node<T>* p = head;
			head = head->next;
			delete p;
			count--;
			if(head==NULL)
				last = NULL;
		}else{
			node<T>* p = head;
			node<T>* q = p->next;
			while(q!=NULL && q->data != item){
				p = q;
				q = q->next;
			}
			if(q == NULL){
				cerr<<"null";
			}else{
				p->next = q->next;
				count--;
				if(q->next == NULL)
					last = p;
				delete q;
			}
		}
	}
}
//***************************************************************************************************************************************************//
template<class T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &list) {
	if (this != &list) {
		copylist(list);
	}
	return *this;
}
//Deep Copy of LinkedList
template <class T>
void LinkedList<T>::copylist(LinkedList<T>& other){
	node<T>* p = head;
	if(head != NULL){	//non-empty list
		destroylist();
	}
	node<T>* q = other.head;
	node<T>* newNode = new node<T>;
	newNode->data = q->data;
	newNode->next = NULL;
	count = other.count;
	p = head = newNode;
	while(q!=NULL){
		q=q->next;
		node<T>* temp = new node<T>;
		temp->data = q->data;
		p->next = temp;
		p=p->next;
	}
	p->next = NULL;
	last = p;
}
template <class T>
ostream& operator<<(ostream& os, LinkedList<T>& list){
	node<T> *p = list.head;
	while(p!= NULL){
		os<< p->data <<" "<<endl;
		p = p->next;
	}
	return os;
}
//***************************************************************************************************************************************************//
template <class T>
void LinkedList<T>::destroylist(){
	node<T> *p;
	while(head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}
template <class T>
LinkedList<T>::~LinkedList(){
	destroylist();
}

#endif /* LINKEDLIST_H_ */
