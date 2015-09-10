//
//  DSOrganismTest.m
//  DSHuman
//
//  Created by Denis Sidorov on 12.07.15.
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

#import "DSOrganismTest.h"
#import "DSOrganism.h"
#import "DSOrganismFemale.h"

@implementation DSOrganismTest
+ (void) organismTest {
    DSOrganism *male = [[DSOrganism alloc] initWithGender:kDSOrganismGenderMale];
    DSOrganism *female = [[DSOrganism alloc] initWithGender:kDSOrganismGenderFemale];
    
    male.name = @"MaleName";
    female.name = @"FemaleName";
    
    
    for (NSUInteger i = 0; i < 10; i++) {
        DSOrganism *child = [female giveBirth];
        child.name = [NSString stringWithFormat:@"child%ld", i];
        
        [male addChild:child];
        [female addChild:child];
    }
    
    NSLog(@"\n%@\n ", male);
    NSLog(@"\n%@ ", female);
    
    [male sayHello];
    [female sayHello];
    
//    for (DSOrganism *organism in male.children) {
//        if (kDSOrganismGenderMale == organism.gender) {
//            [organism fight];
//        }
//        if (kDSOrganismGenderFemale == organism.gender) {
//            [organism giveBirth];
//        }
//    }
    
}

@end
