#include"Function.c"
#include"Room.c"
#include<stdio.h>
#include<time.h>

//单独写入租客文档（使用端）
void WritePeopleDataUser(struct PeopleNode* head)
{    
    struct PeopleNode* tempNode = head->next;

    FILE* fp = fopen("/Users/macbook/Desktop/RentManagementSystem/data/tenant/Tenant Information.txt", "a+");
    //fprintf(fp, "房间号\t姓名\t性别\t电话\t身份证\n");
    while (tempNode != NULL)
    {
        fprintf(fp, "-------------------------------------------------\n");
        fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", tempNode->people->number, tempNode->people->name, tempNode->people->sex, tempNode->people->phone, tempNode->people->ID);
        tempNode = tempNode->next;
    }
    fclose(fp);
}

//覆盖写入租客文档（使用端）
void UpdatePeopleDataUser(struct PeopleNode* head)
{    
    struct PeopleNode* tempNode = head->next;

    FILE* fp = fopen("/Users/macbook/Desktop/RentManagementSystem/data/tenant/Tenant Information.txt", "w+");
    fprintf(fp, "房间号\t姓名\t性别\t电话\t身份证\n");
    while (tempNode != NULL)
    {
        fprintf(fp, "-------------------------------------------------\n");
        fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", tempNode->people->number, tempNode->people->name, tempNode->people->sex, tempNode->people->phone, tempNode->people->ID);
        tempNode = tempNode->next;
    }
    fclose(fp);
}

//单独写入租客文档（管理端）
void WritePeopleDataManagement(struct PeopleNode* head)
{
    struct PeopleNode* tempNode = head->next;

    FILE* fp = fopen("/Users/macbook/Desktop/RentManagementSystem/data/tenant/test.txt", "a+");
    while (tempNode != NULL)
    {
        fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", tempNode->people->number, tempNode->people->name, tempNode->people->sex, tempNode->people->phone, tempNode->people->ID);
        tempNode = tempNode->next;
    }
    fclose(fp);
}

//覆盖写入租客文档（管理端）
void UpdatePeopleDataManagement(struct PeopleNode* head)
{
    struct PeopleNode* tempNode = head->next;

    FILE* fp = fopen("/Users/macbook/Desktop/RentManagementSystem/data/tenant/test.txt", "w+");
    while (tempNode != NULL)
    {
        fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", tempNode->people->number, tempNode->people->name, tempNode->people->sex, tempNode->people->phone, tempNode->people->ID);
        tempNode = tempNode->next;
    }
    fclose(fp);
}

//读取租客文件中的所有信息
struct PeopleNode* ReadPeopleData(struct PeopleNode* head)
{
    struct PeopleInformation* tempNode = (struct PeopleInformation*)malloc(sizeof(struct PeopleInformation));
    FILE* fp = fopen("/Users/macbook/Desktop/RentManagementSystem/data/tenant/test.txt", "r");
    while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\n", tempNode->number, tempNode->name, tempNode->sex, tempNode->phone, tempNode->ID) != EOF)
    {
        head = InsertNodeEndPeopleList(head, tempNode);
        tempNode = (struct PeopleInformation*)malloc(sizeof(struct PeopleInformation));
    }
    free(tempNode);
    
    
    fclose(fp);
    return head;
}



//单独写入房间文档（使用端）
void WriteRoomDataUser(struct RoomNode* head)
{
    struct RoomNode* tempNode = head->next;

    FILE* fp = fopen("/Users/macbook/Desktop/RentManagementSystem/data/room/Room Infomation.txt", "a+");
    //fprintf(fp, "房间号\t入住日期\t到期日期\t当前电表\t当前水表\t租金(一个月)\t房间状态(1为有人,0为无人)\n");
    while (tempNode != NULL)
    {
        fprintf(fp, "--------------------------------------------------------\n");
        fprintf(fp, "%s\t%s\t%s\t%lf\t%lf\t%lf\t%d\n", tempNode->room->number, tempNode->room->in, tempNode->room->out, tempNode->room->electricity, tempNode->room->water, tempNode->room->price, tempNode->room->state);
        tempNode = tempNode->next;
    }
    fclose(fp);
}

//覆盖写入房间文档（使用端）
void UpdateRoomDataUser(struct RoomNode* head)
{
    struct RoomNode* tempNode = head->next;

    FILE* fp = fopen("/Users/macbook/Desktop/RentManagementSystem/data/room/Room Infomation.txt", "w+");
    fprintf(fp, "房间号\t入住日期\t到期日期\t当前电表\t当前水表\t租金(一个月)\t房间状态(1为有人,0为无人)\n");
    while (tempNode != NULL)
    {
        fprintf(fp, "--------------------------------------------------------\n");
        fprintf(fp, "%s\t%s\t%s\t%lf\t%lf\t%lf\t%d\n", tempNode->room->number, tempNode->room->in, tempNode->room->out, tempNode->room->electricity, tempNode->room->water, tempNode->room->price, tempNode->room->state);
        tempNode = tempNode->next;
    }
    fclose(fp);
}

//单独写入房间文档（管理端）
void WriteRoomDataManagement(struct RoomNode* head)
{
    struct RoomNode* tempNode = head->next;

    FILE* fp = fopen("/Users/macbook/Desktop/RentManagementSystem/data/room/test.txt", "a+");
    while (tempNode != NULL)
    {
        fprintf(fp, "%s\t%s\t%s\t%lf\t%lf\t%lf\t%d\n", tempNode->room->number, tempNode->room->in, tempNode->room->out, tempNode->room->electricity, tempNode->room->water, tempNode->room->price, tempNode->room->state);
        tempNode = tempNode->next;
    }
    fclose(fp);
}

//覆盖写入房间文档（管理端）
void UpdateRoomDataManagement(struct RoomNode* head)
{
    struct RoomNode* tempNode = head->next;

    FILE* fp = fopen("/Users/macbook/Desktop/RentManagementSystem/data/room/test.txt", "w+");
    while (tempNode != NULL)
    {
        fprintf(fp, "%s\t%s\t%s\t%lf\t%lf\t%lf\t%d\n", tempNode->room->number, tempNode->room->in, tempNode->room->out, tempNode->room->electricity, tempNode->room->water, tempNode->room->price, tempNode->room->state);
        tempNode = tempNode->next;
    }
    fclose(fp);
}

//读取房间文件中的所有信息
struct RoomNode* ReadRoomData(struct RoomNode* head)
{
    struct RoomInformation* tempNode = (struct RoomInformation*)malloc(sizeof(struct RoomInformation));
    FILE* fp = fopen("/Users/macbook/Desktop/RentManagementSystem/data/room/test.txt", "r");
    while (fscanf(fp, "%s\t%s\t%s\t%lf\t%lf\t%lf\t%d\n", tempNode->number, tempNode->in, tempNode->out, &tempNode->electricity, &tempNode->water, &tempNode->price, &tempNode->state) != EOF)
    {
        head = InsertNodeEndRoomList(head, tempNode);
        tempNode = (struct RoomInformation*)malloc(sizeof(struct RoomInformation));
    }
    free(tempNode);
    
    fclose(fp);
    return head;
}
