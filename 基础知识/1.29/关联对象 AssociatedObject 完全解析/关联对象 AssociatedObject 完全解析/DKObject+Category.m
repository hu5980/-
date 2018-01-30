//
//  DKObject+Category.m
//  关联对象 AssociatedObject 完全解析
//
//  Created by 胡光耀 on 2018/1/29.
//  Copyright © 2018年 hu5980. All rights reserved.
//

#import "DKObject+Category.h"

#import <objc/runtime.h>

// MARK:说明 https://www.jianshu.com/p/79479a09a8c0#%E5%85%B3%E8%81%94%E5%AF%B9%E8%B1%A1%E7%9A%84%E5%BA%94%E7%94%A8



//DKObject+Category.m:11:17: Property 'categoryProperty' requires method 'categoryProperty' to be defined - use @dynamic or provide a method implementation in this category
//
//DKObject+Category.m:11:17: Property 'categoryProperty' requires method 'setCategoryProperty:' to be defined - use @dynamic or provide a method implementation in this category
//
//在这里的警告告诉我们 categoryProperty 属性的存取方法需要自己手动去实现，或者使用 @dynamic 在运行时实现这些方法

//Q：我们为什么要使用关联对象？
//
//A：因为在分类中 @property 并不会自动生成实例变量以及存取方法，所以一般使用关联对象为已经存在的类添加『属性』。

@implementation DKObject (Category)


- (NSString *)categoryProperty {
    return objc_getAssociatedObject(self, _cmd);
}

//这里的 _cmd 代指当前方法的选择子，也就是 @selector(categoryProperty)。

- (void)setCategoryProperty:(NSString *)categoryProperty{
    objc_setAssociatedObject(self, @selector(categoryProperty), categoryProperty, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

/*
objc_AssociationPolicy    modifier
OBJC_ASSOCIATION_ASSIGN    assign
OBJC_ASSOCIATION_RETAIN_NONATOMIC    nonatomic, strong
OBJC_ASSOCIATION_COPY_NONATOMIC    nonatomic, copy
OBJC_ASSOCIATION_RETAIN    atomic, strong
OBJC_ASSOCIATION_COPY    atomic, copy


@property` 其实有元编程的思想，它能够为我们自动生成实例变量以及存取方法，而这三者构成了属性这个类似于语法糖的概念，为我们提供了更便利的点语法来访问属性：

self.property <=> [self property]
self.property = value <=> [self setProperty:value]
*/



@end
