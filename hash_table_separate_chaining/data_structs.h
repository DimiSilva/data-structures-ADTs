#ifndef DATA_STRUCTS_H_INCLUDED
#define DATA_STRUCTS_H_INCLUDED

typedef struct ItemStruct
{
    int id;
    char name[255];
} Item;

Item* createItem();

#endif // DATA_STRUCTS_H_INCLUDED
