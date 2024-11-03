#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define furthest 5  // 定义进程数为 5
#define TIMESLICE 3  // 定义时间片长度为 3 个单位时间

struct process       /* 进程控制块 (PCB) 结构体 */
{
    int id;         // 进程ID
    int priority;   // 进程优先级（时间片轮转中用作轮转时间片数）
    int cputime;    // 进程已经运行的时间
    int alltime;    // 进程所需的总运行时间
    char state;     // 进程状态（R:运行中，W:等待中，F:完成）
    int next;       // 链表指针，用于队列中的下一个进程索引
} prochain[furthest + 1];  // 定义一个大小为 furthest + 1 的 PCB 数组

int procnum;  // 总进程数
int algo;     // 调度算法选择
int run, head, tail, j;  // 运行中的进程索引、队列头、队列尾、循环变量

// 函数声明
void print();       // 打印进程状态信息
void insert(int q); // 插入进程到优先级队列
void insert2();     // 将进程插入队列尾部
void init();        // 初始化进程和队列
void prisch();      // 使用优先级调度算法
void timesch();     // 使用时间片轮转调度算法

int main()    /* 主程序入口 */
{
    srand((unsigned int)time(NULL));  // 设置随机数种子

    while (1) {
        printf("输入调度算法 (1:RR, 2:PRIO):");  // 提示用户选择调度算法
        scanf("%d", &algo);
        if (algo == 2) {
            printf("使用优先级调度算法.\n");
            init();
            prisch();
            break;
        }
        else if (algo == 1) {
            printf("使用时间片轮转调度算法.\n");
            init();
            timesch();
            break;
        }
        else {
            printf("输入无效，请重新输入\n");
        }
    }

    for (j = 1; j <= 40; j++) {
        printf("=");
    }
    printf("\n\n");
    for (j = 1; j <= 40; j++) {
        printf("=");
    }
    printf("\n\n");
    printf("系统结束\n");

    return 0;
}

void print()    /* 打印当前运行进程、等待队列和PCB信息 */
{
    int k, p;
    for (k = 1; k <= 40; k++)
        printf("=");
    printf("\n运行中的进程                ");
    printf("等待队列");
    printf("\n    %d      ", prochain[run].id);  // 打印当前运行的进程ID
    p = head;
    while (p != 0) {
        printf("%5d", p);  // 打印等待队列中的进程ID
        p = prochain[p].next;
    }
    printf("\n");
    for (k = 1; k <= 40; k++)
        printf("=");
    printf("\n");
    printf(" id            ");
    for (k = 1; k <= furthest; k++)
        printf("%5d", prochain[k].id);  // 打印所有进程的ID
    printf("\n");
    printf("优先级         ");
    for (k = 1; k <= furthest; k++)
        printf("%5d", prochain[k].priority);  // 打印所有进程的优先级
    printf("\n");
    printf("CPU时间        ");
    for (k = 1; k <= furthest; k++)
        printf("%5d", prochain[k].cputime);  // 打印所有进程的已运行时间
    printf("\n");
    printf("总时间         ");
    for (k = 1; k <= furthest; k++)
        printf("%5d", prochain[k].alltime);  // 打印所有进程的总运行时间
    printf("\n");
    printf("状态           ");
    for (k = 1; k <= furthest; k++)
        printf("%5c", prochain[k].state);  // 打印所有进程的状态
    printf("\n");
    printf("next           ");
    for (k = 1; k <= furthest; k++)
        printf("%5d", prochain[k].next);  // 打印所有进程的下一个进程索引
    printf("\n");
}

void insert(int q)      /* 将进程插入优先级队列 */
{
    int p, s;
    if (head == 0) {  // 若队列为空，直接将进程设为队列头
        head = q;  // 将新进程设置为队列头
    }
    else {
        p = head;  // 初始化 p 为当前队列头
        s = prochain[head].next;  // 初始化 s 为队列头的下一个节点

        // 找到比当前优先级低的位置插入
        while ((s != 0) && (prochain[q].priority < prochain[s].priority)) {
            p = s;  // 移动 p 到当前节点
            s = prochain[s].next;  // 移动 s 到下一个节点
        }

        // 插入新进程 q 到正确的位置
        prochain[p].next = q;  // 将 p 的 next 指向新进程 q
        prochain[q].next = s;  // 将新进程 q 的 next 指向原 p 的 next
    }
}

void insert2()    /* 将进程放入队列尾部 */
{
    if (tail == 0) {
        // 队列为空，直接将 run 设置为头和尾
        head = run;
        tail = run;
    }
    else {
        // 将当前运行的进程链接到当前队列尾部
        prochain[tail].next = run;
        tail = run;
    }
    // 将当前运行的进程的 next 指针设为 0，表示它是新的队列尾部
    prochain[run].next = 0;
}

void init()     /* 初始化进程队列 */
{
    int i;
    head = 0;
    if (algo == 2) {  // 使用优先级调度算法
        for (i = 1; i <= furthest; i++) {
            prochain[i].id = i;  // 设置进程ID
            prochain[i].priority = (rand() + 11) % 41;  // 随机生成优先级
            prochain[i].cputime = 0;
            prochain[i].alltime = (rand() + 1) % 7 + 1;  // 随机生成总时间
            prochain[i].state = 'W';  // 初始状态为等待
            prochain[i].next = 0;
            insert(i);  // 插入优先级队列
        }

        // 找出优先级最高的进程
        int max_priority = -1;
        int max_id;
        for (i = 1; i <= furthest; i++) {
            if (prochain[i].priority > max_priority) {
                max_priority = prochain[i].priority;
                max_id = i;
            }
        }

        // 因为初始化之后，进程1一定位于队列头部

        // 如果它不是优先级最高的，直接取下一个进程
        if (max_id != 1) {
            head = prochain[1].next;
            insert(1);  // 然后再把1重新插入回队列正确的位置
        }

        //  如果进程1恰巧是优先级最高的，那队列顺序不变
    }

    else {  // 使用时间片轮转调度算法
        for (i = 1; i <= furthest; i++) {
            prochain[i].id = i;
            prochain[i].priority = 0;  // 随机生成轮转时间片数
            prochain[i].cputime = 0;
            prochain[i].alltime = (rand() % 7) + 1;  // 随机生成总时间
            prochain[i].state = 'W';  // 初始状态为等待
            prochain[i].next = (i + 1) % (furthest + 1);
            //上一行代码的解释：假设 furthest = 5，即有 5 个进程，进程索引从 1 到 5：
            //                  prochain[1].next = (1 + 1) % 6 = 2
            //                  prochain[2].next = (2 + 1) % 6 = 3
            //                  prochain[3].next = (3 + 1) % 6 = 4
            //                  prochain[4].next = (4 + 1) % 6 = 5
            //                  prochain[5].next = (5 + 1) % 6 = 0
        }
        head = 1;
        tail = furthest;
        prochain[furthest].next = 0;
    }
    run = head;  // 当前运行的进程为队列头
    prochain[run].state = 'R';  // 设置当前运行的进程状态为运行中
    head = prochain[head].next;
    print();  // 打印初始状态
    printf("初始化完成！\n");
}

void prisch()      /* 使用优先级调度算法 */
{
    while (run != 0) {
        prochain[run].cputime += 1;  // 增加当前进程的已运行时间
        prochain[run].priority -= 3;  // 减少当前进程的优先级
        prochain[run].alltime -= 1;  // 减少当前进程的总运行时间
        if (prochain[run].alltime == 0) {  // 如果进程完成
            prochain[run].state = 'F';  // 设置进程状态为完成
            run = (head != 0) ? head : 0;  // 更新当前运行的进程
            if (run != 0) {
                prochain[run].state = 'R';  // 设置新进程状态为运行中
                head = prochain[head].next;
            }
        }
        // 如果当前运行的进程优先级低于等待队列头部进程的优先级，并且等待队列不为空
        else if ((prochain[run].priority < prochain[head].priority) && (head != 0)) {
            prochain[run].state = 'W';  // 设置当前进程状态为等待
            insert(run);  // 将当前进程插入优先级队列
            run = head;  // 更新当前运行的进程
            if (run != 0) {
                prochain[run].state = 'R';  // 设置新进程状态为运行中
                head = prochain[head].next;
            }
        }
        print();  // 打印当前状态
    }
}

void timesch()      /* 使用时间片轮转调度算法 */
{
    while (run != 0) {
        int time_left = TIMESLICE;  // 每次调度的时间片长度
        while (time_left > 0 && run != 0) {  // 当时间片未用完且还有进程在运行
            if (prochain[run].alltime > 0) {  // 如果进程未完成
                prochain[run].alltime -= 1;  // 减少当前进程的总运行时间
                prochain[run].cputime += 1;  // 增加当前进程的已运行时间
                time_left--;  // 减少剩余时间片
            }
            if (prochain[run].alltime == 0) {  // 如果进程完成，无论时间片是否用完
                prochain[run].state = 'F';  // 设置进程状态为完成
                run = (head != 0) ? head : 0;  // 更新当前运行的进程
                if (run != 0) {
                    prochain[run].state = 'R';  // 设置新进程状态为运行中
                    head = prochain[head].next;
                }
                time_left = TIMESLICE;  // 重置时间片
            }
            else if (time_left == 0 && (head != 0)) {  // 如果时间片用完但进程未完成且等待队列不为空
                prochain[run].state = 'W';  // 设置当前进程状态为等待
                insert2();  // 将当前进程插入队列尾部
                run = head;  // 更新当前运行的进程
                if (run != 0) {
                    prochain[run].state = 'R';  // 设置新进程状态为运行中
                    head = prochain[head].next;
                }
                time_left = TIMESLICE;  // 重置时间片
            }
            print();  // 打印当前状态
        }
    }
}