#include<iostream>
#include<conio.h>
using namespace std;
class Polynomial{
	private:
		int cf[20];
		int degree;
	public:
		Polynomial();
		void create();
		void add(Polynomial a,Polynomial b);
		void disp();
};
Polynomial::Polynomial(){
	int i;
	degree=0;
	for(i=0;i<20;i++)
		cf[i]=0;
}
void Polynomial::create(){
	int i;
	cout<<"\nEnter degree of equation:";
	cin>>degree;
	for(i=degree;i>-1;i--){
		cout<<"Enter Coefficient for exponent "<<i<<" = ";
		cin>>cf[i];
	}
}
void Polynomial::add(Polynomial p,Polynomial q){
	int m,n,i;
	m=p.degree;
	n=q.degree;
	if(m>=n)
		degree=m;
	else
		degree=n;
	for(i=degree;i>-1;i--)
		cf[i]=p.cf[i]+q.cf[i];
}
void Polynomial::disp(){
	for(int i=degree;i>-1;i--){
		cout<<cf[i]<<" x^"<<i;
		if(cf[i-1]<0)
			continue;
		else if(i>0)
			cout<<" + ";
	}
	cout<<"\n";
}
int main(){
	Polynomial p1,p2,p3;
	cout<<"\nFirst Equation = ";
	p1.create();
	cout<<"\nSecond Equation = ";
	p2.create();
	cout<<"\nFirst Equation = ";
	p1.disp();
	cout<<"\nSecond Equation = ";
	p2.disp();
	p3.add(p1,p2);
	cout<<"\nAfter Adding Equation is= ";
	p3.disp();
	return 0;
}
