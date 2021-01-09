#include "data_structs.h"

#ifndef ITEM_LIST_H_INCLUDED
#define ITEM_LIST_H_INCLUDED

typedef struct ItemListNodeStruct
{
    Item *value;
    struct ItemListNodeStruct* next;
} ItemListNode;

typedef struct ItemListStruct
{
    int length;
    ItemListNode *head;
    ItemListNode *end;
} ItemList;

ItemList* itemListCreate();

void itemListPrint(ItemList* list);

void itemListUnshift(ItemList* list, Item* value);
void itemListPush(ItemList* list, Item* value);

Item* itemListFindByIndex (ItemList* list,  int index);
ItemListNode* itemListFindNodeByIndex (ItemList* list,  int index) ;

void itemListRemoveElement(ItemList* list, int index);

ItemList* itemListConcat(ItemList* list1, ItemList* list2) ;
ItemList* itemListCopy(ItemList* list1, ItemList* list2);

#endif // ITEM_LIST_H_INCLUDED
