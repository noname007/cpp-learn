#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//class Parent{
//
//};
//class Son:public Parent{
//};

class MyString:public string
{

    /*************************************************/

public:
    MyString(){}
//
    MyString(const char* str):string(str){}

//    MyString(const MyString & str):string(str){}
    MyString(const string &str):string(str){
    }

    const char * operator()(int start, int len){
     return   substr(start,len).c_str();
    }
//
//    MyString & operator =(string & str){
//        this->string::operator=(str);
//        return *this;
//    }
//
//    MyString & operator =(MyString & str){
//        this->string::operator=(str);
//        return *this;
//    }
//
//    MyString operator +(const string& str){
//        MyString t(str);
//        return t;
//    }
////
//    MyString & operator =(Parent & a){
//
//    }
//    MyString & operator =(Son &b){
//    }



    /*************************************************/

};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
//	s1�Ĵ��±�0��ʼ����Ϊ4���Ӵ�
	cout << s1(0,4) << endl;
//	s1�Ĵ��±�5��ʼ����Ϊ10���Ӵ�
	cout << s1(5,10) << endl;
	return 0;
}