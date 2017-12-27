//
// Created by deepin on 17-12-23.
//

#include "bus.h"
#include "bus_station.h"
#include <iostream>
#include <string.h>

bus_management* CreateBusGraph(bus_management *bus_management1){
    bus_management1 = (bus_management*)malloc(sizeof(bus_management));
    bus_management1->station_number = 0;
    return bus_management1;
}

void AddLine(bus_management *bus_management1){
    int road;
    for (int i = 0; i <100 ; ++i) {
        if(bus_management1->AllBusLine[i].bus_name == 0)
        std::cout << "请输入路线名称" <<std::endl;
        std::cin >> road;
            bus_management1->AllBusLine[i].bus_name = road;
        break;
    }

}
void AddStation(bus_management *bus_management1){
    int i;
    std::cout << "请输入在哪条路线上添加站点" <<std::endl;
    std::cin >> i;
    for (int j = 0; j < 100; ++j) {
        if (bus_management1->AllBusLine[j] ==i){
            stationInfo *station = (stationInfo*)malloc(sizeof(stationInfo));
            std::cout << "请输入站点名称" <<std::endl;
            std::cin >> station->name;
            std::cout << "请输入站点号码" <<std::endl;
            std::cin >> station->number;
            bus_management1->AllBusLine[0].stationInfoName = station;
        }
        else if(j==99)std::cout<< "该路线不存在" <<std::endl;
    }
}
void DeleteStation(busLine lineName,stationInfo station){

}
void modifyStation(bus_management *bus_management1){

}