//
//  linked_list.h
//  Project 3 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef contacts_h
#define contacts_h

#include "types.h" // maybe unnecessary
//#include "token.h"

typedef struct LinkedList {
    //Token * value;
    struct LinkedList * next;
} LinkedList;

LinkedList * append(LinkedList *);
LinkedList * advance_list(LinkedList * , int);
void free_list(LinkedList * list);

#endif /* linked_list_h */
