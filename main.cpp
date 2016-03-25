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

    return 0;
}
