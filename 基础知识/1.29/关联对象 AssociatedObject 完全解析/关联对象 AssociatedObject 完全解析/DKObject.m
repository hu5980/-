//
//  DKObject.m
//  关联对象 AssociatedObject 完全解析
//
//  Created by 胡光耀 on 2018/1/29.
//  Copyright © 2018年 hu5980. All rights reserved.
//

#import "DKObject.h"

@implementation DKObject {
    NSString * _property;
}

- (NSString *)property {
    return  _property;
}

- (void)setProperty:(NSString *)property {
    _property = property;
}


@end
