#include<iostream>
using namespace std;
template<class T>
class MaxHeap{
	private:
		T *heap;
		int heapsize;
		int num_nodes;
	public:
		MaxHeap(int);
		void readheap();
		void maxheapify();
		void printheap();
		void max_heapfun(int);
};
template<class T>
MaxHeap<T>::MaxHeap(int n){
	heapsize=n;
	heap=new T[heapsize];
	num_nodes=heapsize/2; 
}
template<class T>
void MaxHeap<T>::readheap(){
	cout<<"\nEnter Heap elements:";
	for(int i=1;i<=heapsize;i++){
		cout<<"\nEnter Heap[ "<<i<<" ]: ";
		cin>>heap[i];
	}
}
template<class T>
void MaxHeap<T>::maxheapify(){
	cout<<"\n number of nodes="<<num_nodes;
	for(int i=num_nodes;i>0;i--)
		max_heapfun(i);
}
template<class T>
void MaxHeap<T>::max_heapfun(int i){
	int l,r,big;
	T temp;
	while(i<=num_nodes && i>0){
		l=2*i;
		r=2*i+1;
		if(l<=heapsize && heap[l]>heap[i])
			big=l;
		else
			big=i;
		if(r<=heapsize && heap[r]>heap[big])
			big=r;
		if(i!=big){
			temp=heap[i];
			heap[i]=heap[big];
			heap[big]=temp;
			max_heapfun(big);
		}
		i--;
	}
}
template<class T>
void MaxHeap<T>::printheap(){
	cout<<"\nHeap elements are :";
	for(int i=1;i<=heapsize;i++)
		cout<<" "<<heap[i];
}
int main(){
	int n;
	cout<<"\nEnter heapsize :";
	cin>>n;
	MaxHeap<char> obj(n);
	obj.readheap();
	cout<<"\nHeap elements before sort:";
	obj.printheap();
	obj.maxheapify();
	cout<<"\nHeap elements after sort:";
	obj.printheap();
}
