
#include<iostream>
using namespace std;


/**
��Ա���󡢻��ࡢ�����๹�캯��ִ�е�˳��
A��
��ִ�г�Ա����Ĺ��캯������ִ�л���Ĺ��캯��
B��
��ִ�л���Ĺ��캯������ִ�г�Ա����Ĺ��캯��
C��
��ִ���������Լ��Ĺ��캯������ִ�г�Ա����Ĺ��캯��
D��
��ִ���������Լ��Ĺ��캯������ִ�г�Ա����Ĺ��캯��
*/
class Animal{
public:
    Animal(char * str){
        cout<<"Animal "<<str<<endl;
    }
    Animal(){
        cout<<"û�в������캯��ִ��"<<endl;
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
    People p;  //���಻�ܼ̳и���Ĺ��췽��
    a = p;
    return 0;
}
