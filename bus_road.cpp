//
// Created by deepin on 17-12-23.
//

#include "bus.h"
#include "bus_station.h"
#include <iostream>
#include <string.h>

bus_management* CreateBusGraph(bus_management *bus_management1){
    bus_management1 = (bus_management*)malloc(sizeof(bus_management));
    bus_management1->line_number = 0;
    return bus_management1;
}

void AddLine(bus_management *bus_management1){
    int road;
    std::cout << "请输入线路的名称" << std::endl;
    std::cin >> road;
    bus_management1->AllBusLine[bus_management1->line_number].bus_name = road;
    bus_management1->AllBusLine[bus_management1->line_number].station_number = 0;
    bus_management1->AllBusLine[bus_management1->line_number].stationInfoName = NULL;
    bus_management1->line_number++;
    save_bus_managment(bus_management1);
}

void AddStation(bus_management *bus_management1){
    int i;
    std::cout << "请输入在哪条路线上添加站点" <<std::endl;
    std::cin >> i;
    for (int j = 0; j < bus_management1->line_number; j++) {
        if (bus_management1->AllBusLine[j].bus_name ==i){
            stationInfo *station = (stationInfo*)malloc(sizeof(stationInfo));
            std::cout << "请输入站点名称" <<std::endl;
            std::cin >> station->name;
            station->number = bus_management1->AllBusLine[j].bus_name*10 + j;
            station->next = bus_management1->AllBusLine[j].stationInfoName;
            bus_management1->AllBusLine[j].stationInfoName = station;
            bus_management1->AllBusLine[j].station_number++;
        }
        else if(j==bus_management1->line_number)
            std::cout<< "该路线不存在" <<std::endl;
    }
    save_bus_managment(bus_management1);
}


void DeleteStation(bus_management *bus_management1){
    int line_name;
    stationInfo *stationInfo1,*PreStationInfo;
    int stationNumber;
    std::cout << "请输入线路的名称" << std::endl;
    std::cin >> line_name;
    for(int i=0; i<bus_management1->line_number;i++){
        if (bus_management1->AllBusLine[i].bus_name = line_name){
            std::cout << "请输入站点的序号" << std::endl;
            std::cin >> stationNumber;
            PreStationInfo = stationInfo1 = bus_management1->AllBusLine[i].stationInfoName;
            while (stationInfo1){
                if (bus_management1->AllBusLine[i].stationInfoName->number == stationNumber){
                    bus_management1->AllBusLine[i].stationInfoName = stationInfo1->next;
                    bus_management1->AllBusLine[i].station_number--;
                    return;
                } else if (stationInfo1->number == stationNumber){
                    PreStationInfo->next = stationInfo1->next;
                    bus_management1->AllBusLine[i].station_number--;
                    return;
                }
                PreStationInfo = stationInfo1;
                stationInfo1 = stationInfo1->next;
            }
        }
    }

}

void modifyStation(bus_management *bus_management1){

}

void road_management(bus_management *bus_management1){
    printf("1.增加线路\n");
    printf("2.增加站点\n");
    printf("3.删除站点\n");
    int choice;
    std::cin >> choice;
    bus_management1 = load_bus_File();
    switch (choice){
        case 1:AddLine(bus_management1);
            visit_line(bus_management1);
            break;
        case 2:visit_line(bus_management1);
            AddStation(bus_management1);
            break;
        case 3:visit_line(bus_management1);
            DeleteStation(bus_management1);
            break;
        default:printf("输入有误");
            break;
    }
}

void visit_line(bus_management *bus_management1){
    for (int i = 0; i < bus_management1->line_number ; i++) {
        printf("线路：%d------",bus_management1->AllBusLine[i].bus_name);
        stationInfo *stationInfo1 = bus_management1->AllBusLine[i].stationInfoName;
        while (stationInfo1){
            printf("%d:%s-",stationInfo1->number,stationInfo1->name);
            stationInfo1 = stationInfo1->next;
        }
        printf("\n");
    }
}

void save_bus_managment(bus_management *bus_management1){
    FILE *bus_data=NULL;
    bus_data=fopen("bus_data.txt","wt");
    fwrite(bus_management1, sizeof(bus_management),1,bus_data);
    for (int i = 0; i < bus_management1->line_number; ++i) {
        stationInfo *tempRoad = bus_management1->AllBusLine[i].stationInfoName;
        while (tempRoad){
            fwrite(tempRoad, sizeof(stationInfo),1,bus_data);
            tempRoad = tempRoad->next;
        }
    }
    fclose(bus_data);
}

bus_management* load_bus_File(){
    bus_management *bus_management1 = CreateBusGraph(bus_management1);
    FILE *bus_data;
    if(fopen("bus_data.txt","r")!=NULL)
    {
        bus_data=fopen("bus_data.txt","r");
        fread(bus_management1, sizeof(bus_management),1,bus_data);
        for (int i = 0; i <bus_management1->line_number; ++i) {
            for (int j = 0; j <bus_management1->AllBusLine[i].station_number; ++j) {
                stationInfo *tempRoad = (stationInfo *)malloc(sizeof(stationInfo));
                fread(tempRoad, sizeof(stationInfo),1,bus_data);
                tempRoad->next = bus_management1->AllBusLine[i].stationInfoName;
                bus_management1->AllBusLine[i].stationInfoName= tempRoad;
            }
        }
        fclose(bus_data);
    }
    return bus_management1;
}