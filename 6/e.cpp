
#include<iostream>
#include<cstdio>
using namespace std;

enum{
    dragon,ninja,iceman,lion,wolf
};
const char * weapon_name[] = { "sword", "bomb","arrow"};
enum {sword=0,bomb,arrow,no_weapons};
enum CityFlagColor {red = 0,blue,noFlag };

typedef struct {
    CityFlagColor flagColor;
    int battresult[2] ={0,0};
}City;

City c[20];

class Soilder;
class Weapons;
class Group;

class Weapons{
    int gongJiLi;
   // virtual attack();
   // virtual fanji();
};

class Sword:public Weapons{

};

class Bomb:public Weapons{

};

class Arrow:public Weapons{

};


class Soilder{
    int lifeValue;
    int id;
    int gongJiLi;

    int position;
    Weapons *weapon;
public:
    Soilder(int life,int id,int gongJiLi,int weapon_id):life(life),id(id),gongJiLi(gongJiLi),position(0){
        switch(weapon_id){

        case sword:
            weapon = new Sword();
            break;
        case arrow:
            weapon = new Arrow();
            break;
        case bomb:
            weapon = new Bomb;
            break;
        case no_weapons:
            break;
       }
    }
   // virtual attack();
 //   virtual fanji();
};

class Dragon:public Soilder{
    double morale; //士气
public:
    //武器id, 士气 .2f
    Dragon(int life_value,int id,int gongJiLi,int weapon_id, double morale):Soilder(life_value,id,gongJiLi,weapon_id),morale(morale),{

    }
};

class Ninja:public Soilder{

};

class Iceman:public Soilder{
};


class Lion:public Soilder{

};

class Wolf:public Soilder{

};


class Group{
    int shengmingyuan;
    int next_produced_soilder_id_index;//下一个要生产的士兵编号
    int meizhong_soilder_num[5];
    int soilder_total_num;
    char * meizhong_soilder_name[5];
    int * soilder_producted_order;
    char * group_name;
    bool was_taken;
public:
    Group(int * order,int shengmingyuan,char*group_name):soilder_producted_order(order),group_name(group_name),
                                                        shengmingyuan(shengmingyuan),
                                                        next_produced_soilder_id_index(0),
                                                        meizhong_soilder_num({0,0,0,0,0}),
                                                        soilder_total_num(0),
                                                        meizhong_soilder_name({"dragon","ninja","iceman","lion","wolf"}),
                                                        was_taken(false)
    {

    }
    /*
    *
    */
    int get_next_produced_soilder_id(int consume[])
    {

        if(next_produced_soilder_id_index > 4){
            next_produced_soilder_id_index -= 5;
        }

        int id = soilder_producted_order[next_produced_soilder_id_index];

        if(consume[id] <= shengmingyuan){
            ++ next_produced_soilder_id_index;
            shengmingyuan -= consume[id];
            ++ meizhong_soilder_num[id];
            ++ soilder_total_num;
            return id;
        }


        return -1;
    }

    void produce_soilder(int (&consume)[5] ,int timer,int * force)
    {
        if(was_taken){
            return;
        }
        int id = get_next_produced_soilder_id(consume);

        if(id != -1)
        {

            switch(id){
                case dragon:
                    //It has a arrow,and it's morale is 3.67
                    //printf("It has a %s,and it's morale is %.2f\n",weapon[],);
                    new Dragon(consume[id],soilder_total_num,force[id],soilder_total_num % 3,round(shengmingyuan/(1.0*consume[id])));
                    break;
                case iceman:
                    printf("It has a %s\n",weapon[soilder_total_num % 3]);
                    break;
                case wolf:
                    break;
                case ninja:
                    printf("It has a %s and a %s\n",weapon[soilder_total_num % 3],weapon[(soilder_total_num + 1) % 3]);
                    break;
                case lion:
                    printf("It's loyalty is %d\n",shengmingyuan);
                    break;
                default:
                    break;
            }
        }

    }

    int is_taken(){
        return was_taken;
    }
};

int main(){
    int consume[5],force[5];
    int testCase = 0;

    int M = 0,N,R,K,T;
    scanf("%d",&testCase);
    int *p = consume;
    int *f = force;

    //freopen("out.txt","w",stdout);

    for(int order = 1; order<= testCase; ++order)
    {
        scanf("%d%d%d%d%d",&M,&N,&R,&K,&T);
        scanf("%d%d%d%d%d",p,p+1,p+2,p+3,p+4);
        scanf("%d%d%d%d%d",f,f+1,f+2,f+3,f+4);
        memset(c,0,sizeof(City)*20);
        printf("Case:%d\n",order);

        int timer = 0;
        int red_order[] =  {iceman,lion,wolf,ninja,dragon};//{2,3,4,1,0};
        int blue_order[] ={lion,dragon,ninja,iceman,wolf};//{3,0,1,2,4};
        char red_name[] = "red";
        char blue_name[] = "blue";
        Group red(red_order,M,red_name),blue(blue_order,M,blue_name);

        int red_producted_soilder_order_real_id = 0;

        while(timer < T && !red.is_taken() && !blue.is_taken()){

            red.produce_soilder(consume,timer,force);
            blue.produce_soilder(consume,timer,force);

            switch(timer){
            case 5:
                break;
            case 10:
                break;
            case 20:
                break;
            case 30:
                break;
            case 35:
                break;
            case 38:
                break;
            case 40:
                break;
            case 50:
                break;
            case 55:
                break;
            }
        }

    }

    return 0;
}
