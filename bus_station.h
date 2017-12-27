//
// Created by deepin on 17-12-27.
//

#ifndef BUS_BUS_STATION_H
#define BUS_BUS_STATION_H

#endif //BUS_BUS_STATION_H


#define MAX 100


//站点信息
typedef struct info{
    char name[10];
    struct info *next;
}stationInfo;


//公交信息
typedef struct bus{
    int bus_name;
    stationInfo *stationInfoName;
} busLine;


//城市图
typedef struct {
    busLine AllBusLine[MAX];
    int station_number;
}bus_management;


void CreateBusGraph(bus_management *bus_management1);
void AddStation(bus_management *bus_management1);
void DeleteStation(bus_management *bus_management1);
void modifyStation(bus_management *bus_management1);




