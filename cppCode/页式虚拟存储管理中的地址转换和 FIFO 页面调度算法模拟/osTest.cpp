#include<stdio.h>
#include<stdlib.h>

// ����ҳ����Ϊ7
#define Pnum 7
// �����������Ϊ10
#define Mnum 10
// ����ָ�����Ϊ12
#define Onum 12

// ҳ��ṹ�嶨��
// ���ڴ洢ҳ�������Ϣ��ÿ��ҳ����������³�Ա��
struct Page_table
{
    int pageNumber; // ҳ�ţ����ڱ�ʶ��ͬ��ҳ��
    int memoryBlock; // �����ţ���¼��ҳ�������ж�Ӧ�Ŀ��
    int flag;  // ��־λ��0��ʾҳ�������棬1��ʾҳ������
    int diskLocation; // ����λ�ã���¼��ҳ�ڴ����еĴ洢λ��
    int modifyFlag; // �޸ı�־��0��ʾδ�޸ģ�1��ʾ���޸ģ����ڸ���ҳ���Ƿ��޸Ĺ�
} page_table[Pnum];

// ָ���ṹ�嶨��
// ���ڴ洢ָ�������Ϣ��ÿ��ָ����������³�Ա��
struct Order_table
{
    int pageNumber; // ҳ�ţ�ָ�����ڵ�ҳ���
    int offset;// ��Ԫ�ţ���ҳ���ڵ�ƫ����
    char operation; // ��������桢ȡ����λ�Ȳ�������
} Order_table[Onum];

// ȫ�ֱ��������ڱ��汻FIFO�㷨�û�����ҳ�ţ���ʼ��Ϊ -1
int before_page = -1;

// ��������ģ�������ʹ������������±��ʾ��ţ���ӦֵΪ0��ʾδʹ�ã�
// ȫ������ռ�������1ģ�ⱻ��ҳռ�ã�2ģ���ڴ�����ģ����ҵ�Ŀ���������ģ�����4�飬�������Ϊ1��5��8��9
int Memory_uesd[Mnum] = { 1, 0, 1, 1, 1, 0, 1, 1, 0, 0 };

// Ϊ����ҵ���������λ�ã���ʾ�ѱ�װ���ڴ��ҳ�ţ����ĸ�λ�ã���ʼĬ��0��1��2��3ҳ��װ�룬��δװ�룬���� -1ռλ
int Memory_list[4] = { 0, 1, 2, 3 };

// �������ܣ���ӡ��ǰҳ�����ϸ��Ϣ
// ����ҳ�š���š���־λ������λ���Լ��޸ı�־������
void show_page_table()
{
    printf("��ҳ��:\n");
    int i = 0;
    // ����ҳ�����飬�����ӡҳ�������Ϣ
    for (i; i < Pnum; i++)
    {
        printf("ҳ��:%d", page_table[i].pageNumber);
        printf("  ���:%2d", page_table[i].memoryBlock);
        printf("  ��־λ:%d", page_table[i].flag);
        printf("  ����λ��:%.3d", page_table[i].diskLocation);
        printf("  �޸ı�־:%d\n", page_table[i].modifyFlag);
    }
    printf("\n");
}

// �������ܣ���ӡ��װ���ڴ��ҳ�����Ӧ���ڴ��еĿ��
// ֻ�е�Memory_list�е�ҳ�Ų�Ϊ -1ʱ���Ŵ�ӡ�����Ϣ
void show_Memory_list()
{
    int i = 0;
    for (i; i < 4; i++)
    {
        if (Memory_list[i] != -1)
        {
            // ��ӡ��ʽ������Memory_list�е��±꡿:�ڡ�ҳ�š�ҳ-->�ڡ���š���
            printf("��%d��:��%dҳ-->�ڡ�%d����\n", i, Memory_list[i], page_table[Memory_list[i]].memoryBlock);
        }
    }
}

// �������ܣ���ָ����г�ʼ������
// ����ָ���ÿ��ָ��Ĳ������͡�ҳ�ź�ƫ��������Ϣ
void Order_init()
{
    // �߼���ַ��ҳ�ź�ƫ�������
    // ����ָ������·ֱ����ø���ָ����������
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

// �������ܣ�����ϵͳ��ʼ������
// ����ҳ���ҳ�ų�ʼ�����Լ�����0 - 3��ҳ��װ�������������ã�ͬʱ��������ʹ���������
void initial()
{
    // pageNumber��ʼ������ҳ����ÿ��ҳ�����ҳ������Ϊ���������е��±�ֵ
    int i = 0;
    for (i = 0; i < Pnum; i++)
    {
        page_table[i].pageNumber = i;
    }

    // ��ʼ������0 - 3��ҳ��װ�����棬������ر�־λ��������Ϣ��������Memory_used[]����
    // ��0ҳ�ĳ�ʼ������
    page_table[0].flag = 1;
    page_table[0].memoryBlock = 5;
    page_table[0].diskLocation = 11;
    page_table[0].modifyFlag = 0;
    // ��1ҳ�ĳ�ʼ������
    page_table[1].flag = 1;
    page_table[1].memoryBlock = 8;
    page_table[1].diskLocation = 12;
    page_table[1].modifyFlag = 0;
    // ��2ҳ�ĳ�ʼ������
    page_table[2].flag = 1;
    page_table[2].memoryBlock = 9;
    page_table[2].diskLocation = 13;
    page_table[2].modifyFlag = 0;
    // ��3ҳ�ĳ�ʼ������
    page_table[3].flag = 1;
    page_table[3].memoryBlock = 1;
    page_table[3].diskLocation = 21;
    page_table[3].modifyFlag = 0;
    // ��4ҳ�ĳ�ʼ������
    page_table[4].flag = 0;
    page_table[4].memoryBlock = -1;
    page_table[4].diskLocation = 22;
    page_table[4].modifyFlag = 0;
    // ��5ҳ�ĳ�ʼ������
    page_table[5].flag = 0;
    page_table[5].memoryBlock = -1;
    page_table[5].diskLocation = 23;
    page_table[5].modifyFlag = 0;
    // ��6ҳ�ĳ�ʼ������
    page_table[6].flag = 0;
    page_table[6].memoryBlock = -1;
    page_table[6].diskLocation = 121;
    page_table[6].modifyFlag = 0;

    // ģ��Ԥװ����̣�����Memory_used�����ж�Ӧ��ŵ�ʹ�����Ϊ�ѱ���ҵʹ�ã�ֵ��Ϊ2��
    Memory_uesd[1] = 2;
    Memory_uesd[5] = 2;
    Memory_uesd[8] = 2;
    Memory_uesd[9] = 2;
}

// �������ܣ��ж�ָ����ҳ���Ƿ���װ���ڴ�
// ����ֵ�����ҳ��װ���ڴ淵��1�����򷵻� -1
int check_inMemory(int page)
{
    int flag = -1;
    if (page_table[page].flag == 1)
    {
        flag = 1;
    }
    return flag;
}

// �������ܣ��ҵ�Ϊ����ҵ�����ģ�������е�һ�����и���±겢����
// ���δ�ҵ����и񣨼������������򷵻� -1
int check_fullList()
{
    int flag = -1;
    int i = 0;
    // ����memory_list���飬����ֵΪ -1��Ԫ�أ��ҵ��򷵻����±�
    for (i; i < 4; i++)
    {
        if (Memory_list[i] == -1) //�ҵ���һ���տ飬���������±�
        {
            flag = i;
            break;
        }
    }
    return flag;
}

// �������ܣ��ҵ�ȫ��ģ���ڴ��е�һ�����п���±겢����
// ���δ�ҵ����п飨���ڴ���ȫ��ʹ�ã����򷵻� -1
int check_fullBlock()
{
    int flag = -1;
    int i = 0;
    // ����Memory_uesd���飬����ֵΪ0��Ԫ�أ��ҵ��򷵻����±�
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

// �������ܣ�ʵ���Ƚ��ȳ�ҳ���û��㷨
// �������Ϊ����Ҫ�û���ҳ���
// �㷨���̣�����������ڴ��ҳ���û���ȥ������ҳ����뵽�ڴ�����Ӧλ�ã�������ҳ�������Ϣ
void FIFO(int page)
{
    int i = 1;
    before_page = Memory_list[0];//���汻�û�ҳ�ţ�����ǰ�ڴ�����������ҳ��
    for (i = 1; i < 4; i++)
    {
        Memory_list[i - 1] = Memory_list[i];  //��ǰλ��һλ�����ڴ��е�ҳ��˳����ǰ�ƶ�һλ
    }
    Memory_list[3] = page; //������ҳ������ҳ����뵽�ڴ��б�����һ��λ��
    //����ҳ�������Ϣ
    page_table[page].memoryBlock = page_table[before_page].memoryBlock;//����ҳ�Ŀ������Ϊ���û�ҳ�Ŀ��
    page_table[page].flag = 1;//��ʾ��ҳ��װ���ڴ�
    page_table[before_page].memoryBlock = -1;//��Ϊ -1��ʾ��ҳ�����ڶ�Ӧ�����ţ����ѱ��û����ڴ�
    page_table[before_page].flag = 0;//��ʾδװ���ڴ�
    page_table[page].modifyFlag = 0; // ���������̵����ڴ�ʱ������װ��ҳ���޸ı�־��ʼ��Ϊ0����ʾ��װ��δ�޸�
    page_table[before_page].modifyFlag = 0; // ���������̵����ڴ�ʱ�������û���ҳ���޸ı�־��ʼ��Ϊ0����ʾ���û���δ�޸�
}

// �������ܣ���ָ���ĳЩ�����ַ�ת�������Ĳ���ӡ��ʾ��Ϣ
// �������iΪָ���ָ�����
void operation_change(int i)
{
    if (Order_table[i].operation == 'C')
    {
        printf("����ʾ������Ϊ:��\n"); //ģ���������'C'����ת��Ϊ���ġ��桱����ӡ��ʾ
    }
    else if (Order_table[i].operation == 'Q')
    {
        printf("����ʾ������Ϊ:ȡ\n"); //ģ���������'Q'����ת��Ϊ���ġ�ȡ������ӡ��ʾ
    }
    else if (Order_table[i].operation == 'Y')
    {
        printf("����ʾ������Ϊ:��λ\n"); //ģ���������'Y'����ת��Ϊ���ġ���λ������ӡ��ʾ
    }
    else
    {
        printf("����ʾ������Ϊ:%c\n", Order_table[i].operation); //ģ��������������������ַ���ֱ�Ӵ�ӡ���ַ���ʾ����
    }
}

// �������ܣ����к�����ģ��ָ���ִ�й��̣�����ҳ�����С�ȱҳ�жϵ��������������Ҫ����ҳ���û��㷨
void Running()
{
    //��ȡҳ���������У�����Ĭ�ϲ���Order��˳��
    int i = 0;
    int flag = 0; //��ʾ��i��ָ���Ӧ��ҳ���Ƿ�װ���ڴ棬0��ʾδװ�룬1��ʾ��װ��
    int page_in = 0; //��ʾ����Memory_list���±꣨��ţ����������ڴ��б��в�����ҳ
    int block_in = 0; //��ʾ����Memory_used���±꣨��ţ�������������ʹ����������б����ʹ�õĿ�
    for (i; i < Onum; i++)
    {
        if (check_inMemory(Order_table[i].pageNumber) == 1)
        {
            // ���ָ���Ӧ��ҳ�������ڴ��У��γ������ַ����ӡ�����Ϣ
            printf("��ָ���%d��ָ���Ӧҳ�����У��γ������ַ:%4d", i + 1, page_table[Order_table[i].pageNumber].memoryBlock * 1024 + Order_table[i].offset);
            operation_change(i);
        }
        if (check_inMemory(Order_table[i].pageNumber) == -1)
        {
            printf("\n[-----------------��ҳ���жϳ���---------------]\n");
            printf("��ָ���%d��ָ��ִ�в���ȱҳ�жϣ��ж�ҳ��Ϊ��%d\n", i + 1, Order_table[i].pageNumber);
            // �ж��ڴ��Ƿ�����
            if (check_fullBlock() == -1) //�ڴ�ȫʹ�ã�û�п��п飬����FIFO�㷨����ҳ���û�
            {
                printf("����ʾ��");
                if (page_table[Memory_list[0]].modifyFlag == 1) {
                    printf("�ѽ���ҳ���û�,�û�����ҳ��Ϊ��%d,", Memory_list[0]);
                }
                FIFO(Order_table[i].pageNumber);
                printf("װ���ҳ��Ϊ��%d\n", Order_table[i].pageNumber);
                printf("����ʾ����ʱװ���ڴ��е�ҳΪ:\n");
                show_Memory_list();
            }
            else //�ڴ�δ��ȫʹ�ã�ѡ����п齫ҳװ���ڴ�
            {
                page_in = check_fullList();
                Memory_list[page_in] = Order_table[i].pageNumber;
                block_in = check_fullBlock();
                page_table[Order_table[i].pageNumber].flag = 1;
                page_table[Order_table[i].pageNumber].memoryBlock = block_in;
                printf("����ʾ���ѽ��ж�ҳװ���ڴ�,װ���ҳ��Ϊ��%d\n", Order_table[i].pageNumber);
                printf("��ʱװ���ڴ��е�ҳΪ:\n");
                show_Memory_list();
            }
            printf("����ʾ���ж�ִ�к��Ӧ�������ַΪ:%d", page_table[Order_table[i].pageNumber].memoryBlock * 1024 + Order_table[i].offset);
            operation_change(i);
            printf("[-----------------��ҳ���жϳ���---------------]\n");
        }

        // ������ִ�д����ʱ���޸Ķ�Ӧ���޸ı�־Ϊ1����ʾ��ҳ�ѱ��޸�
        if (Order_table[i].operation == 'C')
        {
            page_table[Order_table[i].pageNumber].modifyFlag = 1;
        }

        // ��ÿ�β�������ʾ��ǰҳ��״̬������鿴ҳ���ʵʱ�仯���
        show_page_table();
    }
}

int main()
{
    Order_init(); // ָ���ʼ��������ָ��и���ָ��������Ϣ
    initial(); // ��ҵ��ʼ��������ҳ���ʼ���ͼ��貿��ҳ��װ����������õ�
    show_page_table(); // ��ӡ��ʼҳ��չʾϵͳ��ʼ״̬�µ�ҳ����Ϣ
    Running(); // ���к�����ģ��ָ��ִ�й��̣�����ҳ��������
    system("pause");
    return 0;
}