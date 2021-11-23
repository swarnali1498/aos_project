#include<iostream>
#include <string.h>
#include <vector>
#include<sstream>
#include <iomanip>
#include<map>

using namespace std;

class node{
public:
	int key, value;
	node *prev, *next;
	node(int key,int val): key(key),value(val),prev(NULL),next(NULL){}
};

class DLinkedList{
	node *head, *tail;

	bool empty(){
		return tail==NULL;
	}

	public:
	DLinkedList():head(NULL),tail(NULL){}

	node* add_at_beg(int key, int val){
		node * entry = new node(key,val);

		if(head==NULL && tail==NULL){
			head = tail = entry;
		}
		else{
			head->prev = entry;
			entry->next = head;
			head = entry;
		}
		return entry;
	}

	void update_to_head(node *entry){
		if(entry == head){
			return;
		}
		if (entry != tail) {
			(entry->prev)->next = entry->next;
			(entry->next)->prev = entry->prev;
		}
		else {
			tail = tail->prev;
			tail->next = NULL;
		}
		entry->prev = NULL;
		entry->next = head;
		head->prev= entry;
		head = entry;
	}

	void del_tail(){
		if(empty())
			return;
		if(head==tail){
			delete tail;
			head = tail = NULL;
		}
		else{
			node *n = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete n;
		}
	}


	node *get_tail(){
		return tail;
	}

};


int LRU(int cap, vector<int> token){
	int capacity, size, miss;
	DLinkedList *n;
	map<int, node*> m;
	capacity = cap;
	size=0;
	n = new DLinkedList();
	m = map<int, node*>();
	miss=0;
	int l = token.size();
	for(int i=0;i<l;i++){
		int key = (token[i]);
		int val = (token[i]);
		if(m.find(key)!=m.end()){
			if(m[key]->value!=val){
				miss++;
			}
			m[key]->value = val;
			n->update_to_head(m[key]);
			continue;
		}
		if(size == capacity){
			int i = n->get_tail()->key;
			m.erase(i);
			n->del_tail();
			size--;
		}

		node *entry = n->add_at_beg(key,val);
		size++; miss++;
		m[key]=entry;
	}

// 	for(auto it=m.begin();it!=m.end();it++){
// 		cout<<it->second->value<<" ";
// 	}
	//cout<<"misses: "<<miss<<endl;
	float mr=float(float(miss)/float(l)), hr = float(float(l-miss)/float(l));
	//cout<<"miss ratio: "<<setprecision(2)<<mr<<endl<<"Hit ratio: "<<setprecision(2)<<hr<<endl;
	return miss;
}