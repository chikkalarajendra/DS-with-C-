#include<iostream>
using namespace std;
template<class T>
class node{
	public:
		int count;
		T data;
		node *next,*prev;
};
template<class T>
class Doublell{
	private:
		node<T> *head;
		int inc;
	public:
		Doublell();
		void addnode();
		void insertnode();
		void dispnode();
		int deletenode();
};
template<class T>
Doublell<T>::Doublell(){
	inc=0;
	head=new node<T>;
	head->count=inc;
	head->next=NULL;
	head->prev=NULL;
}
template<class T>
void Doublell<T>::addnode(){
	T n;
	node<T> *temp,*cur;
	cout<<"\nEnter data into the node :";
	cin>>n;
	head->count=++inc;
	temp=new node<T>;
	if(temp!=NULL){
		temp->data=n;
		temp->next=NULL;
		temp->prev=NULL;
	}
	else
		cout<<"\nMemory not allocated";
	cur=head;
	while(cur->next!=NULL)
		cur=cur->next;
	cur->next=temp;
	temp->prev=cur;
}
template<class T>
void Doublell<T>::dispnode(){
	node<T> *temp;
	temp=head;
	cout<<"\nList elements are :";
	cout<<"\t"<<temp->count;
	temp=temp->next;
	while(temp!=NULL){
		cout<<"\t"<<temp->data;
		temp=temp->next;
	}
}
template<class T>
void Doublell<T>::insertnode(){
	node<T> *temp,*temp1,*cur;
	T n;
	int pos;
	cout<<"\nEnter position :";
	cin>>pos;
	if(pos>inc || inc==0)
		cout<<"\nInsertion  means in middle...";
	else{
		temp=new node<T>;
		if(temp==NULL)
			cout<<"\nMemory not allocated";
		else{
			cout<<"\nEnter data to be inserted :";
			cin>>n;
			head->count=++inc;
			temp->data=n;
			temp->next=NULL;
			temp->prev=NULL;
		}
		cur=head;
		int i=0;
		while(cur!=NULL && i<pos-1){
				cur=cur->next;
				i++;
			}
		temp1=cur->next;
		temp1->prev=temp;
		temp->prev=cur;
		temp->next=cur->next;
		cur->next=temp;
	}	
}
template<class T>
int Doublell<T>::deletenode(){
	node<T> *cur,*temp,*temp1;
	int f=0;
	T n;
	cout<<"\nEnter node to be deleted :";
	cin>>n;
	cur=head->next;
	while(cur!=NULL){
		if(cur->data==n && cur->next!=NULL){
			head->count=--inc;
			temp=cur->prev;
			temp1=cur->next;
			temp->next=cur->next;
			temp1->prev=cur->prev;
			delete cur;
			f=1;
		}
		else if(cur->data==n && cur->next==NULL){
			head->count=--inc;
			temp=cur->prev;
			temp->next=cur->next;
			delete cur;
			f=1;
		}
		cur=cur->next;
	}
	return f;
}
int main(){
	Doublell<char> d;
	int opt,f;
	while(1){
		cout<<"\n1.Add node";
		cout<<"\n2.Insert node";
		cout<<"\n3.Delete node";
		cout<<"\n4.Display nodes";
		cout<<"\n5.exit";
		cout<<"\nEnter ur option :";
		cin>>opt;
		switch(opt){
			case 1:d.addnode();
					cout<<"\nNode added...";
					break;
			case 2:d.insertnode();
					cout<<"\nnode inserted...";
					break;
			case 3:f=d.deletenode();
					if(f==1)
						cout<<"\nnode deleted...";
					else
						cout<<"\nnode not found...";
					break;
			case 4:d.dispnode();
					break;
			case 5:exit(0);
			default:cout<<"\nEnter valid option...";
		}
	}
}
