#include<iostream>
using namespace std;
template <class T>
class Bag{
	private:
		T *arr;
		int top;
		int osize;
		int isize;
		int k;
	public:
		T element;
		Bag(int);
		bool isEmpty();
		bool isFull();
		void push(T);
		T pop();
		T topEle();
		void disp();
};
template<class T>
Bag<T>::Bag(int n){
	osize=n;
	isize=osize;
	top=-1;
	k=2;
	arr=new T[isize];
}
template<class T>
bool Bag<T>::isEmpty(){
	return(top==-1)?true:false;
}
template<class T>
bool Bag<T>::isFull(){
	if(top+1==isize){
		T *tarr=new T[k*osize];
		isize=k*isize;
		for(int i=0;i<=top;i++)
			tarr[i]=arr[i];
		arr=tarr;
		return true;
	}
	else return false;
}
template<class T>
void Bag<T>::push(T ele){
	if(isFull())
		cout<<"\nBag size increased to "<<k++<<" * times of original size";
	arr[++top]=ele;
}
template<class T>
T Bag<T>::pop(){
	int d;
	T ele;
	if(isEmpty())
		cout<<"\nBag Empty";
	else{
		d=top/2;
		ele=arr[d];
		for(int i=d;i<top;i++)
			arr[i]=arr[i+1];
		top--;
		return ele;
	}
	return -1;
}
template<class T>
T Bag<T>::topEle(){
	return (top!=-1)?arr[top]:-1;
}
template<class T>
void Bag<T>::disp(){
	for(int i=top;i>-1;i--)
		cout<<"\t"<<arr[i];
}
int main(){
	int n;
	cout<<"\nEnter capacity of Bag:";
	cin>>n;
	Bag<char> b(n);
	int opt;
	while(1){
		cout<<"\n1.push";
		cout<<"\n2.pop";
		cout<<"\n3.Top Element";
		cout<<"\n4.display Bag";
		cout<<"\n5.Exit";
		cout<<"\nEnter ur option: ";
		cin>>opt;
		switch(opt){
			case 1:cout<<"\nEnter element to push into bag: ";
					cin>>b.element;
					b.push(b.element);
					break;
			case 2:b.element=b.pop();
					if(b.element!=-1)
						cout<<"\nElement poped from bag: "<<b.element;
					break;
			case 3:b.element=b.topEle();
					if(b.element!=-1)
					
						cout<<"\nElement top in the bag: "<<b.element;
					break;
			case 4:cout<<"\nBag elements are:";
					b.disp();
					break;
			case 5:exit(0);
			default:cout<<"\nEnter valid option...";
		}
	}
}
