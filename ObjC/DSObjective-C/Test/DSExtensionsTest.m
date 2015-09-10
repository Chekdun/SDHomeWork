//
//  DSExtensionsTest.m
//  DSHuman
//
//  Created by Denis Sidorov on 15.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//
//Задание 2.
//Условие:
//Дано существо из задания 1.
//Задание:
//1. Убрать переменную пол из существа, а также умение воевать и рожать детей;
//2. Вместо нее создать наследников существа: мужское и женское существо;
//3. Мужское существо умеет воевать, женское - рожать детей;
//4. Создать метод performGenderSpecificOperation у родительского существа, который ничего не делает, мужское существо по вызову этого метода идет воевать, женское рожает детей;
//5. Создать массив существ, в котором бы лежали только мужчины и женщины, пройтись по нему через for (Creature *creature in creatures) и вызвать метод performGenderSpecificOperation, которой, в зависимости от пола существа приведет либо к войне, либо к родам -> Подчеркнуть, что это - полиморфизм, значит, охуенно.
//6. Заменить alloc init autorelease на NSOBject категорию с методом object

#import "DSExtensionsTest.h"

@implementation DSExtensionsTest

+ (void) extensionsTest {

    DSOrganism *maleOrganism = [[[DSOrganism alloc] initWithGender:kDSOrganismGenderMale] autorelease];
    DSOrganism *femaleOrganism = [[[DSOrganism alloc] initWithGender:kDSOrganismGenderFemale] autorelease];
    
    NSLog(@"%@", maleOrganism);
    NSLog(@"%@", femaleOrganism);
    
    NSMutableArray *marray = [[NSMutableArray alloc] init];
    [marray release];
    
    marray = [NSMutableArray array];
        
        for (int i = 0 ; i < 5; i++) {
            [marray addObject:arc4random()];
            [marray addObject:(DSOrganism *)maleOrganism];
            [marray addObject:(DSOrganism *)femaleOrganism];
        }
        NSLog(@"%@", marray);
    }

@end
