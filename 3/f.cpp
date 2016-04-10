
#include <iostream>
#include<cstdio>

using namespace std;
class Base {
public:
    int k;
    int v;
    Base(int n):k(n),v(n*20) { }
};

class Big  {
public:
    int v; Base b;
/***********************/
Big(int n):v(n),b(n){}
/***********************/

};
int main()  {
    Big a1(5);    Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;

    printf("%p %p\n",&(a1.b),&(a2.b));
    //printf("%p %p\n",(&(a1.b))->v,&(a2.b));
    return 0;
}
