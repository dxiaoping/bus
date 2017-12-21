//
// Created by deepin on 17-12-21.
//

#include "bus.h"
#include <iostream>
#include <string.h>


void users_init(userInfo *users){
    users=(userInfo*)malloc(sizeof(userInfo));
    users->number=0;
    users->users=NULL;
}

void registers(usersInfo*users){
    user *user1;
    user1=(user*)malloc(sizeof(user));
    std::cout << "请输入您的账号" << std::endl;
    std::cin >> user1->username;
    std::cout << "请输入您的密码" << std::endl;
    std::cin >> user1->password;
    std::cout << "请输入您的手机号" << std::endl;
    std::cin >> user1->phoneNumber;
    user1->authorty=GUEST;
    user_add(users,user1);
}

user *login(usersInfo *users){
    char username[10];
    char password[16];
    user *top;
    top=users->users;
    while(1){
        std::cout << "请输入您的账号" << std::endl;
        std::cin >> username;
        while(1){
            if(strcmp(top->username,username)==0){
                int input_count=0;
                while(input_count<3){
                    std::cout << "请输入您的密码" << std::endl;
                    std::cin >> password;
                    if(strcmp(top->password,password)==0)return users->users;
                    else std::cout << "密码错误" << std::endl;
                    input_count++;

                }
                std::cout << "您已经输错三次密码，请于三小时后重新尝试" << std::endl;
                break;
            }
            else top=top->next;
            if(top==NULL){
                std::cout << "您输入的账号不存在，请重新输入" << std::endl;
                break;
            }
        }
    }

}

user *login_menu(usersInfo *users){
    //load_user(users);
    int choice;
    user *login_user;
    while(1){
        std::cout << "1：登录-----------2：注册" << std::endl;
        if(std::cin >> choice){
            switch(choice){
                case 1:login_user=login(users);
                    break;
                case 2:registers(users);
                    break;
            }
        }
    }




} //用户登录，其中包含注册功能；
void user_add(usersInfo *users,user *user1){
    user1->next=users->users;
    users->users=user1;
    users->number++;
}// 增加用户


void user_delete(usersInfo *users,user *user1){

    users->number--;
}//删除用户
