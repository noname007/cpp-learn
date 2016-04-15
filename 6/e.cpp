
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

enum{
    dragon,ninja,iceman,lion,wolf
};
const char * weapon_name[] = { "sword", "bomb","arrow"};
enum WeaponType{sword=0,bomb,arrow,no_weapons};
enum CityFlagColor {red = 0,blue,noFlag };

typedef struct {
    CityFlagColor flagColor;
    int battresult[2] ={0,0};
    int elements;
}City;

City c[20];


class Soilder;
#define WINNER 1
enum BattleResult{Success,Failure,HeJu};
class Weapons{
public:

    WeaponType weapon_type;

    int gongJiLi;

    Weapons(WeaponType weapon);

    bool  is_weapon_baofei();
    void attack(Soilder * oppose);
};

class Soilder{
protected:
    int lifeValue;
    int id;
    int gongJiLi;

    int position;
    Weapons *weapon;

public:
    Soilder(int life,int id,int gongJiLi,int weapon_id);
    ~Soilder();

    BattleResult attack(Soilder * oppose);
    void attack_use_weapon(Soilder * oppose);
    void fanji(Soilder * oppose);

    bool is_alive();
    void minus_life_value(int v);


};



class Group;

/*****************************  Weapons ***************************************/
Weapons::Weapons(WeaponType weapon):weapon_type(weapon){}

bool  Weapons::is_weapon_baofei(){
    return gongJiLi <=0;
}

void Weapons::attack(Soilder * oppose)
{
    if(oppose->is_alive()){
        oppose->minus_life_value(gongJiLi);
    }

    gongJiLi *= 0.8;
}
/*****************************  Weapons ***************************************/

/*****************************  Weapons ***************************************/
class Sword:public Weapons{
public:
    Sword():Weapons(sword){}
};

class Bomb:public Weapons{
public:
    Bomb():Weapons(bomb){}
};

class Arrow:public Weapons{
public:
    Arrow():Weapons(arrow){}
};

/*****************************  Soilder ***************************************/
    Soilder::Soilder(int life,int id,int gongJiLi,int weapon_id):lifeValue(life),id(id),gongJiLi(gongJiLi),position(0){
        switch(weapon_id){

        case sword:
            weapon = new Sword;
            break;
        case arrow:
            weapon = new Arrow;
            break;
        case bomb:
            weapon = new Bomb;
            break;
        case no_weapons:
            break;
       }
    }

    BattleResult Soilder::attack(Soilder * oppose){
        if(oppose->is_alive()){
            oppose->minus_life_value(gongJiLi);
        }
        attack_use_weapon(oppose);

        if(!oppose->is_alive()){
            return Success;
        }

        oppose->fanji(this);

        if(is_alive()){
            return HeJu;
        }

        return Failure;

    }

    void Soilder::attack_use_weapon(Soilder * oppose){
        if(!weapon){
            return ;
        }

        if(weapon->weapon_type == sword){
            weapon->attack(oppose);
            if(weapon->is_weapon_baofei()){
                delete weapon;
                weapon = NULL;
            }
        }
    }

    void Soilder::fanji(Soilder * oppose){

        if(oppose->is_alive()){
            oppose->minus_life_value(gongJiLi>>2);
        }
        attack_use_weapon(oppose);

    }

    bool Soilder::is_alive(){
        return lifeValue > 0;
    }

    void Soilder::minus_life_value(int v){
        lifeValue -= v;
    }

    Soilder::~Soilder(){
        if(weapon)
            delete weapon;
    }
/*****************************  Soilder ***************************************/


/*****************************  Soilder ***************************************/
class Dragon:public Soilder{
    double morale; //士气
public:
    //武器id, 士气 .2f
    Dragon(int life_value,int id,int gongJiLi,int weapon_id, double morale):Soilder(life_value,id,gongJiLi,weapon_id),morale(morale){
        printf("Its morale is %.2f\n",morale);
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

public:
    int shengmingyuan;
    int next_produced_soilder_id_index;//下一个要生产的士兵编号
    int meizhong_soilder_num[5];
    int soilder_total_num;
    char * meizhong_soilder_name[5];
    int * soilder_producted_order;
    char * group_name;
    bool was_taken;
    Soilder * soilders[5];


    Group(int * order,int shengmingyuan,char * group_name);
    void produce_soilder(int consume[] , int timer, int * force);
    int get_next_produced_soilder_id(int consume[]);
    int is_taken();

    void escape();
    void forward_one_step();
    void gallary_element();

    void arrow_attack();
    void bomb_attack();
    void soilder_attack();
    void report_element();
    void report_weapons();
    void check_whether_game_over();
};

Group::Group(int * order,int shengmingyuan,char*group_name):soilder_producted_order(order),group_name(group_name),
                                                        shengmingyuan(shengmingyuan),
                                                        next_produced_soilder_id_index(0),
                                                        meizhong_soilder_num({0,0,0,0,0}),
                                                        soilder_total_num(0),
                                                        meizhong_soilder_name({"dragon","ninja","iceman","lion","wolf"}),
                                                        was_taken(false){

}


int Group::get_next_produced_soilder_id(int consume[]){

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



void Group::produce_soilder(int consume[] ,int timer,int * force){
    if(was_taken){
        return;
    }
    int id = get_next_produced_soilder_id(consume);

    if(id != -1)
    {

        switch(id){
            case dragon:
                printf("%3d:00 %s dragon %d born\b",timer,group_name,soilder_total_num);
                new Dragon(consume[id],soilder_total_num,force[id],soilder_total_num % 3,shengmingyuan/(1.0*consume[id]));

                break;
            case iceman:
               // printf("It has a %s\n",weapon[soilder_total_num % 3]);
                break;
            case wolf:
                break;
            case ninja:
                //printf("It has a %s and a %s\n",weapon[soilder_total_num % 3],weapon[(soilder_total_num + 1) % 3]);
                break;
            case lion:
                printf("It's loyalty is %d\n",shengmingyuan);
                break;
            default:
                break;
        }
    }

}


int Group::is_taken(){
    return was_taken;
}

void Group::escape(){

}

void Group::gallary_element(){

}

void Group::forward_one_step(){

}

void Group::arrow_attack(){

}

void Group::bomb_attack(){

}

void Group::soilder_attack(){
}

void Group::report_element(){
}

void Group::report_weapons(){
}

void Group::check_whether_game_over(){

}


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
            int minutes[] = {5,10,20,30,35,38,40,50,55};
            int m = 0;
            for(int i = 0; i < 9; ++ i){
                m = minutes[i];
                switch(m){
                    case 5:
                        red.escape();
                        blue.escape();
                        break;
                    case 10:
                        red.forward_one_step();
                        blue.forward_one_step();
                        break;
                    case 20:
                        for(int i = 1;i<N+1;++i){
                            c[i].elements += 10;
                        }
                        break;
                    case 30:
                        red.gallary_element();
                        break;
                    case 35:
                        red.arrow_attack();
                        break;
                    case 38:
                        red.bomb_attack();
                        break;
                    case 40:
                        red.soilder_attack();
                        break;
                    case 50:
                        red.report_element();
                        break;
                    case 55:
                        red.report_weapons();
                        break;
                }
            }


            red.check_whether_game_over();


        }

    }

    return 0;
}
