#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define furthest 5  // ���������Ϊ 5
#define TIMESLICE 3  // ����ʱ��Ƭ����Ϊ 3 ����λʱ��

struct process       /* ���̿��ƿ� (PCB) �ṹ�� */
{
    int id;         // ����ID
    int priority;   // �������ȼ���ʱ��Ƭ��ת��������תʱ��Ƭ����
    int cputime;    // �����Ѿ����е�ʱ��
    int alltime;    // ���������������ʱ��
    char state;     // ����״̬��R:�����У�W:�ȴ��У�F:��ɣ�
    int next;       // ����ָ�룬���ڶ����е���һ����������
} prochain[furthest + 1];  // ����һ����СΪ furthest + 1 �� PCB ����

int procnum;  // �ܽ�����
int algo;     // �����㷨ѡ��
int run, head, tail, j;  // �����еĽ�������������ͷ������β��ѭ������

// ��������
void print();       // ��ӡ����״̬��Ϣ
void insert(int q); // ������̵����ȼ�����
void insert2();     // �����̲������β��
void init();        // ��ʼ�����̺Ͷ���
void prisch();      // ʹ�����ȼ������㷨
void timesch();     // ʹ��ʱ��Ƭ��ת�����㷨

int main()    /* ��������� */
{
    srand((unsigned int)time(NULL));  // �������������

    while (1) {
        printf("��������㷨 (1:RR, 2:PRIO):");  // ��ʾ�û�ѡ������㷨
        scanf("%d", &algo);
        if (algo == 2) {
            printf("ʹ�����ȼ������㷨.\n");
            init();
            prisch();
            break;
        }
        else if (algo == 1) {
            printf("ʹ��ʱ��Ƭ��ת�����㷨.\n");
            init();
            timesch();
            break;
        }
        else {
            printf("������Ч������������\n");
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
    printf("ϵͳ����\n");

    return 0;
}

void print()    /* ��ӡ��ǰ���н��̡��ȴ����к�PCB��Ϣ */
{
    int k, p;
    for (k = 1; k <= 40; k++)
        printf("=");
    printf("\n�����еĽ���                ");
    printf("�ȴ�����");
    printf("\n    %d      ", prochain[run].id);  // ��ӡ��ǰ���еĽ���ID
    p = head;
    while (p != 0) {
        printf("%5d", p);  // ��ӡ�ȴ������еĽ���ID
        p = prochain[p].next;
    }
    printf("\n");
    for (k = 1; k <= 40; k++)
        printf("=");
    printf("\n");
    printf(" id            ");
    for (k = 1; k <= furthest; k++)
        printf("%5d", prochain[k].id);  // ��ӡ���н��̵�ID
    printf("\n");
    printf("���ȼ�         ");
    for (k = 1; k <= furthest; k++)
        printf("%5d", prochain[k].priority);  // ��ӡ���н��̵����ȼ�
    printf("\n");
    printf("CPUʱ��        ");
    for (k = 1; k <= furthest; k++)
        printf("%5d", prochain[k].cputime);  // ��ӡ���н��̵�������ʱ��
    printf("\n");
    printf("��ʱ��         ");
    for (k = 1; k <= furthest; k++)
        printf("%5d", prochain[k].alltime);  // ��ӡ���н��̵�������ʱ��
    printf("\n");
    printf("״̬           ");
    for (k = 1; k <= furthest; k++)
        printf("%5c", prochain[k].state);  // ��ӡ���н��̵�״̬
    printf("\n");
    printf("next           ");
    for (k = 1; k <= furthest; k++)
        printf("%5d", prochain[k].next);  // ��ӡ���н��̵���һ����������
    printf("\n");
}

void insert(int q)      /* �����̲������ȼ����� */
{
    int p, s;
    if (head == 0) {  // ������Ϊ�գ�ֱ�ӽ�������Ϊ����ͷ
        head = q;  // ���½�������Ϊ����ͷ
    }
    else {
        p = head;  // ��ʼ�� p Ϊ��ǰ����ͷ
        s = prochain[head].next;  // ��ʼ�� s Ϊ����ͷ����һ���ڵ�

        // �ҵ��ȵ�ǰ���ȼ��͵�λ�ò���
        while ((s != 0) && (prochain[q].priority < prochain[s].priority)) {
            p = s;  // �ƶ� p ����ǰ�ڵ�
            s = prochain[s].next;  // �ƶ� s ����һ���ڵ�
        }

        // �����½��� q ����ȷ��λ��
        prochain[p].next = q;  // �� p �� next ָ���½��� q
        prochain[q].next = s;  // ���½��� q �� next ָ��ԭ p �� next
    }
}

void insert2()    /* �����̷������β�� */
{
    if (tail == 0) {
        // ����Ϊ�գ�ֱ�ӽ� run ����Ϊͷ��β
        head = run;
        tail = run;
    }
    else {
        // ����ǰ���еĽ������ӵ���ǰ����β��
        prochain[tail].next = run;
        tail = run;
    }
    // ����ǰ���еĽ��̵� next ָ����Ϊ 0����ʾ�����µĶ���β��
    prochain[run].next = 0;
}

void init()     /* ��ʼ�����̶��� */
{
    int i;
    head = 0;
    if (algo == 2) {  // ʹ�����ȼ������㷨
        for (i = 1; i <= furthest; i++) {
            prochain[i].id = i;  // ���ý���ID
            prochain[i].priority = (rand() + 11) % 41;  // ����������ȼ�
            prochain[i].cputime = 0;
            prochain[i].alltime = (rand() + 1) % 7 + 1;  // ���������ʱ��
            prochain[i].state = 'W';  // ��ʼ״̬Ϊ�ȴ�
            prochain[i].next = 0;
            insert(i);  // �������ȼ�����
        }

        // �ҳ����ȼ���ߵĽ���
        int max_priority = -1;
        int max_id;
        for (i = 1; i <= furthest; i++) {
            if (prochain[i].priority > max_priority) {
                max_priority = prochain[i].priority;
                max_id = i;
            }
        }

        // ��Ϊ��ʼ��֮�󣬽���1һ��λ�ڶ���ͷ��

        // ������������ȼ���ߵģ�ֱ��ȡ��һ������
        if (max_id != 1) {
            head = prochain[1].next;
            insert(1);  // Ȼ���ٰ�1���²���ض�����ȷ��λ��
        }

        //  �������1ǡ�������ȼ���ߵģ��Ƕ���˳�򲻱�
    }

    else {  // ʹ��ʱ��Ƭ��ת�����㷨
        for (i = 1; i <= furthest; i++) {
            prochain[i].id = i;
            prochain[i].priority = 0;  // ���������תʱ��Ƭ��
            prochain[i].cputime = 0;
            prochain[i].alltime = (rand() % 7) + 1;  // ���������ʱ��
            prochain[i].state = 'W';  // ��ʼ״̬Ϊ�ȴ�
            prochain[i].next = (i + 1) % (furthest + 1);
            //��һ�д���Ľ��ͣ����� furthest = 5������ 5 �����̣����������� 1 �� 5��
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
    run = head;  // ��ǰ���еĽ���Ϊ����ͷ
    prochain[run].state = 'R';  // ���õ�ǰ���еĽ���״̬Ϊ������
    head = prochain[head].next;
    print();  // ��ӡ��ʼ״̬
    printf("��ʼ����ɣ�\n");
}

void prisch()      /* ʹ�����ȼ������㷨 */
{
    while (run != 0) {
        prochain[run].cputime += 1;  // ���ӵ�ǰ���̵�������ʱ��
        prochain[run].priority -= 3;  // ���ٵ�ǰ���̵����ȼ�
        prochain[run].alltime -= 1;  // ���ٵ�ǰ���̵�������ʱ��
        if (prochain[run].alltime == 0) {  // ����������
            prochain[run].state = 'F';  // ���ý���״̬Ϊ���
            run = (head != 0) ? head : 0;  // ���µ�ǰ���еĽ���
            if (run != 0) {
                prochain[run].state = 'R';  // �����½���״̬Ϊ������
                head = prochain[head].next;
            }
        }
        // �����ǰ���еĽ������ȼ����ڵȴ�����ͷ�����̵����ȼ������ҵȴ����в�Ϊ��
        else if ((prochain[run].priority < prochain[head].priority) && (head != 0)) {
            prochain[run].state = 'W';  // ���õ�ǰ����״̬Ϊ�ȴ�
            insert(run);  // ����ǰ���̲������ȼ�����
            run = head;  // ���µ�ǰ���еĽ���
            if (run != 0) {
                prochain[run].state = 'R';  // �����½���״̬Ϊ������
                head = prochain[head].next;
            }
        }
        print();  // ��ӡ��ǰ״̬
    }
}

void timesch()      /* ʹ��ʱ��Ƭ��ת�����㷨 */
{
    while (run != 0) {
        int time_left = TIMESLICE;  // ÿ�ε��ȵ�ʱ��Ƭ����
        while (time_left > 0 && run != 0) {  // ��ʱ��Ƭδ�����һ��н���������
            if (prochain[run].alltime > 0) {  // �������δ���
                prochain[run].alltime -= 1;  // ���ٵ�ǰ���̵�������ʱ��
                prochain[run].cputime += 1;  // ���ӵ�ǰ���̵�������ʱ��
                time_left--;  // ����ʣ��ʱ��Ƭ
            }
            if (prochain[run].alltime == 0) {  // ���������ɣ�����ʱ��Ƭ�Ƿ�����
                prochain[run].state = 'F';  // ���ý���״̬Ϊ���
                run = (head != 0) ? head : 0;  // ���µ�ǰ���еĽ���
                if (run != 0) {
                    prochain[run].state = 'R';  // �����½���״̬Ϊ������
                    head = prochain[head].next;
                }
                time_left = TIMESLICE;  // ����ʱ��Ƭ
            }
            else if (time_left == 0 && (head != 0)) {  // ���ʱ��Ƭ���굫����δ����ҵȴ����в�Ϊ��
                prochain[run].state = 'W';  // ���õ�ǰ����״̬Ϊ�ȴ�
                insert2();  // ����ǰ���̲������β��
                run = head;  // ���µ�ǰ���еĽ���
                if (run != 0) {
                    prochain[run].state = 'R';  // �����½���״̬Ϊ������
                    head = prochain[head].next;
                }
                time_left = TIMESLICE;  // ����ʱ��Ƭ
            }
            print();  // ��ӡ��ǰ״̬
        }
    }
}