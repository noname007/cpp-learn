#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define PLog(desc) printf("\n\n---%s:%d =============>>>> %s\n\n",__FILE__,__LINE__,desc);


int p_min(int a,int b)
{

    printf("%d\n",a < b?a:b);
}

int p_max(int a,int b)
{
    printf("%d\n",a<b?b:a);
}

int cmp(const void * a ,const void * b)
{
    return *((int *)a) - *((int *)b);

}


class CSample{
    int x;
    int y;
public:
    CSample(){
        cout<<"Constructor 1 called"<<endl;
    }
    CSample(int a){
        x = a;
        cout<<"Constructor 2 called a = " << a <<endl;
    }
    CSample(int a,int b)
    {

        x = a;
        y = b;
        cout<<"Constructor 3 called x = "<< x <<" y = "<<y<<endl;
    }
};




int main(int argc,char * argv[])
{

    printf("\n\n============function pointer test====================>>>\n");
    p_min(1,2);
    int (*fp)(int ,int) = p_min;
    fp(1,2);
    fp = p_max;
    fp(1,2);

    int s[] ={1,4,3,6,7,8,3,2,1,3,1000,23,4,5,66,77,22,3,444,5555};
    qsort(s,10,sizeof(s[0]),cmp);

    for(int i = 0 ;i < 11; ++i)
    {

        printf("%d ",s[i]);
    }

    printf("\n\n===============cmd argument==========================>>>\n");

    for(int i = 0; i< argc;++i)
    {
        printf("param:%d value: %s\n",i,argv[i]);
    }

    PLog("wei yun suan ");
    /**
     *
     *
        &
            n & 0xffffff00 �Ͱ�λ����
            x & (1 << n) ��nλ��ֵ�Ƿ�Ϊ1 ��0��ʼ��
                         ��nλ��ֵ(x >> n) && 1

        |
        ^   ���  ȡ��Ч��
        ~   ��
        >>  ����  x << n ====== x * 2^n
        <<  ����  x >> n ====== floor(x/(2^n))
     *
     */

    printf("%d",1<<0);






    PLog("Constructor");

    CSample array1[2];
    CSample array2[2] = {4,5};

    CSample array3[2] = {3};
    cout<<"pointer new ========>>>>>>>"<<endl;

    CSample * array4 = new CSample[2];
    cout <<"Constructor have more than 1 arguments "<<endl;

    CSample array5[3] = {1,CSample(2,3)};
    CSample array6[3] = {CSample(4,5),1,CSample(6,7)};
    CSample array7[] = {CSample(4,5),1,CSample(6,7)};

    CSample *pArray[] = {new CSample(8),new CSample(9,10)};
    CSample *pArray1[3] = {new CSample(8),new CSample(9,10)};

    delete [] pArray1;
    delete [] pArray;
    delete [] array4;
    return 0;
}
