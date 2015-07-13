//
//  DSOrganism.m
//  DSObjective-C
//
//  Created by Denis Sidorov on 07.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//
//Задание 1.
//Условие:
//Есть существо, у существа есть typedef пола, есть строка имени, есть масса, есть возраст, есть массив детей. Существо умеет воевать и рожать детей. При родах существо не добавляет к себе ребенка автоматом. Существо умеет добавит к себе детей и удалить. Существо умеет говорить "Привет!", причем, когда существо говорит привет, то сначала говорит оно, а потом все его дети (значит и дети детей, и т.д.).
//Задание:
//1. Написать класс существа;
//2. Создать несколько существ и положить их в массив, каждому из существ добавить детей;
//3. В цикле пройти по массиву существ и проверить их пол. Если мужик, то надо отправить существо воевать, если баба, то рожать детей;
//4. У существа наружу должен быть немутабельный массив детей через динамическое проперти с копи+авторелиз, а внутри - еще и мутабельное свойство.

#import "DSOrganism.h"

@interface DSOrganism ()
@property (nonatomic, retain) NSMutableArray *mutableChildren;

@end

@implementation DSOrganism

@dynamic children;

- (void) dialloc {
    self.name = nil;
    self.mutableChildren = nil;
}

- (instancetype) initWithName:(NSString *)name
                       gender:(DSOrganismGender)gender
                          age:(uint8_t)age
                       weight:(uint8_t)weight
{
    self = [super init];
    if (self) {
        self.name = name;
        self.gender = gender;
        self.age = age;
        self.weight = weight;
        self.mutableChildren = [NSMutableArray array];
    }
    return self;
}

- (void)fight {
    NSLog(@" I must FIGHT, I must KILL");
}

- (void)giveBirthChild {
    NSLog(@" Now I will give birth to child");
}

- (void)addChild:(DSOrganism *)child {
    if (nil != child) {
        [self.mutableChildren addObject:child];
    }
}

- (void)removeChild:(DSOrganism *)child {
    if (nil != child) {
        [self.mutableChildren removeObject:child];
    }
}

- (void)sayHello {
    NSLog(@"Hello!");
    
    for (DSOrganism *child in self.mutableChildren) {
        [child sayHello];
    }
}



@end





