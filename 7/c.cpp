
#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{

    /********************My Answer****************************/
    T v[100];
    int index;
public:

    CMyistream_iterator(istream &is){
        cin>>v[0];
        index = 1;
    }

    void operator++(int){

        cin>>v[index++];
    }
    //friend template<class T1> bool operator *(T1 & i);
    T operator *(){

        return v[index-1];
    }
};
//    template<class T>
//    bool operator *(T & i){
//
//    }

class TTTTTTTTT{
    /*********************************************************/
};


int main()
{
	int t;
	cin >> t;
	while( t -- ) {
		 CMyistream_iterator<int> inputInt(cin);
		 int n1,n2,n3;
		 n1 = * inputInt; //���� n1
		 int tmp = * inputInt;
		 cout << tmp << endl;
		 inputInt ++;
		 n2 = * inputInt; //���� n2
		 inputInt ++;
		 n3 = * inputInt; //���� n3
		 cout << n1 << " " << n2<< " " << n3 << " ";
		 CMyistream_iterator<string> inputStr(cin);
		 string s1,s2;
		 s1 = * inputStr;
		 inputStr ++;
		 s2 = * inputStr;
		 cout << s1 << " " << s2 << endl;
	}
	 return 0;
}
