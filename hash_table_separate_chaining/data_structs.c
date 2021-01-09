#include <stdlib.h>
#include "data_structs.h"

Item* createItem() {
        Item* item = (Item*) malloc(sizeof(Item));
        item->id = NULL;
        return item;
}
