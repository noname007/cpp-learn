
#include<iostream>
#include<cstdio>
using namespace std;
/*
1 testcase
20 M
dragon 、ninja、iceman、lion、wolf
3 4 5 6 7

1
20
3 4 5 6 7

红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。

蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
enum {
//    0,   1     2      3    4
 dragon,ninja,iceman,lion,wolf
};
*/


extern "C" {
    char * redOrderName[5] = {"iceman","lion","wolf","ninja","dragon"};
    int redWushiShengmingMap[5] = {2,3,4,1,0};
    char * blueOrder[] = {"lion","dragon","ninja","iceman","wolf"};
    int blueWushiShengmingMap[5] = {3,0,1,2,4};
}

int main(){
    int consume[5];
    int testCase = 0;
    int M = 0;
    scanf("%d",&testCase);
    int *p = consume;
    for(int order = 1; order<= testCase; ++order)
    {
        scanf("%d",&M);
        scanf("%d%d%d%d%d",p,p+1,p+2,p+3,p+4);

        int is_red_product  = true;
        int is_blue_product = false;


        int timer = 0;

        int red_shengmingyuan = M;
        int red_soilder_bianhao       = 0;
        int red_meizhong_soilder_num[]  = {0,0,0,0,0};
        int red_producted_soilder_order = 0;


        int blue_shengmingyuan = M;
        int blue_soilder_bianhao      = 0;
        int blue_meizhong_soilder_num[] = {0,0,0,0,0};
        int blue_producted_soilder_order = 0;
        //#define red_blue %%s
        //000 red iceman 1 born with strength 5,1 iceman in red headquarter
        while(1){

            if(is_red_product){

                for(int i = 0;i<5;++i)
                {
                    if(red_producted_soilder_order>4){
                        red_producted_soilder_order -= 5;
                    }

                    if(consume[red_producted_soilder_order] < red_shengmingyuan){

                        ++red_producted_soilder_order;
                        break;
                    }

                    ++red_producted_soilder_order;

                }

                printf("%3d red %s %d born with strength %d,%d %s in red headquarter"
                    timer,
                    redOrderName[soilder_order],
                    ++soilder_,
                    ++soilder_id[soilder_order],
                );
            }

            if(is_blue_product){

            }



            printf("%3d %s %s %d born with strength,%d %s in red headquarter"
                timer,

               );


            ++timer
        }


    }


   // cout<<dragon<<endl;
    return 0;
}
