#include"MUD.h"

namespace someEnum{
    enum MonsterLevel{low,high,boss};
    enum TypeOfGoods{weapons,armors,drugs};
    enum TypeOfDrugs{life,madness,cleansing};
    enum memory{start,whetherJoin,whetherFind,whetherLie,whetherBeGeneral,whetherFightAgain};
}
void savePlayer(Player& p );
void get(Player& p);
void pointMemory(int n);
int getPoint();

using namespace someEnum;

int main()
{
    srand((int)time(0));      //设置随机数种子
    int way = getPoint();
    Player player("蛇青",11,70);
    Drugs test("生命",drugs,life,50);
    test.useTo(&player);
    Weapons base("铁剑",weapons,7,75);
    player.pick(&base);
    base.useTo(&player);
    player.addToWearBag(&base);
    Armors base1("布甲",armors,20,0.15,30);
    player.pick(&base1);
    base1.useTo(&player);
    player.addToWearBag(&base1);

    cout << "\t\t\t\t该游戏共有5个不同的分支，您在游戏中的的选择会影响游戏剧情的走向，这5个分支分别是：\n";
    cout << "\t\t\t\t1.是否加入海狮族  2.是否去寻找召唤  3.是否隐瞒真相  4.是否当军队统帅  5.是否因为不甘再次战斗\n";
    cout << "游戏前须知:\n\t\t\t1.在该游戏中,如果您在装备一件装备时身上正装备有同类型的装备，则将使用前者替换后者\n";
    cout << "\n\t\t\t2.按回车键以推动剧情发展\n";
    cout << "\t\t\t\t\t    1\n\t\t\t\t\t   /  \\ \n";
    cout << "\t\t\t\t\t  2    5\n";
    cout << "\t\t\t\t\t /  \\ \n";
    cout << "\t\t\t\t\t3    4\n";
    int choice1;
    if(getPoint() > 0)
    {
        cout << "您上次进行到了第" << getPoint() << "个分支,请选择从哪一个分支开始继续您的游戏:（只能选择您进行过的分支！例：您在5，则只能选择1或5）";
        cin >> choice1;
    }

    NPC System("战斗系统");
    Monster guardian("守门将士",low,15,100);                //怪物以及boss的初始化
    Monster seaWolf("海狼",low,4,35);
	Monster soilder1("小兵1",low, 6, 40);
	Monster soilder2("小兵2",low, 6, 40);
    Monster general("三成功力的将军",boss,20,170);
    Monster beliver[4] ={
        Monster("信徒1",high,13,85),
        Monster("信徒2",high,14,78),
        Monster("守卫队长",high,18,100),
        Monster("守卫统领",high,20,130)
    };
    Monster hierarch("光影教主",boss,30,250);
    Monster royalCaptain("守卫统领",high,20,200);
    Monster dragonKing("青龙王",boss,30,400);

    switch(choice1){
case start:     
    system("color 0A");        //控制台背景及字体颜色控制
    pointMemory(0);            //记录存档的位置
    cout << "\t\t\t\t\t\t\t\t\t地图\n";

    cout<<"\t\t\t\t\t\t|                         海之平原                                   |"<<endl;
	cout<<"\t\t\t\t\t\t|___________________________________________________________________|"<<endl;
	cout<<"\t\t\t\t\t\t|海狮族城郊   |          |         |      |        |亚特兰蒂斯________|"<<endl;
	cout<<"\t\t\t\t\t\t|_____________|   边境   |   残破  | 边境 | 海神族 |  皇城   |  内    |"<<endl;
	cout<<"\t\t\t\t\t\t|海狮族-狮王阁|     ~    |         |  ~   |光影祭坛|   外    |  部    | "<<endl;   //  地图打印
	cout<<"\t\t\t\t\t\t|_____________|  海狮族  |   沙场  |海神族|        |   围    |________|"<<endl;
	cout<<"\t\t\t\t\t\t|海狮族-住处  |          |         |      |        |                  |"<<endl;
	cout<<"\t\t\t\t\t\t|_____________|__________|_________|______|________|__________________|\n\n"<<endl;

    cout << "海神历64008年，海蛇族被海神族灭族，海蛇族最后剩下一名少年蛇青藏在海沟里幸免于难\n";
    cout <<"在海神族走后，蛇青只得在海沟中流浪，在这个贫瘠的地方艰难生存，渐渐长大。\n";
    cout << "在他成蛇那年，目睹了亲人被屠戮的他压抑多年的仇恨终是抑制不住喷涌而出\n";
    cout << "它义无反顾的冲向亚特兰蒂斯——海神族的皇宫。\n\n";

    cin.get();
    cout << "\t\t\t\t\t\t【亚特兰蒂斯——皇宫正门】\n\n";
    cout << "蛇青：“你海神族杀我族人，屠我父母，今日我定要让你们血债血偿！”\n";
    cout << "守门将士：“哪里来的废物，我海神族征战四方，杀的人不尽其数";
    cout << "会在乎你一个小小海蛇的骚扰吗？来啊，让我看看你的能耐！”\n";

    cin.get();
    system("cls");
    /*vector<Room*> rooms = {
        new Room("皇城内部"),
        new Room("皇城"),
        new Room("皇城外围"),
        new Room("海神族-光影祭坛"),
        new Room("亚特兰蒂斯"),
        new Room("边境-海神族"),
        new Room("残破沙场"),
        new Room("边境-海狮族"),
        new Room("海狮族-城郊"),
        new Room("海狮族-住处"),
        new Room("海狮族-狮王阁"),
        new Room("海之平原"),
        new Room("陨落之境"),
    };


    rooms[0] -> setDoor(rooms[4]) -> setDoor(rooms[1]) -> setDoor(rooms[2]);
    rooms[1] -> setDoor(rooms[0]) -> setDoor(nullptr) -> setDoor(rooms[2]);
    rooms[2] -> setDoor(rooms[4]) -> setDoor(rooms[1]) -> setDoor(rooms[3]) -> setDoor(rooms[0]);
    rooms[3] -> setDoor(nullptr) -> setDoor(nullptr) -> setDoor(rooms[5]) -> setDoor(rooms[2]);
    rooms[4] -> setDoor(nullptr) -> setDoor(rooms[0]) -> setDoor(rooms[2]);
    rooms[5] -> setDoor(nullptr) -> setDoor(nullptr) -> setDoor(rooms[6]) -> setDoor(rooms[3]);
    rooms[6] -> setDoor(nullptr) -> setDoor(nullptr) -> setDoor(rooms[7]) -> setDoor(rooms[5]);
    rooms[7] -> setDoor(rooms[8]) -> setDoor(rooms[9]) -> setDoor(rooms[10]) -> setDoor(rooms[6]);
    rooms[8] -> setDoor(rooms[11]) -> setDoor(rooms[10]) -> setDoor(nullptr) -> setDoor(rooms[7]);
    rooms[9] -> setDoor(rooms[10]) -> setDoor(nullptr) -> setDoor(nullptr) -> setDoor(rooms[7]);
    rooms[10] -> setDoor(rooms[8]) -> setDoor(rooms[9]) -> setDoor(nullptr) -> setDoor(rooms[7]);*/ 

    cout << "即将开始战斗，这是角色的基本信息:\n";     //人物角色初始化并显示出来
    player.showInfo();
    cout << "您的背包具有一些初级物品:\n";
    player.showBag();

    cin.get();
    system("cls");    
    System.fight(player,guardian);
    player.refresh();
    guardian.refresh();
    savePlayer(player);
    system("cls");
    cout << "\n守门将士：“原来是个弱鸡，呸”\n";
    cout << "\n在浑身的剧痛中，蛇青失去了意识……\n";
case whetherJoin:
    cin.get();
    //get(player);
    cout << "“\n他醒了！他醒了！”在一个小孩的大喊中蛇青缓缓睁开了双眼。褐色的天花板，环顾四周，都是普通的家具装饰。\n";
    cin.get();
    cout << "\n【海狮族——住处】\n";
    cout <<"\n海狮爷爷：“我在王宫的外围发现了你，遍体鳞伤昏迷不醒，我便把你接到了这里。";
    cout <<"      海神族树敌无数，但碍于强大的实力无人敢言，但像你这么勇敢的孩子我还是第一次见。”\n";
    cout << "\n蛇青：    “我族只剩我一人…我没能力为他们声讨，不如随他们去吧…”\n";
    cout << "\n海狮爷爷：“没有计划的勇敢是为鲁莽，加入我们，获取力量再去复仇不迟。”\n";
    pointMemory(1);            //记录存档的位置
    cout << "【选择1.加入海狮族  2.不加入】\n";
    int choice;
    cin >> choice;
    while(choice != 1 && choice != 2)
    {
        cout << "请按照要求输入序号...\n";
        cin >> choice;
    }

    if(choice == 1)        //加入海狮族支线剧情
    {
        cout << "\n蛇青：“您能收留我真是太好了，我流离失所多年一直渴望有一个家，谢谢您，无论让我做什么我都义不容辞。”\n";
        cout << "\n海狮爷爷：“好的，我先带你去见首领，也许他会给你一些任务”\n";
        cin.get();
        cout << "\n【海狮族——狮王阁】\n ";
        cout << "\n狮王首领：“小兄弟你好，废话我就不多说了，现在医药处急需一颗海狼之心，不知你是否可以去海之平原上取来”\n";
        cout << "\n蛇青：“谢首领信任，我定不负期望完成任务”\n";
        cout << "\n【海之平原】\n";
        cin.get();
        cout << "\n辽阔的海之平原上生活着一群凶猛的海狼,您必须击杀三只海狼后方可得到海狼之心\n";
        system("cls");
        for(int i = 0; i < 3; i++)
        {
            cin.get();
            System.fight(player,seaWolf);
            seaWolf.refresh();
        }
        player.refresh();

        cin.get();
        cout << "\n【海狮族——狮王阁】\n";
        cout << "\n首领：“干得不错。奖励你200金币，去休息吧。”\n";
        player.getWealth() += 200; 

        cin.get();
        cout << "\n【海狮族——住处】\n";
        cout << "海狮爷爷：“在很久的远古，海神，海狮与海龙并为三霸主，但随着海龙族整族消失，海狮式微，海神族便一家独大称霸海底。\n";
        cout << "我族也与海神族交战多年，但屡战屡败….很大一部分原因是信息闭塞…我们海狮身躯庞大且毛色发金光，隔很远便可清晰发现，\n";
        cout << "而海神族精通法术，总能偷派傀儡偷的我军部署信息…首领说，希望你可以去前线做一个侦察使者，勘探敌军情况回报回来，不知你可愿意”\n";
        cout << "\n蛇青：“愿意。海狮族救我一命，我定报答，九死不悔。”\n";
        cout << "\n海狮爷爷：“很好，我没有看错你，去吧，即日启程。”\n";

        cin.get();
        cout << "\n【边境——海狮族】\n";
        cout << "\n这里的海水呈现淡红色，沙地上裂痕纵横，兵戟遍地，无不彰显着战争的残酷。\n";
        cout << "\n将军：“蛇青，我们有一精英小队在前线被困，不知战士们是否安好，敌军数量如何，需要靠你前去打探消息，现在出发速去速回”\n";
        cout << "\n蛇青：“是，将军”\n";
        savePlayer(player);
case  whetherFind:     
        //get(player);
        cin.get();
        system("cls");
        cout << "\n【残破沙场】\n";
        cout << "\n突然蛇青感受到了一阵来自心脏的悸动，那是来自血脉的召唤，召唤来自战场深处的陨落之境，但陨落之境与小队被困之处并不是一个方向….";
        pointMemory(2);            //记录存档的位置
        cout << "\n【选择  1.寻找召唤，也许是机缘  2.执行任务，继续去打探消息】\n";
        cin >> choice;
        while(choice != 1 && choice != 2)
        {
            cout << "请按照要求输入序号...\n";
            cin >> choice;
        }
        bool hide;      //用以记录后面剧情的选择
        if(choice == 1)            //寻找召唤触发的剧情
        {
            cout << "\n蛇青遵从自己内心的声音，向战场深处游去\n";
            cin.get();
            cout << "\n【陨落之境】\n";
            cout << "\n陨落之境天色暗沉，仿佛有无数幽魂再次游荡，蛇青跟着自己血脉的指引来到此地，有些害怕。\n";
            cout << "海龙之魂：“苍天有眼，让吾在神魂消散之前可遇吾之后人，孩子，你叫何名？”\n";
            cout << "蛇青：“我…我叫蛇青”\n";
            cout << "海龙之魂：“好，蛇青…蛇青…我海龙一族已沦落到海蛇之位了吗，失去了海洋之光的洗礼，血脉竟已退化至此，真是悲哀啊，蛇青，我的族人是否安好”\n";
            cout << "蛇青：“我…我是我族唯一所剩族人，其他人…其他族人都被海神族屠戮殆尽…..就连我也差点死于其手…”\n";
            cout << "经过长久的而压抑的沉默后，海龙仰天长啸，声波震得周围海水翻滚不止。“报仇！蛇青你定要替我的族人报仇！我会将我的精血尽数转移给你，让你觉醒最高等级的龙之血脉！带你成龙之时，就是海神族灭族之时！”\n";
            cout << "语罢，海龙双爪一握，便有丝丝金线从周围庞大的海龙遗体中流出，金线缠绕于蛇青身上，融入皮肉，渗入骨骼，重铸血脉。蛇青的片片蛇鳞更是逐渐变为金鳞，而金线最后汇聚于蛇青额头之上，化为三道金纹，熠熠生辉。\n";
            cout << "海龙之魂：“三纹齐聚，化龙腾空…孩子，我族复仇之重担，全靠你了….”\n在最后的嘱托声中，海龙之魂逐渐消散与海水中。\n";
            cout << "蛇青：“先祖，我定不辱使命！”\n";
            cin.get();
            cout << "\n【残破沙场】\n";
            cout << "蛇青：“现在赶去战场，不知是否还来得及…”\n";
            cin.get();
            cout << "\n【交战前线】\n";
            cout << "蛇青赶回战场，由于他的的延误，只发现一地的尸首。而海神族的部队更是全无踪影。\n";
            cout << "蛇青：“天哪，这都怪我…”\n";
            cout << "任务：向将军报告任务\n";
            savePlayer(player);

case whetherLie:
            //get(player);
            cin.get();
            system("cls");
            cout << "\n【边境——海狮族】\n";
            cout << "\n将军：“你为何去了如此之久！战况如何！”\n";
            cin.get();
            cout << "【选择 1.	和盘托出，承认自己去晚了的事实 2.	隐瞒真相，谎称已无力挽救】";
            pointMemory(3);            //记录存档的位置
            cin >> choice;
            while(choice != 1 && choice != 2)
            {
                cout << "请按照要求输入序号...\n";
                cin >> choice;
            }
            if(choice == 1)          //选择和盘托出触发的剧情
            {
                cout << "\n1.	蛇青：“对不起，我路上遇到了敌方士兵，为了不被发现只能绕路，等我到的时候，小队人马已尽数牺牲…对不起，是我的错….”\n";
                cout << "\n将军：“哎，算了，事已至此，下去吧”\n声望--\n";
                player.getFame()--;
                hide = false;
            }
            else                     //隐瞒真相触发的剧情
            {
                cout << "2.	蛇青：“对不起！是我的错….我感到的时候我方小队已经几近团灭，要是调部队的话肯定来不及….\n所以我和他们一起殊死抵抗为部落捐躯，但是最后只有我一个逃了出来…对不起…对不起…”\n";
                cout << "将军：“起来吧！你已经尽力了…我知道了…你的勇敢我都记在心里，回去吧。”\n声望++\n";
                player.getFame()++;
                hide = true;
            }
            
        }
        else                     //继续执行任务触发的剧情
        {
            cout << "\n蛇青：“将士们都等着我呢，我不能如此自私…\n”";
            cin.get();
			cout << "\n【交战边境】\n";
			cout << "\n蛇青看清了状况，小队在抵抗且仍有救援机会。\n";
            cin.get();
			cout << "\n【边境——海狮族】\n";
			cout << "\n蛇青：“可救！”\n";
			cout << "\n将军：“走！众将士随我来！”\n";
            cin.get();
            system("cls");
			cout << "\n【交战边境】\n";

            cin.get();
			System.fight(player, soilder1);
            cin.get();
			System.fight(player, soilder2);
            player.refresh();

			cout << "\n【营救成功】\n";
			player.getFame()++;
			cout << "\n夜晚，蛇青一个人偷偷溜出营地\n";
			cout<<"\n蛇青：“我记得召唤好像在陨落之境….”\n";
            cin.get();
		    cout << "\n【陨落之境】\n";
			cout << "陨落之境天色暗沉，仿佛有无数幽魂再次游荡，蛇青跟着自己血脉的指引来到此地，有些害怕。\n";
			cout << "海龙之魂：“苍天有眼，让吾在神魂消散之前可遇吾之后人，孩子，你叫何名？”\n";
			cout << "蛇青：“我…我叫蛇青”\n";
			cout << "海龙之魂：“好，蛇青…蛇青…我海龙一族已沦落到海蛇之位了吗，失去了海洋之光的洗礼，血脉竟已退化至此，真是悲哀啊，蛇青，我的族人是否安好”\n";
			cout << "蛇青：“我…我是我族唯一所剩族人，其他人…其他族人都被海神族屠戮殆尽…..就连我也差点死于其手…”\n";
			cout << "经过长久的而压抑的沉默后，海龙仰天长啸，声波震得周围海水翻滚不止。“报仇！蛇青你定要替我的族人报仇！我会将我的精血尽数转移给你，让你觉醒最高等级的龙之血脉！带你成龙之时，就是海神族灭族之时！”\n";
			cout << "语罢，海龙双爪一握，便有丝丝金线从周围庞大的海龙遗体中流出，金线缠绕于蛇青身上，融入皮肉，渗入骨骼，重铸血脉。蛇青的片片蛇鳞更是逐渐变为金鳞，而金线最后汇聚于蛇青额头之上，化为三道金纹，熠熠生辉。\n";
			cout << "海龙之魂：“三纹齐聚，化龙腾空…孩子，我族复仇之重担，全靠你了….”\n在最后的嘱托声中，海龙之魂逐渐消散与海水中。\n";
			cout << "蛇青：“先祖，我定不辱使命！”\n";

            cin.get();
            system("cls");
            cout << "\t\t\t\t\t\t\n【边境——海狮族】\n";
            cout << "日子在紧张与空闲之间流逝着。年已至末尾，蛇青额头的三纹却没有半点变化…\n\n\t\t\t\t\t\t任务：“了解最近的战况部署\n\n”";
            cout << "统领：“听说马上就要到海神祭典了，我听说远古时期这海洋之光可是三族共享，现在海神一家独大，祭典只有他们独占。将军打算这次趁着祭典，破坏他们的祭祀行动！”\n\n";
            cout << "蛇青：“破坏祭祀…也许可以受到海洋之光的洗礼，或许对金纹有益….”\n";
            cout << "蛇青：“将军，这次破坏祭典的行动我想参加。”\n\n";
            cout << "将军：“可你是侦察使者啊，我们这次是打算奇袭祭坛，你可以吗？”\n";
            cout << "蛇青：“我前段时间偶然习得我家族秘籍，现在也具有一定的战斗力！我可以的”\n";
            cout << "将军：“是吗，那先和我过两招吧”\n\n";

            cin.get();
            system("cls");
            System.fight(player,general);
            player.refresh();

            cout << "将军：“好小子，我用了三成力竟然打不过你，你可以参加了！”\n";
            cout << "蛇青：“谢谢将军！”\n";

            cin.get();
            system("cls");
            cout << "\n\t\t\t\t\t\t【海神族——光影祭坛】\n\n";
            cout << "光影教主：“我海神族有今日的辉煌，都是因为有光影之主的庇护”\n信众：“故，我在”\n";
            cout << "光影教主：“有光影之主，定能保我海神族长盛不衰，万古长存！”\n信众：“长生不衰！万古长存！”\n";
            cout << "\n将军：“呸！恶心！”\n";
            cout << "光影教主：“谁？！”\n";
            cout << "将军：“你爷爷我！这海洋之光本是三族同享，现在你一家霸占，这吃相未免不要太难看！”\n";
            cout << "光影教主：“呵呵，还不是因为你们都是些废物！有本事你来抢啊”\n";
            cout << "将军：“给老子上，杀了这些杂种！”\n";
            
            cin.get();
            system("cls");
            for(int i = 0; i < 4; i++)
            {
                System.fight(player,beliver[i]);
                cin.get();
            }
            player.refresh();
            delete[] beliver;

            cout << "\n将军：“可以啊小子，伤害够高！”\n\n\t\t【对决光影教主】\n";

            cin.get();
            system("cls");
            System.fight(player,hierarch);
            player.refresh();
            hierarch.refresh();

            cout << "\n光影教主：光影之主会诅咒你的！你等着！\n";
            cout << "获得祝福:海洋之心  你和友方属性大幅提升\n";

            cout <<" 蛇青：“将军，这洗礼可以算我一个吗”\n";
            cout <<"将军：“你居功至伟，当然可以！”\n";
            cout << "蛇青站上祭坛，在一片明亮而不耀眼的金光中，蛇青额头上的第二纹缓缓开启，身上的蛇鳞也有更多转变成问金色的龙鳞。随着金光淡去，蛇青身上的金鳞也回复了正常，额头上的纹路也渐渐淡去隐没与皮肤下。\n";
            cout << "\n任务完成 声望暴增\n";
            void stronger();

            if(hide)
            {
                cout << "士兵：“报！将军！他们….他们回来了！”\n";
                cout << "将军：“谁？！”\n";
                cout << "士兵：“一队！我们以为全军覆没的一队！”\n";
                cout << "将军：“什么！！！！他们没死！！快叫他们进来！！”\n";
                cout << "蛇青听闻仿佛如坠冰窟，他知道自己的谎言败露了，海狮族收留他重用他，他却为了自己的机缘害了他们的士兵…不知道得知真相的将军还会不会留他…蛇青瑟瑟发抖，默不作声离开了军帐。\n";
                cout << "果然，没过多久，蛇青便接到了军令：逐出海狮族，永不得归。\n声望清零。";
                player.getFame() = 0;
                system("cls");
            }
            savePlayer(player);
case whetherBeGeneral:
            //get(player);
            cin.get();
            system("cls");
            cout << "\n\t\t\t\t\t\t【边境——海狮族】\n";
            cout << "\n将军：蛇青，你能力出众，声望之高已经有资格担当统领，从今日起你便是我军的新晋统领，如何？\n";
            pointMemory(4);           //记录存档的位置
            cout << "1.接受  2.不接受";
            cin >> choice;
            while(choice != 1 && choice != 2)
            {
                cout << "请按照要求输入序号...\n";
                cin >> choice;
            }
            if(choice == 1)
            {
                cout << "\n蛇青：“谢将军赏识！我定不辱使命！”\n";
                cout << "获得军队战力+++\n";
                cout << "\n【由于在你的帮助下成功破坏海神族祭祀且获得海洋之光的洗礼，你和海狮族部队力量获得大幅提升，将军决定以胜者之师打败者之伍，一鼓作气击败海神族。】\n";
                cout << "\n\t\t\t\t\t\t\t\t\t\t【任务：攻打亚特兰蒂斯】\n";
                cout << "心思缜密的你为确保此次行动万无一失，并且你身为军队统领，获得了进入皇家装备铺的资格，并决定去买些装备武装自己\n";
                Store royalStore("皇家装备铺");
                royalStore.show();
                cout << "你翻了翻自己的背包，发现里面有" << player.getWealth() << "金币\n";
                cout << "店铺老板：请挑选一件您满意的装备吧，它必将带领你所向披靡.\n";
                int yourChoice;
                cin >> yourChoice;
                while(yourChoice <= 0 || yourChoice > 8)
                {
                    cout << "请正确输入您的选择序号";
                    cin >> yourChoice;
                }
                royalStore.sellTo(player,yourChoice - 1);
                cout << "店铺老板：祝将军战事顺利\n\n";
                cout << "是否查看您的背包以更换更顺手的装备？(Y for yes & N for no)\n";
                char ychoice;
                cin >> ychoice;
                while(ychoice != 'Y' && ychoice != 'N' && ychoice != 'y' && ychoice != 'n')
                {
                    cout << "请重新输入您的选择\n";
                    cin >> ychoice;
                }
                if(ychoice == 'Y' || ychoice == 'y')
                {
                    player.showBag();
                    cout << "选择要配带的装备:(除药品外)";
                    int choose;
                    cin >> choose;
                    if(choose > 0 && choose <= player.lengthOfW())
                        player.getWeaponOfBag(choose - 1) -> useTo(&player);
                    else if(choose > player.lengthOfW() && choose <= player.lengthOfA())
                        player.getArmorOfBag(choose - 1) -> useTo(&player); 
                }
                cin.get();
                cout << "\n\t\t\t\t\t\t\t\t\t\t【亚特兰蒂斯——皇宫正门】\n";
                cout << "\n又来到这个熟悉的地方，蛇青仿佛感受到一只名为命运的手一直在牵着他的步伐，只不过不知道如今，这一次再次军临海神族，能否完成他的夙愿。\n";
                cout << "还未至门口，蛇青便见到密密麻麻的海神族部队横亘于皇宫正门前。显然，海神族经历了祭祀的失败，对他们的到来早有预知并不敢轻敌做足了准备。\n";
                cout<<"又来到这个熟悉的地方，蛇青仿佛感受到一只名为命运的手一直在牵着他的步伐，只不过不知道如今，这一次再次军临海神族，能否完成他的夙愿。"; 
                cout<<"还未至门口，蛇青便见到密密麻麻的海神族部队横亘于皇宫正门前。显然，海神族经历了祭祀的失败，对他们的到来早有预知并不敢轻敌做足了准备。"; 
                cout<<"蛇青统领，怎么样，怕了吗！"; 
                cout<<"我等的就是这一天！我定要手刃仇人！"; 
                cout<<"好！上！！！！！！！！"; 

                cin.get();
                system("cls");
                System.fight(player,royalCaptain);
                player.refresh();
                cin.get();
                system("cls"); 

                cout<<"蛇青：我总算进入这皇宫了！今天就是你们血债血偿之时！\n"; 
                cout<<"光影教主：小杂种，你竟能走到这里。海神祭典的仇我今日必将讨回！有种上来单挑！\n"; 
                cout<<"蛇青：你海神族屠我族人！杀我父母！我的血海深仇今日便要从你身上讨回！\n"; 
                cout<<"蛇青回身对族人说：你们不用跟来，我独自会会这个败类！\n"; 

                cin.get();
                system("cls");
                System.fight(player,hierarch);
                player.refresh();

                cout<<"得到光影教主的祭器\n"; 
                cout<<"蛇青手捧祭器，他仿佛感受到了似曾相识的召唤从这个祭器中传出，就像在觉醒龙纹之时的玄妙感觉。\n"; 
                cout<<"或许是血脉不同的原因，那种强大的力量光影教主根本没有发挥出来其中的万分之一， 但蛇青却仿佛感受到了一双手从祭器伸出，缓缓按在他的额头上，温暖而不陌生。\n"; 
                cout<<"蛇青放下心中所有戒备，静静感受着从这双手中稳定的传来的龙之力量…那力量仿佛一支金色的画笔，一笔一划地在蛇青额头上描绘着龙纹，稳定却又带着坚决，仿佛寄托着海龙族先辈的期望与嘱托。\n"; 
                cout<<"你可以的….孩子….带着我们的力量….去吧\n";
                player.stronger();

                cin.get();
                system("cls");

                cout<<"海狮族的士兵在蛇青周围围作一圈，抵御着海神族的攻击保护蛇青，他们不知道发生了什么，但只知道统领正在进行很重要的提升，容不得打扰。\n"; 
                cout<<"突然从皇宫深处爆发出了一股巨大的力量，这力量裹挟着海神之力蛮横的撕破了海狮族的防线，直指蛇青而去，海狮族士兵们绝望的望着那金色的冲击波，闭上了眼睛，但他们却没有退开蛇青的四周。\n"; 
                cout<<"我来！\n"; 
                cout<<"一声怒喝从旁传来，将军手持巨剑冲了上来，巨剑横插入地下，金色的冲击波直冲巨剑发出巨大的碰撞声，一瞬间周围百米的所有山石皆化为粉末，士兵们被巨浪裹挟四散飞去，在一片金色的圣光中，纷纷失去了意识。\n"; 
                cout<<"冲击波带有后劲，将军无力抵抗节节败退，就连巨剑上也出现了些许裂痕。将军嘴边留下猩红的血丝\n"; 
                cout<<"这就是…海神的力量吗…\n"; 
                cout<<"蓦地，将军感觉压力仿佛几乎消失，他疑惑的抬起头，只见在他身旁，一只巨大的青色龙爪抵着巨剑。在同样耀眼的一片金光中，传来蛇青的声音\n"; 
                cout<<"谢谢您，将军，接下来就交给我吧….\n"; 
                cout<<"蛇青缓缓发出几道吐息，将这海神的冲击波挡了大半。\n"; 
                cout<<"身为一族之主，偷偷摸摸的算什么本事….今日你无论如何也难逃一死…我族的仇，还有这些将士的伤，我都要从你身上讨回…\n"; 
                cout<<"想不到啊，当年的漏网之鱼竟然也有能力跟本王叫板了…失误啊失误啊…居然让你完成了三纹化龙，不过即使这样你也依旧打不过我….废物就是废物。\n"; 
                cout<<"声音缓缓从王宫深处传来，一位发须尽白的老者从阴影中走出。\n"; 
                cout<<"海神….\n"; 
                cout<<"青龙王….好久不见的龙族啊….既然如此…那就让我将你最后的幻想破灭吧！\n";

                cin.get();
                system("cls");

                System.fight(player,dragonKing);
                player.refresh(); 

                cout << "蛇青在皇宫废墟中央缓缓跪下….\n"; 
                cout << "爸，妈，龙王前辈….我成功了…\n"; 
                cout << "泪水从眼角流出，转瞬之间融入海水，消失不见。\n";
                cout << "\t\t\t\t\t\tOVER\n";
            }
            else
            {
                cout<<"\n蛇青：将军，我独来独往惯了，身上肩负灭族之仇…我怕将士们跟着我会受到危险…这统领…我还是不做了\n"; 
                cout<<"将军愣住了，他没有料到蛇青竟然会拒绝他。\n";
                cout<<"哎….你说你….随你去吧!"; 
                cout<<"将军有些失望的摆摆手。\n"; 
                cout<<"蛇青鞠了一躬，退出了军帐。他抚摸着额头上的龙纹，接受了海洋之光的洗礼的他感觉自己力量无穷，他望向亚特兰蒂斯的方向。暗下决心。\n"; 
                cout<<"当夜，蛇青偷偷溜出了海狮族的军营，向着亚特兰蒂斯游去。\n"; 
                cout<<"又来到这个熟悉的地方，蛇青仿佛感受到一只名为命运的手一直在牵着他的步伐，只不过这次不知他能否大仇得报…\n"; 
                cout<<"还未至门口，蛇青便见到密密麻麻的海神族部队横亘于皇宫正门前。显然，海神族经历了祭祀的失败，对他们的到来早有预知并不敢轻敌做足了准备。\n"; 
                cout<<"没有了士兵的支援，不知道他能不能闯的过去，蛇青远远的望着这皇宫正门，一言不发便冲了上去…\n";
                cout << "他奋力拼杀着，发泄着内心的仇恨，但无奈自己一人难敌一众敌人，身上不知道什么时候多了许多血流不止的伤口，逐渐的，他的意识变得模糊不清，他意识到还是自己太鲁莽了...\n"; 
                cout<<"在无尽的痛苦中，蛇青缓缓闭上了双眼…\n"; 
                cout << "\t\t\t\t\t\tOVER\n";
            }
            
        }
    }
    else                   //不加入海狮族支线剧情
        {
        cout << "\n蛇青：“对不起，谢谢您的好意，但是我这么多年都自己一个人撑了过来，我想接下来的路还是我一个人走比较好。”\n";
        cin.get();
        savePlayer(player);

case whetherFightAgain: //get(player);
        cout << "\n【海狮族城郊】\n";
        cout << "\n金色的塔顶高耸着，仿佛要刺破海面。即使相隔这么远，亚特兰蒂斯依旧清晰可见。蛇青望着远处的亚特兰蒂斯\n";
        cout <<"【选择  1.上次疏忽大意了才被击败，再去一次\n\t2.先在附近的平原上历练一段时间，再去复仇】\n";
        pointMemory(5);
        cout <<"你选择：";
        cin >> choice;
        while(choice != 1 && choice != 2)
        {
            cout << "请按照要求输入序号...\n";
            cin >> choice;
        }
        if(choice == 1)
        {
            cin.get();
            cout << "\n【亚特兰蒂斯——皇宫正门】\n";
            cout << "\n又是熟悉的场景，只不过这一次你是有备而来。\n";
            cout << "\n守门将士：“又是你？这次我可不会手下留情了”\n";
            System.fight(player,guardian);
            cout << "\n在无尽的悔恨与绝望中，蛇青闭上了双眼。要是当时选择留在海狮族，可能就不会死了吧….\n";
        }
        else
        {
            cin.get();
            cout << "\n【海狮城城郊】\n";
            cout << "\n你看到这里有不少初级野怪，决定用他们来提升自己\n";
            cout << "这里有1.海葵 2.海胆 3.小海龟三种怪物，请选择其中之一进行对战\n";

            Monster loulo[3] = {
                Monster("海葵",low,7,30),
                Monster("海胆",low,8,28),
                Monster("小海龟",low,8,30)
            };

            cin >> choice;
            while(choice != 1 && choice != 2 && choice != 3)       //选择小怪进行四次战斗
            {
                cout << "请按照要求输入:";
                cin >> choice;
            }
            System.fight(player,loulo[choice - 1]);
            player.refresh();
            loulo[choice - 1].refresh();

            for(int i = 0; i < 3; i++)
            {
                cout << "\n请继续选择一个进行战斗来变得强大.\n";
                cin >> choice;
                while(choice != 1 && choice != 2 && choice != 3)
                {
                    cout << "请按照要求输入:";
                    cin >> choice;
                }

                System.fight(player,loulo[choice - 1]);
                player.refresh();
                loulo[choice - 1].refresh();
            }            //杀够四个小怪，变得稍微强大了
            cout << "蛇青感受到了，自己力量从未像此刻一样强大，他望向亚特兰蒂斯的眼神中多了一丝坚定——\n";
            cout << "“去吧，去复仇，这次你一定可以的”心里有个声音对他大声说。\n";
            cin.get();
            cout <<"\n【亚特兰蒂斯——皇宫正门】\n";
            cout << "\n又是熟悉的场景，只不过这一次你是有备而来。\n";
            cout << "\n守门将士：“怎么还是你？你可真是执着，这次我会让你绝望！”\n";
            System.fight(player,guardian);
            cout << "\n精英队长：“有两下子嘛，接下来就让我来会会你吧！”\n";

            Monster captain("精英队长",high,20,200);
            System.fight(player,captain);
            cout << "\n在无尽的悔恨与绝望中，蛇青闭上了双眼。要是当时选择留在海狮族，可能就不会死了吧….\n";
        }
        
    }   
    }
    return 0;
}

void savePlayer(Player& p )
{
    ofstream outFile("SavePlayer.dat",ios::out|ios::binary);
    outFile.write((char*)&p,sizeof(p));
    outFile.close();
}

void get(Player& p)
{
    ifstream inFile("SavePlayer.dat",ios::in|ios::binary);
    inFile.read((char*)&p,sizeof(p));
    inFile.close();

}

void pointMemory(int n)
{
    ofstream outFile("point.txt",ios::out);
    outFile << n;
}
int getPoint()
{
    ifstream inFile("point.txt",ios::out);
    int n;
    inFile >> n;
    return n;
}

