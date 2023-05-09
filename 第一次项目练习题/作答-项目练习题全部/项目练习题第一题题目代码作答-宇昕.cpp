#include <iostream>

using namespace std;

// -------------------- 数据设计 --------------------
/*
    棋盘:
        map[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: map[3][6] = 1 表示(3,6)的位置是黑子
*/
int map[19][19]; //棋盘大小

// 表示当前回合数 偶数表示黑棋落子 奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子 由黑方落子

int flag; //次数

// -------------------- 数据设计 --------------------


// -------------------- service --------------------
/*
    负责人: 张三
    功能:
        初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
 */
void init(int map[][19], int* flag)
{
    //遍历棋盘,初始化
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            map[i][j] = 0;
        }
    }
    //初始化盘数
    *flag = 0;
}

/*
    *难点1
    负责人: 张三
    功能: 根据传入的坐标(map对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y)
{

    if (x + 4 <= 18) //如果右边有可能胜利进行判断
    {
        if (map[x][y] == 1 && map[x + 1][y] == 1 && map[x + 2][y] == 1 && map[x + 3][y] == 1 && map[x + 4][y] == 1)
        {
            return 1;
        }
        if (map[x][y] == 2 && map[x + 1][y] == 2 && map[x + 2][y] == 2 && map[x + 3][y] == 2 && map[x + 4][y] == 2)
        {
            return 2;
        }
    }
    if (x - 4 >= 0) //如果左边有可能胜利进行判断
    {
        if (map[x][y] == 1 && map[x - 1][y] == 1 && map[x - 2][y] == 1 && map[x - 3][y] == 1 && map[x - 4][y] == 1)
        {
            return 1;
        }
        if (map[x][y] == 2 && map[x - 1][y] == 2 && map[x - 2][y] == 2 && map[x - 3][y] == 2 && map[x - 4][y] == 2)
        {
            return 2;
        }
    }
    if (y + 4 <= 18) //如果上边有可能胜利进行判断
    {
        if (map[x][y] == 1 && map[x][y + 1] == 1 && map[x][y + 2] == 1 && map[x][y + 3] == 1 && map[x][y + 4] == 1)
        {
            return 1;
        }
        if (map[x][y] == 2 && map[x][y + 1] == 2 && map[x][y + 2] == 2 && map[x][y + 3] == 2 && map[x][y + 4] == 2)
        {
            return 2;
        }
    }
    if (y - 4 >= 0) //如果下边有可能胜利进行判断
    {
        if (map[x][y] == 1 && map[x][y - 1] == 1 && map[x][y - 2] == 1 && map[x][y - 3] == 1 && map[x][y - 4] == 1)
        {
            return 1;
        }
        if (map[x][y] == 2 && map[x][y - 1] == 2 && map[x][y - 2] == 2 && map[x][y - 3] == 2 && map[x][y - 4] == 2)
        {
            return 2;
        }
    }
    if (x + 4 <= 18 && y + 4 <= 18) //如果右上有可能胜利进行判断
    {
        if (map[x][y] == 1 && map[x + 1][y + 1] == 1 && map[x + 2][y + 2] == 1 && map[x + 3][y + 3] == 1 && map[x + 4][y + 4] == 1)
        {
            return 1;
        }
        if (map[x][y] == 2 && map[x + 1][y + 1] == 2 && map[x + 2][y + 2] == 2 && map[x + 3][y + 3] == 2 && map[x + 4][y + 4] == 2)
        {
            return 2;
        }
    }
    if (x - 4 >= 0 && y + 4 <= 18) //如果左上有可能胜利进行判断
    {
        if (map[x][y] == 1 && map[x - 1][y + 1] == 1 && map[x - 2][y + 2] == 1 && map[x - 3][y + 3] == 1 && map[x - 4][y + 4] == 1)
        {
            return 1;
        }
        if (map[x][y] == 2 && map[x - 1][y + 1] == 2 && map[x - 2][y + 2] == 2 && map[x - 3][y + 3] == 2 && map[x - 4][y + 4] == 2)
        {
            return 2;
        }
    }
    if (x - 4 >= 0 && y - 4 >= 0) //如果左下有可能胜利进行判断
    {
        if (map[x][y] == 1 && map[x - 1][y - 1] == 1 && map[x - 2][y - 2] == 1 && map[x - 3][y - 3] == 1 && map[x - 4][y - 4] == 1)
        {
            return 1;
        }
        if (map[x][y] == 2 && map[x - 1][y - 1] == 2 && map[x - 2][y - 2] == 2 && map[x - 3][y - 3] == 2 && map[x - 4][y - 4] == 2)
        {
            return 2;
        }
    }
    if (x + 4 <= 18 && y - 4 >= 0) //如果右下有可能胜利进行判断
    {
        if (map[x][y] == 1 && map[x + 1][y - 1] == 1 && map[x + 2][y - 2] == 1 && map[x + 3][y - 3] == 1 && map[x + 4][y - 4] == 1)
        {
            return 1;
        }
        if (map[x][y] == 2 && map[x + 1][y - 1] == 2 && map[x + 2][y - 2] == 2 && map[x + 3][y - 3] == 2 && map[x + 4][y - 4] == 2)
        {
            return 2;
        }
    }

    else //没人胜利
    {
        return 0;
    }
}



/*
    负责人: 张三
    功能: 在指定位置落子
        如果map[x][y]是空地 则修改map[x][y]的值:改为相应颜色(flag对应颜色)
        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功
*/
int playerMove(int x, int y)
{
    if (map[x][y] == 0) //确定指定位置空
    {

        if (flag % 2 == 0) //小黑子
        {
            map[x][y] = 1;
        }
        else  //白子
        {
            map[x][y] = 2;
        }
        return 1;
    }
    else //指定位置有棋子
    {
        return 0;
    }
}
// -------------------- service --------------------


// -------------------- view --------------------
/*
    功能: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        进入游戏: 调用游戏界面函数gameView();
        进入设置: 敬请期待...
        退出游戏: 调用exit(0);
*/

void gameView(); //声明一下gameView函数,menuView要用

void menuView()
{
VIEW:
    cout << "1.进入游戏" << endl;
    cout << "2.进入设置" << endl;
    cout << "3.退出游戏" << endl;
    cout << "请输入序号进行选择：" << endl;

    int choice = 0; //玩家界面选择的序号
    int temp = 0; //临时变量

    cin >> choice;

    if (choice == 1) //玩家选择1
    {
        gameView();  //显示游戏页面
    }

    if (choice == 2) //玩家选择2
    {
        cout << "敬请期待..." << endl;  //提示

        system("pause");

        goto VIEW;  //回到菜单
    }
    if (choice == 3) //玩家选择3
    {
        exit(0);  //退出游戏
    }
    else
    {
        cout << "输入错误，请重新输入正确的序号：" << endl; //提示

        goto VIEW;  //回到菜单
    }
}

/*
    负责人: 张三
    功能: 根据map数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowMap() //由于棋子0,1,2,暂不考虑对齐
{
    for (int i = 0; i < 19; i++) //输出列
    {
        for (int j = 0; j < 19; j++)
        {
            cout << map[i][j] << " "; //输出行
        }
        cout << endl;
    }
}

/*
    负责人: 张三
    功能: 根据flag的值 打印游戏胜利界面 用户可以按任意键回到主菜单
    参数: void
    返回值: void
 */

void winView()
{
    if (flag % 2 == 1) //黑棋胜利
    {
        cout << "经过" << flag << "回合后" << endl;
        cout << "+------------------------+" << endl;
        cout << "|                        |" << endl;
        cout << "|    恭喜 黑棋 胜利！    |" << endl;
        cout << "|                        |" << endl;
        cout << "+------------------------+" << endl;
    }
    else //白旗胜利
    {
        cout << "经过" << flag << "回合后" << endl;
        cout << "+------------------------+" << endl;
        cout << "|                        |" << endl;
        cout << "|    恭喜 白旗 胜利！    |" << endl;
        cout << "|                        |" << endl;
        cout << "+------------------------+" << endl;
    }

    system("pause"); //按任意键继续

    //用户回到主菜单在这里我不会实现
}

/*
    *难点2
    负责人: 张三
    功能: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowMap())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
*/
void gameView()
{

    init(map, &flag); //初始化

    while (1) //循环
    {
        flag += 1; //确定当前局数 / 切换玩家

        int x = 0, y = 0; //初始化x y

        gameView_ShowMap(); //打印游戏界面-棋盘

    REIN:
        if (flag % 2 == 0) //黑棋下
        {
            cout << "请 黑棋 输入坐标 x 和 y （中间用一个空格分开）后回车" << endl;
            cin >> x;
            cin >> y;
        }
        if (flag % 2 == 1) //白旗下
        {
            cout << "请 白棋 输入坐标 x 和 y （中间用一个空格分开）后回车" << endl;
            cin >> x;
            cin >> y;
        }

        playerMove(x, y); //玩家落子

        if (playerMove(x, y) == 0) //玩家落子失败
        {
            cout << "落子失败，请重新输入：" << endl;
            goto REIN;
        }

        if (isWin(x, y) != 0) //玩家胜利
        {
            winView();
            break;
        }

    }

}
// -------------------- view --------------------

int main() {
    int testflag = 0;

    // init测试代码
    init(map, &flag);
    if (flag != 0) {
        printf("init()错误");
        exit(0);
    }
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (map[i][j]) {
                printf("init()错误");
                exit(0);
            }
        }
    }
    printf("init()测试成功\n");
    testflag++;

    // playerMove测试代码
    int result = 1;
    result &= playerMove(2, 2);
    result &= playerMove(2, 3);
    result &= playerMove(2, 4);
    result &= playerMove(2, 5);
    if (result != 1 || (map[2][2] & map[2][3] & map[2][4] & map[2][5]) != 1) {
        printf("playerMove()错误");
        exit(0);
    }
    flag = 1;
    result &= playerMove(2, 5);
    if (result != 0 || map[2][5] != 1) {
        printf("playerMove()错误");
        exit(0);
    }
    printf("playerMove()测试成功\n");
    testflag++;

    // isWin测试代码
    playerMove(2, 1);
    if (isWin(2, 1)) {
        printf("isWin()错误");
        exit(0);
    }
    playerMove(1, 0);
    playerMove(3, 2);
    playerMove(4, 3);
    playerMove(5, 4);
    if (isWin(1, 0) != 2) {
        printf("isWin()错误");
        exit(0);
    }
    printf("isWin()测试成功\n");
    testflag++;
    if (testflag == 3) {
        printf("service代码测试成功\n");
    }
    return 0;
}

//------------------------------
//代码实现在上面了
//------------------------------

//void init()
//{
//    //代码实现
//}
//
//int isWin(int x, int y)
//{
//    //代码实现
//}
//
//int playerMove(int x, int y)
//{
//    //代码实现
//}
//
//void menuView()
//{
//    //代码实现
//}
//
//void gameView_ShowMap()
//{
//    //代码实现
//}
//
//void winView()
//{
//    //代码实现
//}
//
//void gameView()
//{
//    //代码实现
//}