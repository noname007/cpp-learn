#include <iostream>
#include <cstdio>
using namespace std;

class B{
public:
	B(){
		cout<<"B constructor"<<endl;
	}
	~B(){
		cout<<"B destructor"<<endl;
	}
};

class A{
public:
	int a;
	B *b;
	A(){
		a = 11111111;
		cout<<"constructor"<<endl;
		b = new B;
	}
	~A(){
		delete b;
		cout<<"destructor"<<endl;
	}
	void Heeeee(){
		cout<<"hhhhhhhhhhhhhhhhhhhh"<<endl;
	}

	void print_this(){
		printf("%x\n",this);
		// printf("%x\n",&this); //error
	}
	void deletedd(){
		delete this;
	}
};

int main(){
	// A * a = new A;
	// A * &b = a;
	// A *a = new A,* &b = a;
	A *a = new A,* b = a;
	A c;
	printf("%x\n",a);
	printf("%x\n",b);
	printf("%x\n",&a);
	printf("%x\n",&b);
	cout<<"================================="<<endl;
	cout<<b->a<<endl;
	cout<<a->a<<endl;
	b->deletedd();
	// b = NULL;
	// if(b){
	// 	cout<<"b========dfadfa"<<endl;
	// }
	//c.deletedd();
	// delete b;
	cout<<"================================="<<endl;
	printf("%x\n",a);
	printf("%x\n",b);
	printf("%x\n",&a);
	printf("%x\n",&b);
	b->print_this();
	cout<<b->a<<endl;
	cout<<a->a<<endl;
	a->Heeeee();
	b->Heeeee();

}