#include <iostream>
#include<cstdio>
using namespace std;
class A {
public:
    int val;

/*****************************/
    A():val(0){
    }

    A(int v){
        val = v;
        cout<<"type converter constructor"<<endl;
    }

    A(const A & a){

        cout<<"copy constructor "<<endl;
    }

    A& GetObj(){

        return *this;
    }
    //如果有下面的 =运算符重载则无法使用类型转换构造函数
    //A& operator=(A& a)
    //{

      //  cout<<"= was called"<<endl;
       // return *this;
    //}
/*****************************/





};
int main()  {
    A a;
    A b(1),c(b);
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
    a = 6;
    cout << a.val << endl;

    cout<<a.GetObj().val<<endl;

    printf("%x %x\n",(int)&c,(int)&b);
    b = c;
    printf("%x %x\n",(int)&c,(int)&b);
}
