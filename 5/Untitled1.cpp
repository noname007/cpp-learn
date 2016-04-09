
#include<iostream>
using namespace std;


/**
成员对象、基类、派生类构造函数执行的顺序？
A、
先执行成员对象的构造函数，再执行基类的构造函数
B、
先执行基类的构造函数，再执行成员对象的构造函数
C、
先执行派生类自己的构造函数，再执行成员对象的构造函数
D、
先执行派生类自己的构造函数，再执行成员对象的构造函数
*/
class Animal{
public:
    Animal(char * str){
        cout<<"Animal "<<str<<endl;
    }
    Animal(){
        cout<<"没有参数构造函数执行"<<endl;
    }

};

class Cats:Animal{
public:
    Cats():Animal("init Cats"){
        cout<<"Cats"<<endl;
    }
};

class People:public Animal{
public:
    Cats c;
    //People(char * str)
     People():Animal("init people"){
        cout<<"PeoPle"<<endl;
    }
};



int main()
{
    Animal a("animal");
    People p;  //子类不能继承父类的构造方法
    a = p;
    return 0;
}
