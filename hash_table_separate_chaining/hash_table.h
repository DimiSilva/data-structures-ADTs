#include "data_structs.h"
#include "item_list.h"

#ifndef HASH_TABLE_H_INCLUDED
#define HASH_TABLE_H_INCLUDED

typedef struct HashTableStruct
{
    int dataCount, tableSize;
    ItemList **items;
} HashTable;

HashTable* createHashTable(int tableSize);

int insertInHashTable(HashTable* hashTable, Item* item);
int searchInHashTable(HashTable* hashTable, int id, Item* item);

#endif
