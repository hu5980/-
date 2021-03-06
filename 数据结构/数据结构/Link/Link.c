//
//  Link.c
//  数据结构
//
//  Created by Bruce on 2018/3/21.
//  Copyright © 2018年 Bruce. All rights reserved.
//

#include "Link.h"
#include <string.h>
#include <stdlib.h>


list_single *create_list_node(int data)
{
    list_single *node = NULL ;
    node = (list_single *)malloc(sizeof(list_single));
    if(node == NULL){
        printf("malloc fair!\n");
    }
    memset(node,0,sizeof(list_single));
    node->data = data ;
    node->next = NULL ;
    return node ;
}


void top_insert_list(list_single *list,list_single *node) {
    if (node != NULL && list!= NULL) {
        list_single *p = list;
        node->next = p->next;
        p->next = node;
    }
}


void tail_insert_list(list_single *list,list_single *node){
     if (node != NULL && list!= NULL) {
         list_single *p = list;
         while (NULL != p->next) {
             p= p->next;
         }
         p->next = node;
     }
}

void print_list(list_single *list) {
    if (list != NULL) {
        list_single *p = list;
        while (NULL != p->next) {
            printf("数据 = %d\n",p->data);
            p= p->next;
        }
        printf("数据 = %d\n",p->data);
    }
}


bool delete_list_node(list_single *list,int data) {
    if (list != NULL){
        list_single *p = list;
        list_single *pre_node;
        while (NULL != p->next) {
            pre_node = p;
            p = p->next;
            if (p->data == data) {
                if (p->next != NULL){
                    pre_node->next = p->next->next;
                    free(p);
                }else{
                    pre_node->next = NULL;
                    free(p);
                }
            }
        }
        return true;
    }
    printf("没有要删除的节点");
    return false;
}


