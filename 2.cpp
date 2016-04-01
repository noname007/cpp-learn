
#include<cstdio>
#include<iostream>


class A {
   int v;   A * next;
   void Func() { }
public:
    int func(int a) { return a * a; }
};

class B  {
   private:  int v;
   public : void Func() { }
};
int main()
{

    class A { public: int v; A * p; };
         A a;  a.p = & a;  return 0;

}
