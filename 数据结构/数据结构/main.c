//
//  main.c
//  数据结构
//
//  Created by Bruce on 2018/3/21.
//  Copyright © 2018年 Bruce. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Link.h"

int main(void)
{
    
    list_single *headNode = create_list_node(100); //创建一个节点
    
    for (int i = 0; i < 10; i++) {
        top_insert_list(headNode, create_list_node(i));
    }

    for (int i = 10; i < 20; i++) {
        tail_insert_list(headNode, create_list_node(i));
    }

    print_list(headNode);
    return 0 ;
}  
