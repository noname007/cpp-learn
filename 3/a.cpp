#include<iostream>
#include<cstdio>
using namespace std;

//http://www.cnblogs.com/ComputerG/archive/2011/02/22/1961383.html
//http://iask.sina.com.cn/b/12778015.html


//test case
//Tom,18,7817,80,80,90,70
class Student{

    char name[1000];
    int age;
    int grad1,grad2,grad3,grad4;
    char Id[1000];
public:
    void input()
    {

        //scanf("%s,%d,%s,%d,%d,%d,%d",name,&age,Id,&grad1,&grad2,&grad3,&grad4);

        //http://baike.baidu.com/view/1390039.htm
        scanf("%[^,],%d,%[^,],%d,%d,%d,%d",name,&age,Id,&grad1,&grad2,&grad3,&grad4);
        //cout<<grad1<<","<<grad2<<","<<grad3<<","<<grad4<<endl;
        //cout>>name>>endl;
       // cout<<name<<endl;
        //printf("%s",name);
       // printf("%d",age);
        //cout>>this->name>>endl;
        //cout>>age>>endl;
        //cin>> >> "," >>age>> "," >>Id>> "," >>grad1>> "," >>grad2>> "," >>grad3>> "," >>grad4;

        //string temp;
        //cin>>temp;
       // int pos1 = temp.find(',');
        //while()
       // cout<<pos<<endl;
        //name = temp.substr(0,pos1);
       // pos2 = temp.find(pos1,',')
       // age

    }
    void output(){
        int avg = (grad1+grad2+grad3+grad4)/4 ;
        cout << name << ',' << age << ',' << Id << ',' << avg<< endl;
    }

};

int main(){
    Student s;
    s.input();
    s.output();
    return 0;
}


