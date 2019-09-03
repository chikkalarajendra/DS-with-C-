#include<iostream>
using namespace std;
template<class T>
class Stack{
	private:
		T *stk;
		int top;
		int size;
	public:
		T element;
		Stack(int);
		void push(T);
		T pop();
		T istop();
		void peep();
};
template<class T>
Stack<T>::Stack(int n){
	top=-1;
	size=n;
	stk=new T[size];
}
template<class T>
void Stack<T>::push(T ele){
	if(top<size-1)
		stk[++top]=ele;
	else
		cout<<"\nStack Overflow";
}
template<class T>
T Stack<T>::pop(){
	if(top<0)
		cout<<"\nStack Underflow";
	else
		return stk[top--];
	return -1;
}
template<class T>
T Stack<T>::istop(){
	if(top!=-1)
		return stk[top];
	return -1;
}
template<class T>
void Stack<T>::peep(){
	for(int i=top;i>=0;i--)
		cout<<"\t"<<stk[i];
}
int main(){
	int n;
	cout<<"Enter the stack size :";
	cin>>n;
	Stack<int> s(n);
	int opt;
	while(1){
		cout<<"\n1.push";
		cout<<"\n2.pop";
		cout<<"\n3.top";
		cout<<"\n4.peep";
		cout<<"\n5.Exit";
		cout<<"\nEnter ur option: ";
		cin>>opt;
		switch(opt){
			case 1:cout<<"\nEnter element to push into stack: ";
					cin>>s.element;
					s.push(s.element);
					break;
			case 2:s.element=s.pop();
					if(s.element!=-1)
						cout<<"\nElement poped from stack: "<<s.element;
					break;
			case 3:s.element=s.istop();
					if(s.element!=-1)
						cout<<"\nTop Element of stack: "<<s.element;
					break;
			case 4:cout<<"\nStack elements are:";
					s.peep();
					break;
			case 5:exit(0);
			default:cout<<"\nEnter valid option...";
		}
	}
}
