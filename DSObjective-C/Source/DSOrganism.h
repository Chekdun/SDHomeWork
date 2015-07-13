//
//  DSOrganism.h
//  DSHuman
//
//  Created by Denis Sidorov on 08.07.15.
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

#import <Foundation/Foundation.h>

typedef enum {
    kDSOrganismGenderMale = 1,
    kDSOrganismGenderFemale = 2
} DSOrganismGender;

@interface DSOrganism : NSObject

- (instancetype) initWithName:(NSString *)name
                       gender:(DSOrganismGender)gender
                          age:(uint8_t)age
                       weight:(uint8_t)weight;


@property (nonatomic, copy)     NSString *name;
@property (nonatomic, retain)   NSMutableArray *children;
@property (nonatomic, assign)   DSOrganismGender gender;
@property (nonatomic, assign)   uint8_t age;
@property (nonatomic, assign)   uint8_t weight;

- (void) fight;
- (void) giveBirthChild;
- (void) addChild:(DSOrganism *)child;
- (void) removeChild:(DSOrganism *)child;
- (void) sayHello;

@end
