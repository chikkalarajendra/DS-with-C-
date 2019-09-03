#include<iostream>
using namespace std;
class CQueue{
	private:
		int rear,front,size;
		int *cq;
	public:
		CQueue(int);
		void enqueue(int);
		int dequeue();
		void disp();
};
CQueue::CQueue(int n){
	rear=-1;
	front=-1;
	size=n;
	cq=new int[n];
	for(int i=0;i<n;i++)
		cq[i]=-1;
}
void CQueue::enqueue(int ele){
	if((rear+1)%size==front)
			cout<<"\nCricular Queue Full";
	else if(front==-1){
		front=0;rear=0;
		cq[rear]=ele;
	}
	else if(rear==size-1 && front!=0){
		rear=0;
		cq[rear]=ele;
	}
	else
		cq[++rear]=ele;
}
int CQueue::dequeue(){
	int ele;
	if(front==-1){
		cout<<"\nCircular Queue Empty";
		return -1;
	}
	else if(rear==front){
		ele=cq[rear];
		rear=-1;
		front=-1;
	}
	else if((front+1)%size==0){
		ele=cq[front];
		front=0;
	}
	else{
		ele=cq[front];
		front++;
	}
	return ele;
}
void CQueue::disp() 
{ 
    if (front == -1) 
    { 
        cout<<"\nQueue is Empty"; 
        return; 
    } 
    cout<<"\nElements in Circular Queue are: "; 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            cout<<"\t"<<cq[i]; 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            cout<<"\t"<<cq[i]; 
  
        for (int i = 0; i <= rear; i++) 
            cout<<"\t"<<cq[i]; 
    } 
} 
int main(){
	int n,ele;
	cout<<"Enter the Circular Queue size :";
	cin>>n;
	CQueue q(n);
	int opt;
	while(1){
		cout<<"\n1.enqueue";
		cout<<"\n2.dequeue";
		cout<<"\n3.display";
		cout<<"\n4.Exit";
		cout<<"\nEnter ur option: ";
		cin>>opt;
		switch(opt){
			case 1:cout<<"\nEnter element into Cque: ";
					cin>>ele;
					q.enqueue(ele);
					break;
			case 2:ele=q.dequeue();
					if(ele!=-1)
						cout<<"\nElement deleted from Cque: "<<ele;
					break;
			case 3:cout<<"\nCque elements are:";
					q.disp();
					break;
			case 4:exit(0);
			default:cout<<"\nEnter valid option...";
		}
	}	
}
