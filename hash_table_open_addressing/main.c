#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "hash_table.h"

HashTable* hashTable;

void renderPresentation(int option);
void renderOptions();
char*  getOptionTitle(int option);
void goToOption(int option);

void insertItemInHashTable(int option);
void searchItemInHashTable(int option);

int main()
{
    system("chcp 65001  > nul");

    hashTable = createHashTable(1000);



    int option = -1;
    do
    {
        option = -1;
        renderPresentation(option);
        renderOptions();
        scanf("%d", &option);
        if(option < 0 || option > 13)
        {
            printf("Digite uma opção válida!\n");
            pressAnyKeyToContinue();
            continue;
        }

        if(option != 0) goToOption(option);
    }
    while (option != 0);
    return 0;
}

void renderPresentation(int option)
{
    system("cls");
    printf("Tabela hash");

    if(option != -1)
        printf("\n\nOpção atual: %s:", getOptionTitle(option));

    printf("\n\n");
}

void renderOptions()
{
    printf("Selecione uma operação: \n");
    printf("1 - inserir item na tabela\n");
    printf("2 - buscar item na tabela\n");
    printf("0 - Sair\n");
}

char* getOptionTitle(int option)
{
    switch(option)
    {
    case 1:
        return "Inserir item na tabela";
    case 2:
        return "buscar item na tabela";
    default:
        return "";
    }
}

void goToOption(int option)
{
    renderPresentation(option);
    switch(option)
    {
    case 1:
        insertItemInHashTable(option);
        break;
    case 2:
        searchItemInHashTable(option);
        break;
    }
    pressAnyKeyToContinue();
}


void insertItemInHashTable(int option)
{
    Item* item;
    char name[255];
    item = createItem();

    int id = getIntUserInput("Digite o id do novo item ou um valor negativo caso queira voltar ao menu: ");
    if(id < 0) return ;

    searchInHashTable(hashTable, id, item );
    if(item->id != NULL)
    {
        renderPresentation(option);
        printf("id já em uso.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return insertItemInHashTable(option);
    }

    renderPresentation(option);

    getStringUserInput("Digite o nome do item a ser adicionado: ", name);

    item->id = id;
    strcpy(item->name, name);

    insertInHashTable(hashTable, item);

    renderPresentation(option);

    printf("Item inserido");
}

void searchItemInHashTable(int option)
{
    Item* item;
    item = createItem();

    int id = getIntUserInput("Digite o id do item que deseja encontrar ou um valor negativo caso queira voltar ao menu: ");
    if(id < 0) return ;

    searchInHashTable(hashTable, id, item);
    if(item->id == NULL)
    {
        renderPresentation(option);
        printf("Item não encontrado.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return searchItemInHashTable(option);
    }

    renderPresentation(option);
    printf("O nome do item buscado de id %d é %s", item->id, item->name);
}
