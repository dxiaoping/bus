//
// Created by deepin on 17-12-27.
//

#ifndef BUS_BUS_STATION_H
#define BUS_BUS_STATION_H

#endif //BUS_BUS_STATION_H


#define MAX 100


//站点信息
typedef struct info{
    char name[10]; //站点名称
    int number; //站点号码
    struct info *next;
}stationInfo;


//公交信息
typedef struct bus{
    int bus_name;
    stationInfo *stationInfoName;
}busLine;


//城市图
typedef struct {
    busLine AllBusLine[MAX];
    int station_number;
}bus_management;


void CreateBusGraph(bus_management *bus_management1);
void AddLine(bus_management *bus_management1);
void AddStation(bus_management *bus_management1,busLine lineName);
void DeleteStation(busLine lineName,stationInfo station);
void modifyStation(bus_management *bus_management1);
