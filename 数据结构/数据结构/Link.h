//
//  Link.h
//  数据结构
//
//  Created by Bruce on 2018/3/21.
//  Copyright © 2018年 Bruce. All rights reserved.
//

#ifndef Link_h
#define Link_h

#include <stdio.h>

//结构体类型
struct  list_node
{
    int data ;
    struct list_node *next ;
};

//定义一个别名
typedef struct list_node list_single ;

//创建一个链表节点
list_single *create_list_node(int data);

//头插法插入链表
void top_insert_list(list_single *list,list_single *node);

//尾插法插入链表
void tail_insert_list(list_single *list,list_single *node);

//打印链表
void print_list(list_single *list);

#endif /* Link_h */
