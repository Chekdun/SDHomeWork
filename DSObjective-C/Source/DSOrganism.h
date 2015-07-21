//
//  DSOrganism.h
//  DSHuman
//
//  Created by Denis Sidorov on 08.07.15.
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

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, DSOrganismGender) {
    kDSOrganismGenderUndefine,
    kDSOrganismGenderMale,
    kDSOrganismGenderFemale
};

@interface DSOrganism : NSObject

@property (nonatomic, copy)             NSString            *name;
@property (nonatomic, readonly)         NSArray             *children;
//@property (nonatomic, assign, readonly) DSOrganismGender    gender;
@property (nonatomic, assign)           uint8_t             age;
@property (nonatomic, assign)           uint8_t             weight;

- (id)initWithGender:(DSOrganismGender)gender;

//- (void)fight;

- (void)sayHello;

//- (DSOrganism *)giveBirth;

- (void)addChild:(DSOrganism *) child;

- (void)removeChild:(DSOrganism *) child;

- (void)performGenderSpecificOperation;

@end
