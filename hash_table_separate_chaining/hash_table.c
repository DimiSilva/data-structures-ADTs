#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_table.h"
#include "item_list.h"
#include "data_structs.h"

int generateHashPositionByDivison(int value, int tableSize);
int generateHashPositionByMultiplication(int value, int tableSize);
int generateHashPositionByFold(int value, int tableSize);
int generateHashPositionForString(char *str);

int solveCollisionWithLinearProbing(int position, int index, int tableSize);
int solveCollisionWithQuadraticProbing(int position, int index, int tableSize);
int solveCollisionWithDoubleHash(int hash1, int key, int index, int tableSize);

int solveCollisionWithLinearProbing(int position, int index, int tableSize)
{
    return ((position + index) & 0x7FFFFFFF) % tableSize;
}

int solveCollisionWithQuadraticProbing(int position, int index, int tableSize)
{
    position = position + 2*index + 5*index*index;
    return (position & 0x7FFFFFFF) % tableSize;
}

int solveCollisionWithDoubleHash(int hash1, int key, int index, int tableSize)
{
    int hash2 = generateHashPositionByDivison(key, tableSize - 1) + 1;
    return ((hash1 + index*hash2) & 0x7FFFFFFF) % tableSize;
}

int generateHashPositionByDivison(int key, int tableSize)
{
    return (key & 0x7FFFFFFF) % tableSize;
}

int generateHashPositionByMultiplication(int key, int tableSize)
{
    float constant =  0.6180339887;
    float position= key * constant;
    position = position- (int) position;
    return (int) (tableSize * position);
}

int generateHashPositionByFold(int key, int tableSize)
{
    int bitsNumber = 10;
    int part1 = key >> bitsNumber;
    int part2 = key & (tableSize - 1);
    return (part1 ^ part2);
}

int generateHashPositionForString(char *str)
{
    int position = 7;
    int size = strlen(str);
    for(int i = 0; i < size; i++) position = 31 * position + (int) str[i];
    return position;
}

HashTable* createHashTable(int tableSize)
{
    HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
    if(hashTable != NULL)
    {
        hashTable->tableSize = tableSize;
        hashTable->items = (ItemList**) malloc(tableSize * sizeof(ItemList*));

        if(hashTable->items == NULL)
        {
            free(hashTable);
            return NULL;
        }
        hashTable->dataCount = 0;
        for(int i=0; i < hashTable->tableSize; i++) hashTable->items[i] = NULL;
    }
    return hashTable;
}

int insertInHashTable(HashTable* hashTable, Item* item)
{
    if(hashTable == NULL || hashTable->dataCount == hashTable->tableSize) return 0;

    int key = item->id;
    int position, newPosition;
    position = generateHashPositionByDivison(key, hashTable->tableSize);

    for (int i = 0; i < hashTable->tableSize; i++)
    {
        newPosition = solveCollisionWithLinearProbing(position, i, hashTable->tableSize);
        if(hashTable->items[newPosition] == NULL) hashTable->items[newPosition] = itemListCreate();

        itemListUnshift(hashTable->items[newPosition], item);
        hashTable->dataCount++;
        return 1;
    }
    return 0;
}

int searchInHashTable(HashTable* hashTable, int id, Item* item)
{
    if(hashTable == NULL) return 0;

    int position, newPosition;
    Item *tempItem;
    position = generateHashPositionByDivison(id, hashTable->tableSize);

    for(int i = 0; i < hashTable->tableSize; i++)
    {
        newPosition = solveCollisionWithLinearProbing(position, i, hashTable->tableSize);
        if(hashTable->items[newPosition] == NULL || hashTable->items[newPosition]->head == NULL) return 0;
        for(int j = 0; j < hashTable->items[newPosition]->length; j++)
        {
            tempItem = (itemListFindByIndex(hashTable->items[newPosition], j));
            if(tempItem->id == id)
            {
                *item = *tempItem;
                return 1;
            }
        }

    }
    return 0;
}
