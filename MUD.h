#ifndef MUD_H
#define MUD_H
#include<vector>
#include<string>
#include<ctime>
#include<iostream>
#include<fstream>
using namespace std;

class Role {
	protected:
		string name;
		double MHP;
        double NHP;           //当前生命值
		double Wealth;        //玩家表示拥有的金币，怪物表示死后掉落的金币
		double ATK;           //攻击力
		double Dodge;         //闪避
		bool isToxic = false;         //玩家表示中毒与否 ，怪物表示能否让玩家中毒
        double magicDamage = 0;   //法术伤害
        double experience = 0;    //玩家表示该等级的当前经验值，怪物表示死后奖励给玩家的经验值
        bool isdead = false;       

	public:
        Role(string name,double ATK,double MHP):name(name),ATK(ATK),MHP(MHP),NHP(MHP),Dodge(0),Wealth(0){}
		Role(string name):
                name(name),MHP(100),NHP(100),Wealth(200),ATK(10),Dodge(0){}

        double& getExperience(){return experience;}
        double& getWealth(){return Wealth;} 
        bool& istoxic(){return isToxic;}  
        bool& isDead(){return isdead;}
        double& getATK(){return ATK;}
        double& getNHP(){return NHP;}
        double& getMHP(){return MHP;}
        double& getMD(){return magicDamage;}
        string getName(){return name;}
        void refresh(){
            NHP = MHP;
            isdead = false;
        }   //战斗结束后玩家复原属性
        void showFightInfo();         
        virtual ~Role() = 0;                //虚基类
};

class Monster;
class Player;

class Goods{                        //物品基类
    protected:
        string name;
        double price;
        enum Type{weapons,armors,drugs};//枚举以区分表示物品类型
        int type;//具体的类型
    public:
        Goods(string name,int type,double price = 0):name(name),price(price),type(type){}

        double getPrice(){return price;}
        string getName(){return name;}
        int getType(){return type;}
        void soldBy(Player& p);
        void picked(Player* p);

        virtual void useTo(Player* p) = 0;
        virtual void show() = 0;
};

class Weapons: public Goods{
    private:
        double ATK;                 //攻击加成
        string magicName;           //法术名称
        double magicDamage;          //法术伤害
    public:
        Weapons(string name, int type, double atk, double price = 0, string mName = " ", 
                double mDamage = 0):
                Goods(name,type,price),
                ATK(atk),magicName(mName),magicDamage(mDamage){}

        double getATK(){return ATK;}
        double getMD(){return magicDamage;}
        void useTo(Player* p); //被角色使用

        void show();  //显示属性      
};

class Armors: public Goods{
    private:
        double HP;//生命值加成
        double physicalExsistance;//物理抗性
        double dodge; //闪避
    public:
        Armors(string name,int type,double Hp, double PE, double price = 0, double dodge = 0):
                Goods(name,type,price),HP(Hp),physicalExsistance(PE),dodge(dodge){}

        void useTo(Player* p); //被角色使用 
        double getHP(){return HP;}
        double getPE(){return physicalExsistance;}
        double getDodge(){return dodge;}

        void show();  //显示属性

};

class Drugs:public Goods{
    private:
        enum Type{life,madness,cleansing,holy};//药剂四种类型：生命，狂暴，净化，圣灵
                            //分别为生命＋20，攻击+15，消除异常状态（中毒），免疫异常状态5回合
        int typeOfDrug;
        int num = 1;
    public:
        Drugs(string name,int type,int typeOfdrug,double price = 0):
            Goods(name,type,price),typeOfDrug(typeOfdrug){}

        void useTo(Player* p);  //被角色使用
        int getTypeOfDrug(){return typeOfDrug;}
        int& getNum(){return num;}

        void show();  //展示功效
};

class Player: public Role{           //玩家类
    private:
        int level; 
        int fame = 0;     
        vector<Goods*> weaponsBag;          //背包武器栏
        vector<Goods*> armorsBag;           //背包防具栏
        vector<Goods*>  drugsBag = {
            new Drugs("生命药剂", drugs, life, 50),
            new Drugs("狂暴药剂", drugs, madness, 50),
            new Drugs("净化药剂", drugs, cleansing, 50),
        };            //背包药品栏
        double physicalExsistance;      //物理抗性
        enum TypeOfGoods{weapons,armors,drugs};    //同上       
        enum Type{life,madness,cleansing,holy}; //药品类型
        vector<Goods*> wearingBag = {new Armors("布甲",armors,10,0.15,30),new Weapons("铁剑",weapons,7,75)};                   //玩家背包 
    public:
        Player(string name,double ATK,double MHP):Role(name,ATK,MHP),level(1),physicalExsistance(0){
        }
        Player(string name):Role(name), level(1),physicalExsistance(0){
        }    

        void addToWearBag(Goods* g){wearingBag.push_back(g);}
        double& getDodge(){return Dodge;} 
        double& getPE(){return physicalExsistance;}
        void ArmorWearing(Goods* g){ wearingBag[0] = g;}
        void WeaponWearing(Goods* g){ wearingBag[1] = g;}
        int& getFame(){return fame;}  
        int& getLevel(){return level;}
        int lengthOfW(){return weaponsBag.size();}
        int lengthOfA(){return armorsBag.size();}
        int lengthOfD(){return drugsBag.size();}
        int getLength(){return weaponsBag.size() + armorsBag.size() + drugsBag.size();}   //背包总物品数量
        int getNumOfDrugs(){return drugsBag.size();}   //背包内药品数量
        Goods* getDrugOfBag(int n){return drugsBag[n];} //得到背包内的某个药物
        Goods* getWeaponOfBag(int n){return weaponsBag[n];}
        Goods* getArmorOfBag(int n){return armorsBag[n];} 

        ~Player();
        void stronger();
        void levelUp();
        void pick(Goods* g);      //将装备或药品装入背包
        void showInfo();         //显示玩家属性
        void attack(Monster& m);    //攻击怪物
        void buy(Goods* g);         //购买装备或药品
        void hurt(double ATK,double MD);   //受到伤害
        void showBag();             //显示背包内物品
        void showDrugsOfBag();      //显示药品属性
        void showWeaponsOfBag();    //武器属性
        void showArmorsOfBag();     //防具属性
        void takeOff(int n); //卸下装备（仅限武器和防具）
};

class Monster: public Role{
    private:
        enum Type{weapons,armors,drugs};
        enum goodsLevel{low,high,boss};
        int glevel;

        vector<Goods*> lowReward = {
            new Weapons("铁剑",weapons,5,75), new Weapons("阔刀",weapons,9,90),
            new Weapons("诅咒之刃",weapons,8,100), new Weapons("奥术权杖",weapons,10,95),
            new Armors("布甲",armors,10,0.15,30), new Armors("先锋盾",armors,30,0.15,80)
        };
        vector<Goods*> highReward = {
            new Weapons("白银之锋",weapons,20,300), new Weapons("雷霆战矛",weapons,25,450,"技能:触电",10),
            new Weapons("神圣法杖",weapons,20,500,"技能: 秘术",15),
            new Armors("赤红甲",armors,70,0.25,600), new Armors("冰霜之盾",armors,75,0.25,500,15),
        };

    public:
        Monster(string name,int level,double ATK,double MHP):Role(name,ATK,MHP),glevel(level){
            if(glevel == low)
            {
                Wealth = 40 + rand() % 20; 
                experience = 50 + rand() % 50;
            }
            else if(glevel == high)
            {
                Wealth = 100 + rand() % 50;
                experience = 80 + rand() % 40;
            }
            else
            {
                isToxic = true;
            }
            
        }
        Monster(string name,int level):Role(name),glevel(level){
            if(glevel == low)
                experience = 50 + rand() % 50;
            else if(glevel == high)
                experience = 300 + rand() % 100;
        }
        Goods* reward(int n){
            if(glevel == low)
                return lowReward[n];
            else if(glevel == high)
                return highReward[n];
        }

        ~Monster();
        void attack(Player& p);
        void hurt(double ATK,Player* p); //受到伤害，HP=0时一定概率掉落随机装备


};

class NPC:public Role{
    public:
        NPC(string name):Role(name){}
        void fight(Player& player,Monster& soldier);

};

class Store{
    private:
        string name;
        enum TypeOfGoods{weapons,armors,drugs};
        enum TypeOfDrugs{life,madness,cleansing,holy};
        vector<Goods*> store ={
            new Weapons("淬毒战刃", weapons, 13, 120, "剧毒", 5),
            new Weapons("死神镰刀", weapons, 30, 400, "死神呓语",15),
            new Armors("精钢甲", armors, 100, 0.2, 200, 10),
            new Armors("先祖战甲", armors, 200, 0.3, 100, 20),
            new Drugs("生命药剂", drugs, life, 50),
            new Drugs("狂暴药剂", drugs, madness, 50),
            new Drugs("净化药剂", drugs, cleansing, 50),
            new Drugs("圣灵药剂", drugs, holy,50)
        };
    public:
        Store(string name):name(name){}
        int getLength(){return store.size();}
        Goods* getContent(int n){return store[n];}
        void sellTo(Player& p, int n){p.buy(store[n]);}
        void show();
};

class Room {
private:
	string Name;
	vector<Role *> thisplace;
	int num = 0;
	vector<Room *> available;
	int direction = 0;
public:
	Room(string name):Name(name){}
	void setnpc(Role *);//设置地图中的npc
	Room* setDoor(Room*);//设置地图的通道，按照0123：上下左右的顺序存放相邻区域信息
	void printRoom();
};

#endif
