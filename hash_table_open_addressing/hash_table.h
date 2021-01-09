#ifndef HASH_TABLE_H_INCLUDED
#define HASH_TABLE_H_INCLUDED

typedef struct ItemStruct
{
    int id;
    char name[255];
} Item;

typedef struct HashTableStruct
{
    int dataCount, tableSize;
    Item **items;
} HashTable;

Item* createItem();

HashTable* createHashTable(int tableSize);
void freeHashTable(HashTable* hashTable);

int insertInHashTable(HashTable* hashTable, Item* item);
int searchInHashTable(HashTable* hashTable, int id, Item* item);

#endif
