#include <iostream>
using namespace std;
class Point {
	private:
		int x;
		int y;
	public:
		Point() { };
    /****************************/
    friend istream & operator>> (istream& is,Point & p);
    friend ostream & operator<< (ostream& os,const Point & p);
};
    istream & operator >> (istream& is, Point & p){
//        string s;
//        is >> s;
//        int pos = s.find(" ",0);
//        string sTemp =s.substr(0,pos) ;
//        p.x = atoi(sTemp.c_str());
//        p.y = atoi(s.substr(pos,s.length()-pos-2).c_str() );
        int a,b;
        is>>a>>b;
 //       cout<<a<<b<<endl;
        p.x =a;
        p.y = b;
        return is;
    }

    ostream & operator << (ostream& os,const Point & p){
        os<<p.x<<","<<p.y;
        return os;
    }
class ttttttttttttt{



    /****************************/
};




int main()
{
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}
