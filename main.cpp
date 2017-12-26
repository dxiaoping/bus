#include <iostream>
#include "bus.h"

int main() {
    user *loginUser;
    userInfo *users;
    //初始化线性表
    users=users_init(users);
    //获得登录的用户结构体
    while(1){
        loginUser = login_menu(users);
        user_menu(users,loginUser);
    }


    if (loginUser == NULL) return 0;

}