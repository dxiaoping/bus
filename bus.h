//
// Created by deepin on 17-12-21.
//

#ifndef BUS_BUS_H
#define BUS_BUS_H

#endif //BUS_BUS_H


#define ROOT 1
#define GUEST 2
#define OK 1
#define FALSE 0


//用户信息
typedef struct users{
    int authorty;
    char username[10];
    char password[16];
    char phoneNumber[12];
    struct users *next;
    struct users *pre;
} user;

//线性表保存用户
typedef struct userInfo{
    int number;
    struct users *users;
} usersInfo;

//站点信息
typedef struct bus_station{
    char station_name[10];
    int road[20];
    struct bue_station *next;
} station;
typedef struct bus_stations{
    int number;
    station *station;
} stations;
typedef struct bus_road{
    int road_name[10];
    station *next;
    station *pre;
} road;
typedef struct bus_roads{
    int number;
    road *road;
} roads;
usersInfo* users_init(userInfo *users);

void modify_password(user *loginUser);
void modify_information(user *loginUser);
user *login(usersInfo *users);
void registers(usersInfo*users);
user *login_menu(usersInfo *users); //用户登录，其中包含注册功能；
void user_menu(usersInfo *users,user *loginUser);//用户界面;
usersInfo* user_add(usersInfo *users,user *user1);// 增加用户
void user_delete(usersInfo *users,user *user1);//删除用户
usersInfo* load_user(usersInfo *users);//从文件中读取数据
void save_user(userInfo *users);//保存用户信息
void user_management(user *loginUser);//用户管理


