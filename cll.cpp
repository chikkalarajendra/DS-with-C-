#include<iostream>
using namespace std;
template<class T>
class node{
	public:
		T data;
		node *next;
};
template<class T>
class cll{
	private:
		node<T> *first,*last;
		int inc;
	public:
		cll();
		void addnode();
		void insertfnode();
		void dispnode();
		int deletenode();
};
template<class T>
cll<T>::cll(){
	first=NULL;
	last=first;
}
template<class T>
void cll<T>::addnode(){
	node<T> *temp;
	T n;
	temp=new node<T>;
	if(temp==NULL)
		cout<<"\nMemory not allocated...";
	else{
		cout<<"\nEnter value :";
		cin>>n;
		temp->data=n;
		temp->next=NULL;
		if(first==NULL){
			first=temp;
			temp->next=temp;
			last=first;
		}
		else{
			temp->next=last->next;
			last->next=temp;
			last=last->next;
		}
	}
}
template<class T>
void cll<T>::insertfnode(){
	node<T> *temp;
	T n;
	temp=new node<T>;
	if(temp==NULL)
		cout<<"\nMemory not allocated..";
	else{
		cout<<"\nEnter value to insert in front :";
		cin>>n;
		temp->data=n;
		temp->next=NULL;
		if(first==NULL){
			temp->next=temp;
			first=temp;
			last=temp;
		}
		else{
			temp->next=first;
			first=temp;
			last->next=temp;
		}
	}
	
}
template<class T>
void cll<T>::dispnode(){
	node<T> *temp;
	temp=first;
	cout<<"\nElements are :";
	do{
		cout<<"\t"<<temp->data;
		temp=temp->next;
	}while(temp!=first);
}
int main(){
	cll<int> obj;
	obj.addnode();
	obj.addnode();
	obj.addnode();
	obj.dispnode();
	obj.insertfnode();
	obj.insertfnode();
	obj.dispnode();
	return 0;
}
