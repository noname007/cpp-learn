
#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s)
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;

}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{

    /********************My Answer****************************/
//    #define ARR_BUF_SIZE 10000//
//    typedef int  arr_size_t;
    char * s;
    int len ;
public:
//    MyString(){}
    MyString (const char * str = NULL){

        len = strlen(str);
        if(len){
            s = new char[len + 1];
            strcpy(s,str);
        }else{
            s = NULL;
        }
    }
    MyString(const MyString& str){

        len = str.len;

        if(len){
            s = new char[str.len + 1];
            strcpy(s,str.c_str());
        }else{
            s = NULL;
        }

    }

    MyString & operator=(const MyString& str){
        if(str.c_str() == s){
            return (*this);
        }

        delete [] s;
        s = new char[str.length()+1];
        strcpy(s,str.c_str());
        return (*this);
    }

    MyString& operator=(const char* str){
        len = strlen(str);
        if(len){
            delete [] s;
            s = new char[len + 1];
            strcpy(s,str);
        }else{
            s = NULL;
        }
    }

    MyString operator + (const MyString &str){
        if(str.len <= 0){
            return MyString(*this);
        }

        char * s1 = new char[str.len + len + 1];
        strcpy(s1,s);
        strcat(s1,str.c_str());
        delete [] s;
        s = s1;
        return MyString(s);
    }

    int operator >(const MyString & str) const{
        return strcmp(s,str.c_str()) > 0;
    }
    int operator <(const MyString & str){
        return  str > (*this);
    }
    int operator == (const MyString &str){
        return  !((*this) > str) && !(str > (*this));
    }

    char & operator[](int index){
        return *(s + index);
    }

    MyString & operator +=(const char*str){
        (*this) + MyString(str);
        return (*this);
    }

    const char * c_str() const{
        return s;
    }
    int length() const{
        return len;
    }
};
ostream &operator <<(ostream &os,const MyString & str){
    os<<str.c_str();
    return os;
}

class tfdasfdklafkajk{
    /*********************************************************/
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
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}
