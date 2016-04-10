
#include<iostream>
#include<cstdio>
using namespace std;
/*
1 testcase
20 M
dragon 、ninja、iceman、lion、wolf
3 4 5 6 7

2
20
3 4 5 6 7
20
3 4 5 6 7


7
20
3 4 5 6 7
40
3 14 5 6 7
30
40 50 60 70 80
100
10 20 30 40 50
400
20 3 300 60 98
1000
332 90 47 8989 83
5000
200 400 6 70 20

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
    char * blueOrderName[] = {"lion","dragon","ninja","iceman","wolf"};
    int blueWushiShengmingMap[5] = {3,0,1,2,4};
}

int main(){
    int consume[5];
    int testCase = 0;

    int M = 0;
    scanf("%d",&testCase);
    int *p = consume;
    //freopen("out.txt","w",stdout);
    for(int order = 1; order<= testCase; ++order)
    {
        scanf("%d",&M);
        scanf("%d%d%d%d%d",p,p+1,p+2,p+3,p+4);


        printf("Case:%d\n",order);

        int timer = 0;

        int red_shengmingyuan = M;
        int red_soilder_bianhao       = 0;
        int red_meizhong_soilder_num[]  = {0,0,0,0,0};
        int red_producted_soilder_order = 0;
        int is_red_product  = true;

        int is_blue_product = true;
        int blue_shengmingyuan = M;
        int blue_soilder_bianhao      = 0;
        int blue_meizhong_soilder_num[] = {0,0,0,0,0};
        int blue_producted_soilder_order = 0;

        int red_producted_soilder_order_real_id = 0;
        //#define red_blue %%s
        //000 red iceman 1 born with strength 5,1 iceman in red headquarter
        while(1 && (is_red_product||is_blue_product)){

            if(is_red_product){
                is_red_product = false;
                for(int i = 0; i < 5; ++i)
                {
                    if(red_producted_soilder_order>4){
                        red_producted_soilder_order -= 5;
                    }
                    red_producted_soilder_order_real_id = redWushiShengmingMap[red_producted_soilder_order];
                    //printf("===========>>>%d,%d\n",consume[red_producted_soilder_order_real_id],red_shengmingyuan);
                    if(consume[red_producted_soilder_order_real_id] <= red_shengmingyuan){
                        red_shengmingyuan -= consume[red_producted_soilder_order_real_id];
                        ++ red_meizhong_soilder_num[red_producted_soilder_order_real_id];
                        is_red_product = true;
                        //++red_producted_soilder_order;
                        break;
                    }

                    ++red_producted_soilder_order;

                }
                if(is_red_product)
                {
                    printf("%03d red %s %d born with strength %d,%d %s in red headquarter\n",
                        timer,
                        redOrderName[red_producted_soilder_order],
                        ++red_soilder_bianhao,
                        consume[red_producted_soilder_order_real_id],
                        red_meizhong_soilder_num[red_producted_soilder_order_real_id],
                        redOrderName[red_producted_soilder_order]
                    );
                    ++red_producted_soilder_order;
                }else{
                    //003 red headquarter stops making warriors
                    printf("%03d red headquarter stops making warriors\n",timer);
                }
            }

            if(is_blue_product){
                is_blue_product = false;
                for(int i = 0; i < 5; ++i)
                {
                    if(blue_producted_soilder_order>4){
                        blue_producted_soilder_order -= 5;
                    }
                    red_producted_soilder_order_real_id = blueWushiShengmingMap[blue_producted_soilder_order];
                    //printf("===========>>>%d,%d\n",consume[red_producted_soilder_order_real_id],red_shengmingyuan);
                    if(consume[red_producted_soilder_order_real_id] <= blue_shengmingyuan){
                        blue_shengmingyuan -= consume[red_producted_soilder_order_real_id];
                        ++ blue_meizhong_soilder_num[red_producted_soilder_order_real_id];
                        is_blue_product = true;
                        //++red_producted_soilder_order;
                        break;
                    }

                    ++blue_producted_soilder_order;

                }
                if(is_blue_product)
                {
                    printf("%03d blue %s %d born with strength %d,%d %s in blue headquarter\n",
                        timer,
                        blueOrderName[blue_producted_soilder_order],
                        ++blue_soilder_bianhao,
                        consume[red_producted_soilder_order_real_id],
                        blue_meizhong_soilder_num[red_producted_soilder_order_real_id],
                        blueOrderName[blue_producted_soilder_order]
                    );
                    ++blue_producted_soilder_order;
                }else{
                    //003 red headquarter stops making warriors
                    printf("%03d blue headquarter stops making warriors\n",timer);
                }
            }

            ++timer;
        }


    }


   // cout<<dragon<<endl;
    return 0;
}
