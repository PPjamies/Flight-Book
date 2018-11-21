/*
 * SortedLinkedList.h
 *
 *  Created on: Oct 21, 2018
 *      Author: Pazuz
 */

#ifndef SORTEDLINKEDLIST_H_
#define SORTEDLINKEDLIST_H_
#include <iostream>
#include "LinkedList.h"
#include "Passenger.h"
using namespace std;

template <class T>
class SortedLinkedList: public LinkedList<T>{
	protected:
		int count;
		node<T>* head;
		node<T>* last;
	public:
		SortedLinkedList<T>();
		void add(T&);
		void remove(T&);
		bool find(T&);
		T search(T&);
		void list();
		template <class U>
			friend ostream& operator<<(ostream& os, const SortedLinkedList<U>& list);
};
template <class T>
SortedLinkedList<T>::SortedLinkedList(){	//constructor
	head = last = NULL;
	count = 0;
}

template <class T>
void SortedLinkedList<T>::add(T& item){		//Add node in sorted order
	node<T>* p = head;
	node<T>* temp = p;
	node<T>* newNode = new node<T>;
	newNode->data = item;
	newNode->next = NULL;

	if(head == NULL){	//insert empty list
		head = last = newNode;
		count++;
	}else if(count==1){ //insert list with one node
		if(p->data < item){ //insert last
			p->next = newNode;
			last = newNode;
			count++;
		}else if(p->data > item){//insert front
			newNode->next = p;
			head = newNode;
			count++;
		}
	}else{	//insert list has multiple nodes
		while(p != NULL && p->data < item){
			if(p->next == NULL || p->next->data > item){
				temp = p;
			}
			p = p->next;
		}
		if(p == NULL){	//insert last
			last = newNode;
			temp->next = newNode;
			count++;
		}else{ //insert front
			if(head == p){
				newNode->next = p;
				head = newNode;
			}else{//insert middle
				newNode->next = temp->next;
				temp->next = newNode;
			}
			count++;
		}
	}
}
template <class T>
void SortedLinkedList<T>::remove(T& item){
	node<T>* p = head;
	node<T>* temp = head;

	if(head==NULL){	//delete from empty list
		cout<<"Empty list"<<endl;
	}else{
		while(p!=NULL && p->data < item && p->data != item){
			if(p->next->data == item){	//set temp before moving pointer p
				temp = p;
			}
			p=p->next;
		}
		if(p->data == item){
			if(p==head && p==last){	//delete only node in list
				head = last = NULL;
				delete p;
			}else if(p==head && p!=last){	//delete from front
				head = p->next;
				p->next = NULL;
				delete p;
			}else if(p==last){	//delete from last
				temp->next = NULL;
				last = temp;
				delete p;
			}else{//delete from middle
				temp->next= p->next;
				delete p;
			}
			count--;
			cout<<"The passenger is deleted"<<endl;
		}else{
			cout<<"Passenger not found"<<endl;
		}
	}
}
template <class T>
bool SortedLinkedList<T>::find(T& item){	//returns 1 if item is in list, returns 0 if not
	node<T>* p = head;
	if(p == NULL){
		return 0;
	}else{
		while(p!=NULL && p->data < item){
			p=p->next;
		}
		if(p == NULL){
			return 0;
		}else{
			if(p->data > item){
				return 0;
			}else{
				return 1;
			}
		}
	}
}
template <class T>
T SortedLinkedList<T>::search(T& item){		//searches list for passenger and returns them
	node<T>* p = head;
	while(p!=NULL && p->data < item){
		p=p->next;
	}
	if(p->data == item){
		return p->data;
	}
}
template <class T>
void SortedLinkedList<T>::list(){		//List the passenger's information in a particular format
	node<T>* p = head;
	if(p==NULL){
		cout<<"Empty database"<<endl;
	}else{
		while(p!=NULL){
			cout<< p->data.getFirstName()<< " " << p->data.getLastName() << " [" << p->data.getAddress();
			cout<< "] [+" << p->data.getPhone() << "]" << endl;
			p=p->next;
		}
	}
}
template <class T>
ostream& operator<<(ostream& os, const SortedLinkedList<T>& list){
	node<T>* p = list.head;
	while(p!=NULL){
		os<<p->data<<endl;
		p=p->next;
	}
	return os;
}

#endif /* SORTEDLINKEDLIST_H_ */
