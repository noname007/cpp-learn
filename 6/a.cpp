
#include <iostream>
using namespace std;
class B {
	private:
		int nBVal;
	public:
		void Print()
		{ cout << "nBVal="<< nBVal << endl; }
		void Fun()
		{cout << "B::Fun" << endl; }
		B ( int n ) { nBVal = n;}
};

    /********************My Answer****************************/
class D:public B{
public:
    int nDVal;
    void Fun(){
        cout<<"D::Fun"<<endl;
    }
    void Print(){
        B::Print();
        cout<<"nDVal="<<nDVal<<endl;
    }
    D(int n):nDVal(n),B(n*3){}
};
    /*********************************************************/


int main() {
	B * pb; D * pd;
	D d(4); d.Fun();
	pb = new B(2); pd = new D(8);
	pb -> Fun(); pd->Fun();
	pb->Print (); pd->Print ();
	pb = & d; pb->Fun();
	pb->Print();
	return 0;
}
