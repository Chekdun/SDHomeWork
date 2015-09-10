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
#import "DSOrganismMale.h"
#import "DSOrganismFemale.h"

@interface DSOrganism ()

@property (nonatomic, retain) NSMutableArray    *mutableChildren;
@property (nonatomic, assign) DSOrganismGender  gender;

@end

@implementation DSOrganism

#pragma mark
#pragma mark Class methods

+ (Class)organismClassForGender:(DSOrganismGender)gender {
    return kDSOrganismGenderMale == gender ? [DSOrganismMale class] : [DSOrganismFemale class];
}

@dynamic children;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.mutableChildren = nil;
    
    [super dealloc];
}

//- (instancetype)init {
//    return [self initWithGender:kDSOrganismGenderUndefine];
//}

- (id)initWithGender:(DSOrganismGender)gender {
    self = [super init];
   
    Class organismClass = [[self class] organismClassForGender:gender];
    
    [self release];
    self = [[organismClass alloc] init];
    
        return self;
    }
//    self = [super init];
//    Class organismClass = [[self class] organismClassForGender:gender];
//    
//    [self release];
//    self = [[organismClass alloc] init];
//    return [[organismClass alloc] init];
//}
//    self = [super init];
//    Class organismClass = [[self class] organismClassForGender:gender];
//    //[self release];
//
//    return [[organismClass alloc] init];
//}

#pragma mark -
#pragma mark Accessor

- (NSArray *)children {
    return [[self.mutableChildren copy] autorelease];
 }
            
- (NSString *)description {
        return [NSString stringWithFormat:@"%@, name: %@, gender: %lu, age: %hhu; children: %@",
                [super description],
                self.name,
                (unsigned long)self.gender,
                self.age,
                self.children];
    }

#pragma mark -
#pragma mark public

//- (void)fight {
//    if (kDSOrganismGenderMale == self.gender) {
//        NSLog(@"I am %@ going to WAR", self.name);
//    } else {
//        NSLog(@"I am civilian");
//    }
//}

- (void)sayHello {
    NSLog(@"Hello, my name is %@ and I am %lu", self.name, (unsigned long)self.gender);
    NSArray *children = self.children;

    if ([children count]) {
        NSLog(@"Children say hello:");
    for (DSOrganism *organism in self.mutableChildren) {
        [organism sayHello];
        }
    }
}

//- (instancetype)giveBirth {
//    DSOrganismGender randomGender = arc4random_uniform(2) + 1;
//    if (kDSOrganismGenderFemale) {
//        return [[[[self class] alloc] initWithGender:randomGender] autorelease];
//    }
//}

- (void)addChild:(DSOrganism *)child {
    if (child != nil && NO ==[self.mutableChildren containsObject:child]) {
        [self.mutableChildren addObject:child];
    }
}

- (void)removeChild:(DSOrganism *)child {
    [self.mutableChildren removeObject:child];
}

- (void)performGenderSpecificOperation {
    
}

@end

