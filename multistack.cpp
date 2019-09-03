#include<iostream>
using namespace std;
class MultiStack{
	private:
		int *stck;
		int top1,top2,max;
	public:
		MultiStack(int);
		void push1(int);
		void push2(int);
		int pop1();
		int pop2();
		void disp1();
		void disp2();
};
MultiStack::MultiStack(int n){
	max=n;
	top1=-1;
	top2=max;
	stck=new int[max];
}
void MultiStack::push1(int x){
	if(top1<top2-1){
		top1++;
		stck[top1]=x;
	}
	else{
		cout<<"\nStack Overflow";
		}
}
void MultiStack::push2(int x){
	if(top1<top2-1){
		top2--;
		stck[top2]=x;
	}
	else{
		cout<<"\nStack Overflow";
		}
}
int MultiStack::pop1(){
	int x;
	if(top1>=0){
		x=stck[top1];
		top1--;
		return x;
	}
	else{
		cout<<"\nStack Underflow";
		return -1;
	}
}
int MultiStack::pop2(){
	int x;
	if(top2<max){
		x=stck[top2];
		top2++;
		return x;
	}
	else{
		cout<<"\nStack Underflow";
		return -1;
	}
}
void MultiStack::disp1(){
	int i;
	cout<<"\nStack1 elements from top to down are: ";
	for(i=top1;i>=0;i--)
		cout<<stck[i]<<"\t";
}
void MultiStack::disp2(){
	int i;
	cout<<"\nStack2 elements from top to down are: ";
	for(i=top2;i<max;i++)
		cout<<stck[i]<<"\t";
}
int main(){
	int n,ele,opt;
	cout<<"\nEnter Array Size:";
	cin>>n;
	MultiStack mt(n);
	while(1){
		cout<<"\n1.push1";
		cout<<"\n2.push2";
		cout<<"\n3.pop1";
		cout<<"\n4.pop2";
		cout<<"\n5.display stack1";
		cout<<"\n6.display stack2";
		cout<<"\n7.Exit";
		cout<<"\nEnter ur option: ";
		cin>>opt;
		switch(opt){
			case 1:cout<<"\nEnter element to push into stack1: ";
					cin>>ele;
					mt.push1(ele);
					break;
			case 2:cout<<"\nEnter element to push into stack2: ";
					cin>>ele;
					mt.push2(ele);
					break;
			case 3:ele=mt.pop1();
					if(ele!=-1)
						cout<<"\nElement poped from stack1: "<<ele;
					break;
			case 4:ele=mt.pop2();
					if(ele!=-1)
						cout<<"\nElement poped from stack2: "<<ele;
					break;
			case 5:cout<<"\nStack1 elements are:";
					mt.disp1();
					break;
			case 6:cout<<"\nStack2 elements are:";
					mt.disp2();
					break;
			case 7:exit(0);
			default:cout<<"\nEnter valid option...";
		}
	}
}

