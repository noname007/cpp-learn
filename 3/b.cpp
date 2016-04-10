
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

//#define DEBUG


class Group{
    int shengmingyuan;
    int next_produced_soilder_id_index;//下一个要生产的士兵编号
    int meizhong_soilder_num[5];
    int soilder_total_num;
    int can_produce;
    char * meizhong_soilder_name[5];
    int * soilder_producted_order;
    char * group_name;
public:
    Group(int * order,int shengmingyuan,char*group_name):group_name(group_name),
                                                        shengmingyuan(shengmingyuan),
                                                        next_produced_soilder_id_index(0),
                                                        meizhong_soilder_num({0,0,0,0,0}),
                                                        soilder_total_num(0),
                                                        can_produce(true),
                                                        meizhong_soilder_name({"dragon","ninja","iceman","lion","wolf"})
    {
        #ifdef DEBUG
        //cout<<"=========================================";
        #endif // DEBUG

        soilder_producted_order = order;
    }
    /*
    *
    */
    int get_next_produced_soilder_id(int consume[])
    {
        for(int i = 0; i < 5; ++i)
        {
            if(next_produced_soilder_id_index > 4){
                next_produced_soilder_id_index -= 5;
            }

            int id = soilder_producted_order[next_produced_soilder_id_index];

            ++ next_produced_soilder_id_index;

            if(consume[id] <= shengmingyuan){
                shengmingyuan -= consume[id];
                ++ meizhong_soilder_num[id];
                ++ soilder_total_num;
                return id;
            }
        }

        return -1;
    }
    void produce_soilder(int (&consume)[5] ,int timer)
    {
        if(can_produce){
            can_produce = false;

            int id = get_next_produced_soilder_id(consume);

            if(id == -1){
                can_produce = false;
            }else{
                can_produce = true;
            }


            if(can_produce)
            {
                printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
                    timer,
                    group_name,
                    meizhong_soilder_name[id],
                    soilder_total_num,
                    consume[id],
                    meizhong_soilder_num[id],
                    meizhong_soilder_name[id],
                    group_name
                );
            }else{
                //003 red headquarter stops making warriors
                printf("%03d %s headquarter stops making warriors\n",timer,group_name);
            }
        }
    }

    int can_produced(){
        return can_produce;
    }
};

int main(){
    int consume[5];
    int testCase = 0;

    int M = 0;
    scanf("%d",&testCase);
    int *p = consume;
    #ifdef DEBUG
        freopen("out.txt","w",stdout);
    #endif // DEBUG
    for(int order = 1; order<= testCase; ++order)
    {
        scanf("%d",&M);
        scanf("%d%d%d%d%d",p,p+1,p+2,p+3,p+4);


        printf("Case:%d\n",order);

        int timer = 0;
        int red_order[] = {2,3,4,1,0};
        int blue_order[] ={3,0,1,2,4};
        char red_name[] = "red";
        char blue_name[] = "blue";
        Group red(red_order,M,red_name),blue(blue_order,M,blue_name);

        int red_producted_soilder_order_real_id = 0;

        while(1 && (red.can_produced()||blue.can_produced())){

            red.produce_soilder(consume,timer);
            blue.produce_soilder(consume,timer);
            ++timer;
        }


    }

    return 0;
}
