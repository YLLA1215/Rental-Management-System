#include"File.c"

void Menu()
{ 
    do
    {
        struct PeopleNode* peopleHead =  CreatPeopleList();
        struct PeopleNode* tempPeople;
        struct RoomNode* roomHead = CreatRoomList();
        struct RoomNode* tempRoom;
        int choose = 0;
        printf("===========================================\n");
        printf("|---------------租房管理系统--------------|\n");
        printf("|--------------- 1.租客登记 --------------|\n");
        printf("|--------------- 2.房间信息 --------------|\n");
        printf("|--------------- 3.查看租客 --------------|\n");
        printf("|--------------- 4.房租计算 --------------|\n");
        printf("|--------------- 5.租客退房 --------------|\n");
        printf("|--------------- 6.正在开发 --------------|\n");
        printf("|--------------- 7.正在开发 --------------|\n");
        printf("|--------------- 8.正在开发 --------------|\n");
        printf("|--------------- 9.正在开发 --------------|\n");
        printf("|--------------- 0.退出系统 --------------|\n");
        printf("===========================================\n");

        printf("请选择要进行的操作:");
        scanf("%d", &choose);
        
        switch (choose)
        {
            int choose2 = 0;
            int choose3 = 0;
            char data[100];
            case 1:
                printf("【租客登记】\n");
                do
                {
                    printf("===========================================\n");
                    peopleHead = InsertDataEndPeopleList(peopleHead);
                    printf("登记成功!\n");
                    printf("===========================================\n");
                    printf("是否继续登记(是请输入1，否请输入0):");
                    scanf("%d", &choose2);
                    if (choose2 == 0)
                    {
                        WritePeopleDataUser(peopleHead);
                        WritePeopleDataManagement(peopleHead);
                    }
                } while (choose2);
                break;

            case 2:
                printf("===========================================\n");
                printf("|------------- 1.查看房间信息 ------------|\n");
                printf("|------------- 2.更新房间信息 ------------|\n");
                printf("===========================================\n");
                printf("请选择要进行的操作:");
                scanf("%d", &choose3);

                switch (choose3)
                {
                case 1:    
                    printf("===========================================\n");
                    printf("|------------- 1.显示所有房间 ------------|\n");
                    printf("|------------- 2.查找单独房间 ------------|\n");
                    printf("===========================================\n");
                    printf("请选择要进行的操作:");
                    scanf("%d", &choose3);
                    switch (choose3)
                    {
                    case 1:
                        roomHead = ReadRoomData(roomHead);
                        PrintRoomList(roomHead);
                        break;
                    
                    case 2:
                        printf("【查找单独房间】\n");
                        printf("请输入房间的房间号/入住日期/到期日期/价格进行操作:");
                        scanf("%s", data);
                        roomHead = ReadRoomData(roomHead);
                        tempRoom = SmartSearchRoom(roomHead, data);
                        PrintCurrentRoomNode(tempRoom);
                        break;

                    
                    default:
                        printf("你的输入有误");
                        break;
                    }
                    break;
                
                case 2:
                    printf("【更新房间信息】\n");
                    do
                    {
                        printf("===========================================\n");
                        roomHead = InsertEndRoomList(roomHead);
                        printf("房间信息更新成功!\n");
                        printf("===========================================\n");
                        printf("是否继续更新房间信息(是请输入1，否请输入0):");
                        scanf("%d", &choose2);
                        if (choose2 == 0)
                        {
                            WriteRoomDataUser(roomHead);
                            WriteRoomDataManagement(roomHead);
                        }
                    } while (choose2);
                    break;
                default:
                    printf("你的输入有误");
                    break;
                }
                break;

            case 3:
                printf("===========================================\n");
                printf("|------------- 1.显示所有租客 ------------|\n");
                printf("|------------- 2.查找单独租客 ------------|\n");
                printf("===========================================\n");
                printf("请选择要进行的操作:");
                scanf("%d", &choose3);

                switch (choose3)
                {
                case 1:
                    printf("【显示所有租客】\n");
                    ReadPeopleData(peopleHead);
                    PrintPeopleList(peopleHead);
                    break;
                
                case 2:
                    printf("【查找单独租客】\n");
                    printf("请输入租客的房间号/姓名/电话/身份证进行操作:");
                    scanf("%s", data);
                
                    tempPeople = SmartSearch(peopleHead, data);
                    PrintCurrentPeopleNode(tempPeople);
                    break;

                default:
                    printf("你的输入有误\n");
                    break;
                }
                break; 

            case 4:
                printf("【房租计算】\n");
                printf("请输入房间的房间号/入住日期/到期日期/价格进行操作:");
                scanf("%s", data);
                roomHead = ReadRoomData(roomHead);
                tempRoom = SmartSearchRoom(roomHead, data);
                PrintCurrentRoomNode(tempRoom);
                RentCalculation(tempRoom);
                UpdateRoomDataManagement(roomHead);
                break;
            case 5: 
                printf("【租客退房】\n");
                do
                    {
                        peopleHead =  CreatPeopleList();

                        printf("以下为目前所有租客:\n");
                        ReadPeopleData(peopleHead);
                        PrintPeopleList(peopleHead);

                        printf("请输入租客的房间号/姓名/电话/身份证进行操作:");
                        scanf("%s", data);

                        tempPeople = SmartSearch(peopleHead, data);
                        PrintCurrentPeopleNode(tempPeople);

                        printf("是否确认退房，确认请按1，退出请按0:");
                        scanf("%d", &choose3);

                        if (choose3 == 0)
                        {
                            exit(0);
                        }
                        
                        peopleHead = DeleteNodePeopleList(peopleHead, tempPeople);
                        printf("退房成功\n");
                        printf("是否继续执行租客退房(是请输入1，否请输入0):");
                        scanf("%d", &choose2);

                        UpdatePeopleDataUser(peopleHead);
                        UpdatePeopleDataManagement(peopleHead);
                        
                    } while (choose2);
                break;    

            case 0:
                printf("===========================================\n");
                printf("|-------------- 系统退出成功 -------------|\n");
                printf("===========================================\n");
                exit(0);
                break;

            default:
                printf("你的输入有误，请重新输入:");
                break;
        }
        printf("按任意数字显示主菜单\n");
        scanf("%d", &choose);
    } while (1);
}