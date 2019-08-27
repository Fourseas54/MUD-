#include"MUD.h"

void Weapons::showWeapons()
{
    cout << "武器: " << name << " 价格: " << price << " 攻击力+" << ATK << 
    " 技能伤害+" << magicDamage << endl;
}

void Armors::showArmors()
{
    cout << "防具:" << name <<  " 价格: " << price << " 生命值+" << HP << 
    " 物理抗性+" << physicalExsistance << " 闪避+" << dodge << endl;
}

void Drugs::showDrugs()
{
    switch(typeOfDrug)
    {
        case life:     cout << "生命药剂 生命值+50";
                       break;
        case madness:  cout << "狂暴药剂 攻击力+20";
                       break;
        case cleansing:cout << "净化药剂 解除中毒状态";
                       break;
        case holy:     cout << "圣灵药剂 免疫中毒5回合";
                       break;
    }
    cout << " 价格: " << price << endl;
}

void Store::showStore()
{
    cout << "商品有：\n";
    for(int i = 0; i < this -> getLength(); i++)
        (this->getContent(i)) -> show();
}

void Player::beHurt(double ATK,double MD)
{
    if(isdead) 
    {
        cout << "您的角色已经死亡，是否花费200金币复活？(Y or N)\n";
        char choice;
        cin >> choice;
        if(choice == 'Y')
            NHP = MHP;
        else
            cout << "游戏结束！谢谢\n";
        
    }
    if( rand()%100 > Dodge )
        NHP -= (ATK*(1.0 - physicalExsistance) + magicDamage); //受到伤害
    if(immuneTimes != 0) 
        NHP += magicDamage;  //是否免疫中毒
    if(NHP <= 0)
        isdead = true; //是否死亡
}

void Player::showBag()
{
    for(int i = 0; i < this->getLength(); i++)
    {
        (this->getContent(i)) -> show();
    }
}

void Player::use(Weapons* w)
{
    if(!isWearingWeapon)
    {
        ATK += w -> getATK();
        magicDamage += w -> getMD();
        isWearingWeapon = true;
    }
}

void Player::use(Armors* a)
{
    if(!isWearingArmor)
    {
        MHP += a -> getHP();
        NHP = MHP;
        physicalExsistance += a ->getPE();
        Dodge += a -> getDodge();
        isWearingArmor = true;
    }
}

void Player::use(Drugs* d)
{
    switch(d -> getType())
    {
        case life:     NHP += 50;
                       break;
        case madness:  ATK += 20;
                       break;
        case cleansing:isToxic = false;
                       break;
        case holy:     immuneTimes = 5;
                       break;
    }
}

void Monster::hurt(double ATK,Player* p)
{
    if(isdead)
    {    
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
                cout << "是否将其放入背包？(enter Y for yes & N for no)\n";// 玩家是否捡起怪物掉落的装别
                char choice;
                if(choice == 'Y')
                    g -> picked(p);

            }
            else
                cout << "很不幸，对方似乎穷困潦倒，并未掉落装备\n";
            cout << "您获得了" << Wealth << "金币和" << experience << "经验";//杀死怪物获得金币和经验
            p -> getWealth() += Wealth;
            p -> getExperience() += experience;
            
        }
    }
    else 
        NHP -= ATK;

}

void Room::setdoor(Room &place) {
	*available[direction] = place;
}


void Room::setnpc(Role& character) {
	*thisplace[num] = character;
}



