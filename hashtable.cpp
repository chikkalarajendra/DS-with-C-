#include<iostream>
using namespace std;
class node{
	public:
	int value;
	node *next;
};
class HTI{
	public:	
		node *hashtable[100];
		int hts;
		HTI(int bkt){
			hts=bkt;
			for(int i=0;i<hts;i++)
				hashtable[i]=NULL;
		}
		void menu();
		void addnode();
		int searchnode(int);
		void printlist(node *n);
		void printhashtable();
		void deletenode(int);
};

void HTI::menu(){
	cout<<"\n1.Add Node";
	cout<<"\n2.Search Node";
	cout<<"\n3.Delete Node";
	cout<<"\n4.Display Nodes";
	cout<<"\nAny Other Key for Exit";
}
void HTI::addnode(){
	int key,ele;
	node *n1,*n2;
	n1=new node();
	cout<<"\nEnter data :";
	cin>>ele;
	n1->value=ele;
	n1->next=NULL;
	key=ele%hts;
	if(hashtable[key]==NULL)
		hashtable[key]=n1;
	else{
		for(n2=hashtable[key];n2->next!=NULL;n2=n2->next);
			n2->next=n1;
	}
}
int HTI::searchnode(int data){
	int key=data%hts;
	node *n;
	for(n=hashtable[key];n!=NULL;n=n->next)
		if(n->value==data)
			return key;
	return -1;
}
void HTI::printlist(node *n){
	node *n1;
	for(n1=n;n1!=NULL;n1=n1->next)
		cout<<" "<<n1->value;
}
void HTI::printhashtable(){
	for(int i=0;i<hts;i++){
		cout<<"\nhashtable[ "<<i<<" ]:";
		printlist(hashtable[i]);
		cout<<"\n";
	}
}
void HTI::deletenode(int data){
	int key=data%hts;
	node *n1,*n2;
	if(hashtable[key]->value==data){
		n1=hashtable[key];
		hashtable[key]=hashtable[key]->next;
		delete(n1);
		return;
	}
	for(n1=hashtable[key];n1->next!=NULL;n1=n1->next){
		n2=n1->next;
		if(n2->value==data){
			n1->next=n2->next;
			delete(n2);
			break;
		}
	}
}
int main(){
	int data;
	int f,opt;
	int bucket;
	cout<<"\nEnter Bucket size :";
	cin>>bucket;
	HTI obj(bucket);
	obj.menu();
	cout<<"\nEnter option :";
	cin>>opt;
	while(opt==1||opt==2||opt==3||opt==4){
		if(opt==1)
			obj.addnode();
		else if(opt==2){
			cout<<"\nEnter Data to search :";
			cin>>data;
			f=obj.searchnode(data);
			if(f==-1)
				cout<<"\n Node doesn't exists";
			else{
				cout<<"\nNode exists in:"<<f<<" ";
				obj.printlist(obj.hashtable[f]);
			}
		}
		else if(opt==3){
			cout<<"\nEnter node to delete :";
			cin>>data;
			f=obj.searchnode(data);
			if(f==-1)
				cout<<"\n Node doesn't exists";
			else
				obj.deletenode(data);
		}
		else if(opt==4)
			obj.printhashtable();
		obj.menu();
		cout<<"\nEnter ur option:";
		cin>>opt;
	}
}
