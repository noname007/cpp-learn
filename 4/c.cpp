#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
/*********************************************/
    int mem[3][4] ;
    int row,col;
    int pos ;
public:
    Array2(int row,int col):row(row),col(col){


    }
    Array2(){
    }
    // 这里出现了mem 第二维的指针可以在类外函数中访问，有点问题
    int *  operator[](int row){

        return mem[row];
    }
    int operator()(int row,int col){
        return mem[row][col];
        //cout<<mem[row][col]<<endl;
    }

/*********************************************/

};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
