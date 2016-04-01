
#include<iostream>
using namespace std;

class T{

private:
    int _id;
public:
    static int idddd;

    int v;
    T(int a);

    T(const T &a){
        _id = 0;
        v = a.v + 1;
        cout<<this->_id<<"copy constructor called"<<endl;
    }
    ~T(){
         _id = 0;
        cout<<this->_id<<"  destructor was called "<<endl;
    }

};
T::T(int a)
{
       // idddd = 0;
        //this->_id = idddd;
        v = a;
        cout<<this->_id<<" constructor called "<<endl;
}


T test1()
{

    T  a(4);
    return a;
}

void test2(T b)
{


}


int main()
{
cout<<"test1====复制构造函数========"<<endl;
    cout<<"test1().v:"<<test1().v<<endl;
cout<<"test2====复制构造函数========"<<endl;
    T t(3);
    test2(t);

cout<<"test3====复制构造函数========"<<endl;
    T t3(t);
    T t4 = t3;

cout<<"test4====类型构造函数======="<<endl;
    t4 = 5;
    cout<<t4.v<<endl;
    return 0;
}
