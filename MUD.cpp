#include"MUD.h"
#include<iomanip>
Role::~Role(){}

void Role::showFightInfo()
{
    cout<< setw(6) << name  << ":  最大/当前生命值:" << MHP << "/" << NHP <<"  攻击力: " << 
    ATK << "  闪避率:" << Dodge  << " 是否中毒: ";
    if(isToxic) cout << "是";
    else cout << "否";
    cout << endl;
}
void Weapons::show()
{
    cout << "武器: " << name << " 价格: " << price << " 攻击力+" << ATK << 
    " 技能伤害+" << magicDamage << endl;
}

void Armors::show()
{
    cout << "防具: " << name <<  " 价格: " << price << " 生命值+" << HP << 
    " 物理抗性+" << physicalExsistance << " 闪避+" << dodge << endl;
}

void Drugs::show()
{
    cout << "药品: ";
    switch(typeOfDrug)
    {
        case life:     cout << "生命药剂 生命值+50";
                       break;
        case madness:  cout << "狂暴药剂 攻击力+10";
                       break;
        case cleansing:cout << "净化药剂 解除中毒状态";
                       break;
    }
    cout << " 价格: " << price;
    cout << " 数量：" << num << endl;
}

void Store::show()
{
    cout << "听闻将军升迁，真是可喜可贺，我们这里可是皇城最好的装备店，看一下我们的物品吧：\n";
    for(int i = 0; i < this -> getLength(); i++)
        (this->getContent(i)) -> show();
}

void Player::levelUp()
{
    ATK += 3;
    MHP += 10;
    NHP = MHP;
}

void Player::showInfo()
{
    cout << "名称: " << name << "  最大/当前生命值:" << MHP << "/" << NHP <<"  攻击力: " << 
    ATK << "  闪避率:" << Dodge << "  金币:" << Wealth << "  法术伤害: " << magicDamage << " 是否中毒: ";
    if(isToxic) cout << "是";
    else cout << "否";
    cout << endl;
}

void Player::hurt(double ATK,double MD)
{
    if(isdead) 
    {
        /*cout << "您的角色已经死亡，是否花费200金币复活？(Y or N)\n";
        char choice;
        cin >> choice;
        if(choice == 'Y')
        {    
            NHP = MHP;
            if(getWealth() - 200 > 0)
            {
                getWealth() -= 200;
                cout << "您已复活并"
        }*/
        cout << "很遗憾，您已战败...\n";
        
    }
    if( rand()%100 > Dodge )
        NHP -= (ATK*(1.0 - physicalExsistance) + magicDamage); //受到伤害
    if(NHP <= 0)
    {
        cout << "很遗憾，您已战败...\n";
        isdead = true; //是否死亡
    }
}

void Player::pick(Goods* g)
{
    if(g -> getType() == weapons) 
        weaponsBag.push_back(g);
    else if(g -> getType() == armors) 
        armorsBag.push_back(g);
    else 
    {
        Drugs* d = (Drugs*) g;
        ((Drugs*)getDrugOfBag(d -> getTypeOfDrug())) -> getNum()++;
    } 
}

void Player::showDrugsOfBag()
{
    for(int i = 0; i < drugsBag.size(); i++)
    {   
        cout << i + 1 << ".";
        drugsBag[i] -> show();
    }
}

void Player::showWeaponsOfBag()
{
    for(int i = 0; i < weaponsBag.size(); i++)
    {
        cout << i + 1 << ".";
        weaponsBag[i] -> show();
    }
        
}

void Player::showArmorsOfBag()
{
    for(int i = 0; i < armorsBag.size(); i++)
    {
        cout << i + 1 << ".";
        armorsBag[i] -> show();
    }
}

void Player::showBag()
{
    if(this -> getLength() == 0) cout << "空无一物.....\n";
    showWeaponsOfBag();
    showArmorsOfBag();
    showDrugsOfBag();
}

void Goods::soldBy(Player& p)
{
    p.getWealth() += price;
}

void Armors::useTo(Player* p)
{
    p -> takeOff(0);
    p -> ArmorWearing(this);
    p->getMHP() += HP;
    p->getNHP() = p->getMHP();
    p->getPE() += physicalExsistance;
    p -> getDodge() += dodge;
}

void Drugs::useTo(Player* p)
{
    switch(this -> getTypeOfDrug())
        {
            case life: if(p->getNHP() + 50 <= p->getMHP()) p->getNHP() += 50;
                       else p->getNHP() = p->getMHP();
                       this -> getNum()--;
                       break;
            case madness:  p->getATK() += 20;
                       break;
            case cleansing:p->istoxic() = false;
                       break;
        }
}

void Weapons::useTo(Player* p)
{
    
    p -> takeOff(1);
    cout << "1";
    p -> WeaponWearing(this);
    p->getATK() += ATK;
    p->getMD() += magicDamage;
}

void Goods::picked(Player* p)
{
    p -> pick(this);
}



void Player::buy(Goods* g)
{
    if(g -> getType() == weapons) weaponsBag.push_back(g);
    else if(g -> getType() == armors) armorsBag.push_back(g);
    else drugsBag.push_back(g);
    cout << "已成功放入您的背包\n";
    this -> getWealth() -= g -> getPrice();
}

void Player::stronger()
{
    ATK += 20;
    MHP += 100;
    NHP = MHP;
    Dodge += 20;
    physicalExsistance += 0.2;
}

void Player::attack(Monster& m)
{
    m.hurt(ATK + magicDamage,this);
}

void NPC::fight(Player& player,Monster& soldier)
{
    cout << "对战开始！\n\n";
    while(!soldier.isDead() && !player.isDead())
    {
        cout << endl << endl;
        player.showFightInfo();   //显示每回合对战双方的信息
        soldier.showFightInfo();
        if(soldier.getName() == "光影教主" && 2*soldier.getNHP() <= soldier.getMHP())
        {
            cout << "不小心让光影教主逃跑了....\n";
            break;
        }
        cout << "使用药品or进行攻击？(attack for 攻击 & drug for 药品)\n";
        string choice;
        cin >> choice;
        while(choice != "drug" && choice != "attack")
        {
            cout << "请按照要求输入！\n";
            cin >> choice;
        }
        if(choice == "drug")
        {
            cout << "选择药品种类：";
            player.showDrugsOfBag();
            int choice;
            cin >> choice;
            (player.getDrugOfBag(choice - 1)) -> useTo(&player);
        }
        else
            player.attack(soldier); 
        soldier.attack(player);  
    }
}

void Player::takeOff(int n)
{
    if(n == 0)
    {    
        Armors* a = (Armors*) wearingBag[n]; 
        MHP -= a -> getHP();
        NHP = MHP;
        physicalExsistance = Dodge = 0;
    }
    else if(n == 1)
    {
        Weapons* w = (Weapons*) wearingBag[n];
        ATK -= w -> getATK();
        magicDamage -= w -> getMD();
    }
}

Player::~Player()
{
    for(int i = 0; i < 4; i++)
    {
        delete drugsBag[i];
    }
}

Monster::~Monster()
{
    for(int i = 0; i < 5; i++)
    {
        delete lowReward[i];
        delete highReward[i];
    }
    delete lowReward[5];
}
void Monster::attack(Player& p)
{
    if(isToxic) magicDamage += 10;
    p.hurt(ATK,magicDamage);
}

void Monster::hurt(double ATK,Player* p)
{
    if(NHP - ATK <= 0)
    {    
        isdead = true;
        cout << name << "已被击杀!";
        if(glevel != boss)
        {
            if(rand()%100 > 49)                   //50%概率掉落装备
            {
                int base;
                cout << "你真幸运！对方掉落了一件装备\n";
                if(glevel = low)                         //根据怪物类别以掉落不同的装备
                    base = 6;
                else if(glevel = high) 
                    base = 5;
                Goods* g = this -> reward( rand() % base) ;
                g -> show();
                cout << "1.将其放入背包or 2.直接装备\n";// 玩家是否捡起怪物掉落的装备
                cin.get();
                int choice;
                cin >> choice;
                while(choice != 1 && choice != 2)
                {
                    cout << "请准确输入序号：";
                    cin >> choice;
                }
                if(choice == 1)
                {
                    p -> pick(g);
                   
                }
                else 
                    g -> useTo(p);

            }
            else
                cout << "很不幸，对方似乎穷困潦倒，并未掉落装备\n";
            cout << "您获得了" << Wealth << "金币和" << experience << "经验";//杀死怪物获得金币和经验
            p -> getWealth() += Wealth;
            p -> getExperience() += experience;
            if(p -> getExperience() > 100 + p -> getLevel()*70)
            {
                cout << "\n您的等级上升了一级！\n";
                p -> getExperience() = 0;
                p -> getLevel() += 1;
                p -> levelUp();
            }   
            
        }
    }
    else 
        NHP -= ATK;
    if(NHP <= 0)
        isdead = true;

}

Room* Room::setDoor(Room* place) {
	available.push_back(place);
    return this;
}


void Room::setnpc(Role* character) {
	thisplace.push_back(character);
}

void Room::printRoom()
{
    cout << "当前所在区域: " << Name << "";

}
