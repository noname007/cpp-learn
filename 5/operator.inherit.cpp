
#include<iostream>
using namespace std;
class T{
public:

    int a;
    T():a(23){}

};
//重载覆盖隐藏   http://blog.chinaunix.net/uid-20750677-id-1878267.html
//四个基本构造函数
//继承与多态
class Parent{
public :
    int a;
    Parent(int v = 0){
        cout<<"parent constructor:"<<v<<&a<<endl;
        a = v;
    }

    Parent & operator = (int v){
        a = v;
        return (*this);
    }

    Parent & operator =(Parent & p){
        cout<<"copy assignment constructor"<<endl;
        a = p.a;
        return (*this);
    }

    Parent & operator = (T& t){
        cout<<t.a<<endl;;
    }

    int operator<<(int a){
        t_f();
        cout<<"<< operator overload param:"<<a<<endl;
    }

    virtual int t_f(){
        cout<<"==============parent===================="<<endl;
    }

    ~Parent(){
        cout<<"a:"<<a<<endl;
    }
};
class Son:public Parent{

public:

    Son(int v=0):Parent(){
        cout<<"Son Constructor=========="<<&a<<endl;
        a = v + 1;
    }
//    int operator<<(int a){
//        t_f();
//        cout<<"<< operator overload param:"<<a<<endl;
//    }
    int t_f(){
        cout<<"========================son============"<<endl;
    }

};



int main(){
    Parent p;
    Son s1(4),s2(5);
    p<<2;

    s1<<2;


    //s1 = ((Parent)6);
    //s1= 6;
   s1 = s2;

   T t;
   p = 2;

    //cout<<p.a<<endl<<s1.a<<endl;
    return 0;
}
