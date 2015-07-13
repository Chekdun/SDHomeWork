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

@implementation DSOrganismTest

+ (void) organismTest {
// create  2 organism
    DSOrganism *newOrganism1 = [[DSOrganism alloc] initWithName:@"John"
                                                         gender:kDSOrganismGenderMale
                                                            age:25
                                                         weight:180];
    
    NSLog(@"\n name = %@\n, gender = %u\n, age = %hhu\n, weight = %hhu\n", newOrganism1.name, newOrganism1.gender, newOrganism1.age, newOrganism1.weight);
    assert(nil != newOrganism1);
    
    DSOrganism *newOrganism2 = [[DSOrganism alloc] initWithName:@"July"
                                                         gender:kDSOrganismGenderFemale
                                                            age:24
                                                         weight:170];
    
    NSLog(@"\n name = %@\n, gender = %u\n, age = %hhu\n, weight = %hhu\n", newOrganism2.name, newOrganism2.gender, newOrganism2.age, newOrganism2.weight);
    assert(nil != newOrganism2);

}
@end
