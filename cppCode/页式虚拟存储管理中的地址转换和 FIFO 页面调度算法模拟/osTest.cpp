#include<stdio.h>
#include<stdlib.h>

// 定义页表长度为7
#define Pnum 7
// 定义主存块数为10
#define Mnum 10
// 定义指令集总数为12
#define Onum 12

// 页表结构体定义
// 用于存储页表相关信息，每个页表项包含以下成员：
struct Page_table
{
    int pageNumber; // 页号，用于标识不同的页面
    int memoryBlock; // 主存块号，记录该页在主存中对应的块号
    int flag;  // 标志位，0表示页不在主存，1表示页在主存
    int diskLocation; // 磁盘位置，记录该页在磁盘中的存储位置
    int modifyFlag; // 修改标志，0表示未修改，1表示已修改，用于跟踪页面是否被修改过
} page_table[Pnum];

// 指令表结构体定义
// 用于存储指令相关信息，每个指令项包含以下成员：
struct Order_table
{
    int pageNumber; // 页号，指令所在的页面号
    int offset;// 单元号，在页面内的偏移量
    char operation; // 操作，如存、取、移位等操作类型
} Order_table[Onum];

// 全局变量，用于保存被FIFO算法置换出的页号，初始化为 -1
int before_page = -1;

// 数组用于模拟主存的使用情况，数组下标表示块号，对应值为0表示未使用，
// 全部主存占用情况，1模拟被非页占用，2模拟内存分配给模拟作业的块数，本次模拟分配4块，块号依次为1，5，8，9
int Memory_uesd[Mnum] = { 1, 0, 1, 1, 1, 0, 1, 1, 0, 0 };

// 为本作业分配的主存位置，表示已被装入内存的页号，共四个位置，初始默认0，1，2，3页已装入，若未装入，则用 -1占位
int Memory_list[4] = { 0, 1, 2, 3 };

// 函数功能：打印当前页表的详细信息
// 包括页号、块号、标志位、磁盘位置以及修改标志等内容
void show_page_table()
{
    printf("【页表】:\n");
    int i = 0;
    // 遍历页表数组，逐个打印页表项的信息
    for (i; i < Pnum; i++)
    {
        printf("页号:%d", page_table[i].pageNumber);
        printf("  块号:%2d", page_table[i].memoryBlock);
        printf("  标志位:%d", page_table[i].flag);
        printf("  磁盘位置:%.3d", page_table[i].diskLocation);
        printf("  修改标志:%d\n", page_table[i].modifyFlag);
    }
    printf("\n");
}

// 函数功能：打印已装入内存的页及其对应在内存中的块号
// 只有当Memory_list中的页号不为 -1时，才打印相关信息
void show_Memory_list()
{
    int i = 0;
    for (i; i < 4; i++)
    {
        if (Memory_list[i] != -1)
        {
            // 打印格式：【在Memory_list中的下标】:第【页号】页-->第【块号】块
            printf("【%d】:第%d页-->第【%d】块\n", i, Memory_list[i], page_table[Memory_list[i]].memoryBlock);
        }
    }
}

// 函数功能：对指令集进行初始化操作
// 设置指令集中每条指令的操作类型、页号和偏移量等信息
void Order_init()
{
    // 逻辑地址由页号和偏移量组成
    // 设置指令集，以下分别设置各条指令的相关属性
    Order_table[0].operation = 'C'; Order_table[0].pageNumber = 0; Order_table[0].offset = 70;
    Order_table[1].operation = '+'; Order_table[1].pageNumber = 1; Order_table[1].offset = 50;
    Order_table[2].operation = 'X'; Order_table[2].pageNumber = 2; Order_table[2].offset = 15;
    Order_table[3].operation = 'C'; Order_table[3].pageNumber = 3; Order_table[3].offset = 21;
    Order_table[4].operation = 'Q'; Order_table[4].pageNumber = 0; Order_table[4].offset = 56;
    Order_table[5].operation = '-'; Order_table[5].pageNumber = 6; Order_table[5].offset = 40;
    Order_table[6].operation = 'Y'; Order_table[6].pageNumber = 4; Order_table[6].offset = 53;
    Order_table[7].operation = '+'; Order_table[7].pageNumber = 5; Order_table[7].offset = 23;
    Order_table[8].operation = 'C'; Order_table[8].pageNumber = 1; Order_table[8].offset = 37;
    Order_table[9].operation = 'Q'; Order_table[9].pageNumber = 2; Order_table[9].offset = 78;
    Order_table[10].operation = '+'; Order_table[10].pageNumber = 4; Order_table[10].offset = 1;
    Order_table[11].operation = 'C'; Order_table[11].pageNumber = 6; Order_table[11].offset = 84;
}

// 函数功能：进行系统初始化操作
// 包括页表的页号初始化，以及假设0 - 3号页已装入主存的相关设置，同时更新主存使用情况数组
void initial()
{
    // pageNumber初始化，将页表中每个页表项的页号设置为其在数组中的下标值
    int i = 0;
    for (i = 0; i < Pnum; i++)
    {
        page_table[i].pageNumber = i;
    }

    // 初始化假设0 - 3号页已装入主存，设置相关标志位及其他信息，并更新Memory_used[]数组
    // 第0页的初始化设置
    page_table[0].flag = 1;
    page_table[0].memoryBlock = 5;
    page_table[0].diskLocation = 11;
    page_table[0].modifyFlag = 1; // 初始化页号0的修改标志为1，表示已修改过（初始状态下就有修改情况）
    // 第1页的初始化设置
    page_table[1].flag = 1;
    page_table[1].memoryBlock = 8;
    page_table[1].diskLocation = 12;
    page_table[1].modifyFlag = 0;
    // 第2页的初始化设置
    page_table[2].flag = 1;
    page_table[2].memoryBlock = 9;
    page_table[2].diskLocation = 13;
    page_table[2].modifyFlag = 0;
    // 第3页的初始化设置
    page_table[3].flag = 1;
    page_table[3].memoryBlock = 1;
    page_table[3].diskLocation = 21;
    page_table[3].modifyFlag = 0;
    // 第4页的初始化设置
    page_table[4].flag = 0;
    page_table[4].memoryBlock = -1;
    page_table[4].diskLocation = 22;
    page_table[4].modifyFlag = 0;
    // 第5页的初始化设置
    page_table[5].flag = 0;
    page_table[5].memoryBlock = -1;
    page_table[5].diskLocation = 23;
    page_table[5].modifyFlag = 0;
    // 第6页的初始化设置
    page_table[6].flag = 0;
    page_table[6].memoryBlock = -1;
    page_table[6].diskLocation = 121;
    page_table[6].modifyFlag = 0;

    // 模拟预装入过程，更新Memory_used数组中对应块号的使用情况为已被作业使用（值设为2）
    Memory_uesd[1] = 2;
    Memory_uesd[5] = 2;
    Memory_uesd[8] = 2;
    Memory_uesd[9] = 2;
}

// 函数功能：判断指定的页号是否已装入内存
// 返回值：如果页已装入内存返回1，否则返回 -1
int check_inMemory(int page)
{
    int flag = -1;
    if (page_table[page].flag == 1)
    {
        flag = 1;
    }
    return flag;
}

// 函数功能：找到为本作业分配的模拟主存中第一个空闲格的下标并返回
// 如果未找到空闲格（即表已满），则返回 -1
int check_fullList()
{
    int flag = -1;
    int i = 0;
    // 遍历memory_list数组，查找值为 -1的元素，找到则返回其下标
    for (i; i < 4; i++)
    {
        if (Memory_list[i] == -1) //找到第一个空块，并返回其下标
        {
            flag = i;
            break;
        }
    }
    return flag;
}

// 函数功能：找到全部模拟内存中第一个空闲块的下标并返回
// 如果未找到空闲块（即内存已全被使用），则返回 -1
int check_fullBlock()
{
    int flag = -1;
    int i = 0;
    // 遍历Memory_uesd数组，查找值为0的元素，找到则返回其下标
    for (i; i < Mnum; i++)
    {
        if (Memory_uesd[i] == 0)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

// 函数功能：实现先进先出页面置换算法
// 传入参数为本次要置换的页面号
// 算法过程：将最早进入内存的页面置换出去，将新页面插入到内存中相应位置，并更新页表相关信息
void FIFO(int page)
{
    int i = 1;
    before_page = Memory_list[0];//保存被置换页号，即当前内存中最早进入的页号
    for (i = 1; i < 4; i++)
    {
        Memory_list[i - 1] = Memory_list[i];  //向前位移一位，将内存中的页面顺序向前移动一位
    }
    Memory_list[3] = page; //插入新页，将新页面插入到内存列表的最后一个位置
    //更新页表相关信息
    page_table[page].memoryBlock = page_table[before_page].memoryBlock;//将新页的块号设置为被置换页的块号
    page_table[page].flag = 1;//表示新页已装入内存
    page_table[before_page].memoryBlock = -1;//置为 -1表示该页不存在对应主存块号，即已被置换出内存
    page_table[before_page].flag = 0;//表示未装入内存
    page_table[page].modifyFlag = 0; // 新增：进程调出内存时，将新装入页的修改标志初始化为0，表示刚装入未修改
    page_table[before_page].modifyFlag = 0; // 新增：进程调出内存时，将被置换出页的修改标志初始化为0，表示已置换出未修改
}

// 函数功能：将指令集中某些操作字符转换成中文并打印提示信息
// 传入参数i为指令集内指令序号
void operation_change(int i)
{
    if (Order_table[i].operation == 'C')
    {
        printf("【提示】操作为:存\n"); //模拟操作，将'C'操作转换为中文“存”并打印提示
    }
    else if (Order_table[i].operation == 'Q')
    {
        printf("【提示】操作为:取\n"); //模拟操作，将'Q'操作转换为中文“取”并打印提示
    }
    else if (Order_table[i].operation == 'Y')
    {
        printf("【提示】操作为:移位\n"); //模拟操作，将'Y'操作转换为中文“移位”并打印提示
    }
    else
    {
        printf("【提示】操作为:%c\n", Order_table[i].operation); //模拟操作，对于其他操作字符，直接打印其字符表示操作
    }
}

// 函数功能：运行函数，模拟指令的执行过程，处理页面命中、缺页中断等情况，并根据需要调用页面置换算法
void Running()
{
    //获取页面请求序列，程序默认采用Order中顺序
    int i = 0;
    int flag = 0; //表示第i条指令对应的页号是否装入内存，0表示未装入，1表示已装入
    int page_in = 0; //表示插入Memory_list的下标（块号），用于在内存列表中插入新页
    int block_in = 0; //表示插入Memory_used的下标（块号），用于在主存使用情况数组中标记新使用的块
    for (i; i < Onum; i++)
    {
        if (check_inMemory(Order_table[i].pageNumber) == 1)
        {
            // 如果指令对应的页号已在内存中，形成物理地址并打印相关信息
            printf("【指令】第%d条指令对应页号命中，形成物理地址:%4d", i + 1, page_table[Order_table[i].pageNumber].memoryBlock * 1024 + Order_table[i].offset);
            operation_change(i);
        }
        if (check_inMemory(Order_table[i].pageNumber) == -1)
        {
            printf("\n[-----------------【页面中断程序】---------------]\n");
            printf("【指令】第%d条指令执行产生缺页中断，中断页号为：%d\n", i + 1, Order_table[i].pageNumber);
            // 判断内存是否已满
            if (check_fullBlock() == -1) //内存全使用，没有空闲块，调用FIFO算法进行页面置换
            {
                printf("【提示】");
                if (page_table[Memory_list[0]].modifyFlag == 1) {
                    printf("已进行页面置换,置换出的页号为：%d,", Memory_list[0]);
                }
                FIFO(Order_table[i].pageNumber);
                printf("装入的页号为：%d\n", Order_table[i].pageNumber);
                printf("【提示】此时装入内存中的页为:\n");
                show_Memory_list();
            }
            else //内存未完全使用，选择空闲块将页装入内存
            {
                page_in = check_fullList();
                Memory_list[page_in] = Order_table[i].pageNumber;
                block_in = check_fullBlock();
                page_table[Order_table[i].pageNumber].flag = 1;
                page_table[Order_table[i].pageNumber].memoryBlock = block_in;
                printf("【提示】已将中断页装入内存,装入的页号为：%d\n", Order_table[i].pageNumber);
                printf("此时装入内存中的页为:\n");
                show_Memory_list();
            }
            printf("【提示】中断执行后对应的物理地址为:%d", page_table[Order_table[i].pageNumber].memoryBlock * 1024 + Order_table[i].offset);
            operation_change(i);
            printf("[-----------------【页面中断程序】---------------]\n");
        }

        // 新增：执行存操作时，修改对应的修改标志为1，表示该页已被修改
        if (Order_table[i].operation == 'C')
        {
            page_table[Order_table[i].pageNumber].modifyFlag = 1;
        }

        // 在每次操作后显示当前页表状态，方便查看页表的实时变化情况
        show_page_table();
    }
}

int main()
{
    Order_init(); // 指令集初始化，设置指令集中各条指令的相关信息
    initial(); // 作业初始化，包括页表初始化和假设部分页已装入主存的设置等
    show_page_table(); // 打印初始页表，展示系统初始状态下的页表信息
    Running(); // 运行函数，模拟指令执行过程，处理页面相关情况
    system("pause");
    return 0;
}