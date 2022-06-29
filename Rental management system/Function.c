#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//链表节点
struct PeopleNode
{
    struct PeopleInformation* people;
    struct PeopleNode* next;
};

//租客信息
struct PeopleInformation
{
    char number[10];        //房间号
    char name[20];          //名字 
    char sex[10];           //性别
    char phone[12];         //手机号码
    char ID[20];            //身份证
};

//创建链表
struct PeopleNode* CreatPeopleList()
{
    struct PeopleNode* head = (struct PeopleNode*)malloc(sizeof(struct PeopleNode));
    if (head == NULL)
    {
        printf("内存分配失败(1)\n");
        exit(0);
    }
    return head;
}

//头插法导入数据
struct PeopleNode* InsertDataBeginPeopleList(struct PeopleNode* head)
{
    struct PeopleNode* insertNode = (struct PeopleNode*)malloc(sizeof(struct PeopleNode));
    struct PeopleInformation* tempData = (struct PeopleInformation*)malloc(sizeof(struct PeopleInformation));
    
    if (insertNode == NULL)
    {
        printf("内存分配失败(1)");
        exit(0);
    }
    printf("请依次输入租客的信息:\n");
    printf("房间号：");
    scanf("%s", tempData->number);
    printf("姓名:");
    scanf("%s", tempData->name);
    printf("性别:");
    scanf("%s", tempData->sex);
    printf("手机号码:");
    scanf("%s", tempData->phone);
    printf("身份证:");
    scanf("%s", tempData->ID);
    
    insertNode->people = tempData;
    
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
struct PeopleNode* InsertDataEndPeopleList(struct PeopleNode* head)
{
    struct PeopleNode* tempNode = head;
    struct PeopleNode* insertNode = (struct PeopleNode*)malloc(sizeof(struct PeopleNode));
    struct PeopleInformation* tempData = (struct PeopleInformation*)malloc(sizeof(struct PeopleInformation));
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
    
    printf("请依次输入租客的信息:\n");
    printf("房间号：");
    scanf("%s", tempData->number);
    printf("姓名:");
    scanf("%s", tempData->name);
    printf("性别:");
    scanf("%s", tempData->sex);
    printf("手机号码:");
    scanf("%s", tempData->phone);
    printf("身份证:");
    scanf("%s", tempData->ID);
    
    insertNode->people = tempData;
    insertNode->next = NULL;

    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    tempNode->next = insertNode;

    return head;
}

//尾插法导入节点
struct PeopleNode* InsertNodeEndPeopleList(struct PeopleNode* head, struct PeopleInformation* people)
{
    struct PeopleNode* tempNode = head;
    struct PeopleNode* insertNode = (struct PeopleNode*)malloc(sizeof(struct PeopleNode));
    insertNode->people = people;
    insertNode->next = NULL;

    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    tempNode->next = insertNode;

    return head;
}

//删除第一个节点数据
struct PeopleNode* DeleteBeginPeopleList(struct PeopleNode* head)
{
    struct PeopleNode* tempNode = head->next;
    head->next = tempNode->next;
    free(tempNode);

    return head;
}

//删除最后一个节点数据
struct PeopleNode* DeleteEndPeopleList(struct PeopleNode* head)
{   
    struct PeopleNode* tempNode;
    struct PeopleNode* current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }
    
    tempNode = current->next;
    current->next = NULL;
    free(tempNode);

    return head;
}

//通过节点进行删除
struct PeopleNode* DeleteNodePeopleList(struct PeopleNode* head, struct PeopleNode* deleteNode)
{
    struct PeopleNode* tempNode = head;

    while (tempNode->next != deleteNode)
    {
        tempNode = tempNode->next;
    }
    tempNode->next = deleteNode->next;
    free(deleteNode);

    return head;
}

//打印当前节点数据
void PrintCurrentPeopleNode(struct PeopleNode* tempNode)
{
    printf("----------------------------------------------------------\n");
    printf("房间号\t姓名\t性别\t电话\t身份证\n");
    printf("----------------------------------------------------------\n");
    printf("%s\t%s\t%s\t%s\t%s\n", tempNode->people->number, tempNode->people->name, tempNode->people->sex, tempNode->people->phone, tempNode->people->ID);
    printf("----------------------------------------------------------\n");
}

//打印整个链表数据
void PrintPeopleList(struct PeopleNode* head)
{
    struct PeopleNode* tempNode = head->next;
    //system("pause");
    printf("----------------------------------------------------------\n");
    printf("房间号\t姓名\t性别\t电话\t\t身份证\n");
    printf("----------------------------------------------------------\n");
    
    while (tempNode != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%s\n", tempNode->people->number, tempNode->people->name, tempNode->people->sex, tempNode->people->phone, tempNode->people->ID);
        printf("----------------------------------------------------------\n");
        tempNode = tempNode->next;
    }
}

//通过房间号查询
void SearchByNumber(struct PeopleNode* head)
{
    
}

//智能搜索
struct PeopleNode* SmartSearch(struct PeopleNode* head, char* data)
{
    struct PeopleNode* tempNode = head->next;
    while (tempNode != NULL)
    {
        if (strcmp(tempNode->people->number, data) == 0)
        {
            return tempNode;
        }
        else if (strcmp(tempNode->people->name, data) == 0)
        {
            return tempNode;            
        }
        else if (strcmp(tempNode->people->phone, data) == 0)
        {
            return tempNode;
        }
        else if (strcmp(tempNode->people->ID, data) == 0)
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
