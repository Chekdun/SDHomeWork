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
    kDSOrganismGenderUndefine,
    kDSOrganismGenderMale,
    kDSOrganismGenderFemale
}DSOrganismGender;


@interface DSOrganism : NSObject

@property (nonatomic, copy)             NSString            *name;
@property (nonatomic, copy, readonly)   NSArray             *children;
@property (nonatomic, assign, readonly) DSOrganismGender    gender;
@property (nonatomic, assign, readonly) uint8_t             age;
@property (nonatomic, assign, readonly) uint8_t             weight;

- (instancetype)initWithGender:(DSOrganismGender)gender;

- (void)fight;

- (void)sayHello;

- (DSOrganism *)giveBirth;

- (void)addChild:(DSOrganism *) child;

- (void)removeChild:(DSOrganism *) child;

@end
