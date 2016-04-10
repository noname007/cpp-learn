#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt {


/***************************************************************************/
void strrev(char * r){
    int len = strlen(r) - 1;
    for(int i =0;i < len;++i,--len){
        r[i] ^= r[len];
        r[len] ^= r[i];
        r[i] ^= r[len];
    }
}
public:
    char chr[204];

    CHugeInt( char * s)
    {
        memcpy(chr,s,strlen(s)+1);
        //strrev(chr);
    }

    CHugeInt(int v)
    {
        int i =0;
        do{
            chr[i++] = v%10 + '0';
        }while(v /= 10);
        chr[i] = 0;
        strrev(chr);
    }

    CHugeInt operator +(const CHugeInt & b){
           char result[210];
           add(chr,b.chr,result);
           return CHugeInt(result);
    }

    CHugeInt operator + (const int & n){

        CHugeInt t(n);
        return (*this) + t;
    }

    void operator += (const int &n){
       (*this) = (*this) + n;
    }


    CHugeInt& operator ++(){
        (*this) += 1;
        return (*this);
    }
    CHugeInt operator++(int t){
        CHugeInt tt(*this);
        ++(*this);
        return tt;
    }


protected:
    void  add(const char * a,const char *b,char * result){
        int index_a = strlen(a) - 1;
        int index_b = strlen(b) - 1;
        int index_r = 0;

        for(;~index_a && ~index_b; -- index_a, -- index_b){
            result[index_r ++ ] = a[index_a] + b[index_b] - '0';
        }

        while(~index_a){
            result[index_r++] = a[index_a -- ];
        }

        while(~index_b){
            result[index_r++] =  b[index_b --];
        }

        int jinwei = 0;

        for(int i = 0; i < index_r;++i){
                result[i] += jinwei;

                jinwei = 0;
                if(result[i] > '9'){
                        jinwei = 1;
                        result[i] -= 10;
                }
        }

        if(jinwei){
            result[index_r++] = '1';
        }

        result[index_r] = 0;
        strrev(result);
    }
};
    ostream & operator <<(ostream & os,  const CHugeInt & obj){
        os << obj.chr;
        return os;
    }


    CHugeInt operator + (int n,CHugeInt &obj){
        return obj + n;
    }

class tttttttttttt{
/***************************************************************************/




};
int  main()
{
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);
		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
