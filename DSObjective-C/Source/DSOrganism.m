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

@property (nonatomic, retain) NSMutableArray    *mutableChildren;
@property (nonatomic, assign) DSOrganismGender  gender;

@end

@implementation DSOrganism

@dynamic children;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.mutableChildren = nil;
}

- (instancetype)init {
    return [self initWithGender:kDSOrganismGenderUndefine];
}

- (instancetype)initWithGender:(DSOrganismGender)gender {
    self = [super init];
    
    if (self) {
        self.mutableChildren = [[NSMutableArray alloc] init];
        self.gender = gender;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessor

- (NSArray *)children {
    return [self.mutableChildren copy];
 }
            
- (NSString *)description {
        return [NSString stringWithFormat:@"%@, name: %@, gender: %u, age: %hhu; children: %@", [super description],
                self.name, self.gender, self.age, self.children];
    }

#pragma mark -
#pragma mark public

- (void)fight {
    if (kDSOrganismGenderMale == self.gender) {
        NSLog(@"I am %@ going to WAR", self.name);
    } else {
        NSLog(@"I am civilian");
    }
}

- (void)sayHello {
    NSLog(@"Hello, my name is %@ and I am %u", self.name, self.gender);
    NSLog(@"Children say hello:");
    
    for (DSOrganism *organism in self.mutableChildren) {
        [organism sayHello];
    }
}

- (instancetype)giveBirth {
    DSOrganismGender randomGender = (arc4random() % 2) + 1;
    
    return [[[self class] alloc] initWithGender:randomGender];
}

- (void)addChild:(DSOrganism *)child {
    if (child != nil) {
        [self.mutableChildren addObject:child];
    }
}

- (void)removeChild:(DSOrganism *)child {
    [self.mutableChildren removeObject:child];
}

@end

