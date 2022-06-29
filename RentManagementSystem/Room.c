#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//链表节点
struct RoomNode
{
    struct RoomInformation* room;
    struct RoomNode* next;
};

//房间信息
struct RoomInformation
{
    char number[10];        //房间号
    int state;             //当前房间状态（是否空余）
    char in[20];            //入住日期
    char out[20];           //到期日期
    double electricity;     //当前电表
    double water;           //当前水表
    double price;           //房租
};

//创建链表
struct RoomNode* CreatRoomList()
{
    struct RoomNode* head = (struct RoomNode*)malloc(sizeof(struct RoomNode));
    if (head == NULL)
    {
        printf("内存分配失败(1)\n");
        exit(0);
    }
    return head;
}

//头插法导入数据
struct RoomNode* InsertBeginRoomList(struct RoomNode* head)
{
    struct RoomNode* insertNode = (struct RoomNode*)malloc(sizeof(struct RoomNode));
    struct RoomInformation* tempData = (struct RoomInformation*)malloc(sizeof(struct RoomInformation));
    
    if (insertNode == NULL)
    {
        printf("内存分配失败(1)");
        exit(0);
    }
    printf("请依次输入房间的信息:\n");
    printf("房间号：");
    scanf("%s", tempData->number);
    printf("房间状态(1为有人,0为无人):");
    scanf("%d", &tempData->state);
    if (tempData->state == 1)
    {
        printf("入住日期:");
        scanf("%s", tempData->in);
        printf("到期日期:");
        scanf("%s", tempData->out);
    }
    else if (tempData->state == 0)
    {
        strcpy(tempData->in, "暂无");
        strcpy(tempData->out, "暂无");
    }
    printf("当前电表:");
    scanf("%lf", &tempData->electricity);
    printf("当前水表:");
    scanf("%lf", &tempData->water);
    printf("房间租金(一个月):");
    scanf("%lf", &tempData->price);
    
    insertNode->room = tempData;
    
    if (head->next == NULL)
    {
        head->next = insertNode;
        insertNode->next = NULL;
    }
    else
    {
        insertNode->next = head->next;
        head->next = insertNode;
    }
    return head;
}

//尾插法导入数据
struct RoomNode* InsertEndRoomList(struct RoomNode* head)
{
    struct RoomNode* tempNode = head;
    struct RoomNode* insertNode = (struct RoomNode*)malloc(sizeof(struct RoomNode));
    struct RoomInformation* tempData = (struct RoomInformation*)malloc(sizeof(struct RoomInformation));
    if (insertNode == NULL)
    {
        printf("内存分配失败(1)");
        exit(0);
    }
    if (tempData == NULL)
    {
        printf("内存分配失败(2)");
        exit(0);
    }
    
    printf("请依次输入房间的信息:\n");
    printf("房间号：");
    scanf("%s", tempData->number);
    printf("房间状态(1为有人,0为无人):");
    scanf("%d", &tempData->state);
    if (tempData->state == 1)
    {
        printf("入住日期:");
        scanf("%s", tempData->in);
        printf("到期日期:");
        scanf("%s", tempData->out);
    }
    else if (tempData->state == 0)
    {
        strcpy(tempData->in, "暂无");
        strcpy(tempData->out, "暂无");
    }
    printf("当前电表:");
    scanf("%lf", &tempData->electricity);
    printf("当前水表:");
    scanf("%lf", &tempData->water);
    printf("房间租金(一个月):");
    scanf("%lf", &tempData->price);
    
    insertNode->room = tempData;
    insertNode->next = NULL;

    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    tempNode->next = insertNode;

    return head;
}

//尾插法导入节点
struct RoomNode* InsertNodeEndRoomList(struct RoomNode* head, struct RoomInformation* room)
{
    struct RoomNode* tempNode = head;
    struct RoomNode* insertNode = (struct RoomNode*)malloc(sizeof(struct RoomNode));
    insertNode->room = room;
    insertNode->next = NULL;

    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    tempNode->next = insertNode;

    return head;
}

//删除第一个节点数据
struct RoomNode* DeleteBeginRoomList(struct RoomNode* head)
{
    struct RoomNode* tempNode = head->next;
    head->next = tempNode->next;
    free(tempNode);

    return head;
}

//删除最后一个节点数据
struct RoomNode* DeleteEndRoomList(struct RoomNode* head)
{   
    struct RoomNode* tempNode;
    struct RoomNode* current = head;

    while (current->next->next != NULL)
    {
        current = current->next;
    }
    
    tempNode = current->next;
    current->next = NULL;
    free(tempNode);

    return head;
}

//打印当前节点数据
void PrintCurrentRoomNode(struct RoomNode* tempNode)
{
    printf("----------------------------------------------------------\n");
    printf("房间号\t入住日期\t到期日期\t当前电表\t当前水表\t租金(一个月)\t房间状态(1为有人,0为无人)\n");
    printf("----------------------------------------------------------\n");
    printf("%s\t%s\t%s\t%lf\t%lf\t%lf\t%d\n", tempNode->room->number, tempNode->room->in, tempNode->room->out, tempNode->room->electricity, tempNode->room->water, tempNode->room->price, tempNode->room->state);
    printf("----------------------------------------------------------\n");
}

//打印整个链表数据
void PrintRoomList(struct RoomNode* head)
{
    struct RoomNode* tempNode = head->next;
    //system("pause");
    printf("----------------------------------------------------------\n");
    printf("房间号\t入住日期\t到期日期\t当前电表\t当前水表\t租金(一个月)\t房间状态(1为有人,0为无人)\n");
    printf("----------------------------------------------------------\n");
    
    while (tempNode != NULL)
    {
        printf("%s\t%s\t%s\t%lf\t%lf\t%lf\t%d\n", tempNode->room->number, tempNode->room->in, tempNode->room->out, tempNode->room->electricity, tempNode->room->water, tempNode->room->price, tempNode->room->state);
        printf("----------------------------------------------------------\n");
        tempNode = tempNode->next;
    }
}

//单月房租计算（使用后会更新电表水表）
void RentCalculation(struct RoomNode* tempNode)
{
    double totalprice = 0;
    double currentElectricity;
    double currentWater;

    double startElectricity = tempNode->room->electricity;
    double startWater = tempNode->room->water;
    
    printf("请输入房间当前电表数值:");
    scanf("%lf", &currentElectricity);
    printf("请输入房间当前水表数值:");
    scanf("%lf", &currentWater);

    tempNode->room->electricity = currentElectricity;
    tempNode->room->water = currentWater;

    //总房租 = 单月房租 + （当前电表-起始电表）* 1.3 + （当前水表-起始水表）* 6 + 网费 
    totalprice = tempNode->room->price + (currentElectricity - startElectricity)*1.3 + (currentWater - startWater)*6 + 30;

    printf("-----------------\n");
    printf("单月房租为:%lf\n", totalprice);
    printf("-----------------\n");
}

//智能搜索
struct RoomNode* SmartSearchRoom(struct RoomNode* head, char* data)
{
    double temp = 0;
    sscanf(data, "%lf", &temp);
    struct RoomNode* tempNode = head->next;
    while (tempNode != NULL)
    {
        if (strcmp(tempNode->room->number, data) == 0)
        {
            return tempNode;
        }
        else if (strcmp(tempNode->room->in, data) == 0)
        {
            return tempNode;            
        }
        else if (strcmp(tempNode->room->out, data) == 0)
        {
            return tempNode;
        }
        else if (tempNode->room->price == temp)
        {
            return tempNode;
        }
        else
        {
            tempNode = tempNode->next;
        } 
    }
    printf("对不起，未能找到目标\n");
    exit(0);
}