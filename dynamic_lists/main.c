#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "int_list.h"
#include "int_list_list.h"
#include "utils.h"

IntListList* intListList;

void renderPresentation(int option);
void renderOptions();
char*  getOptionTitle(int option);
void goToOption(int option);
void showIntLists();
void createNewIntList(int option);
void insertInIntListBegin (int option);
void showIntList(int option);
void insertInIntListEnd (int option);
void removeIntListElements(int option);
void countIntListElements(int option);
void checkIfIntListIsEmpty(int option);
void concatIntLists(int option);
void copyIntList(int option);
void orderIntList(int option);
void getIntListElement(int option);
void intListOrderedInsert(int option);

int main() {
    system("chcp 65001  > nul");
    intListList = intListListCreate();
    int option = -1;
    do {
        option = -1;
        renderPresentation(option);
        renderOptions();
        scanf("%d", &option);
        if(option < 0 || option > 13){
            printf("Digite uma opção válida!\n");
            pressAnyKeyToContinue();
            continue;
        }

        if(option != 0)
            goToOption(option);
    } while (option != 0);
    return 0;
}

void renderPresentation(int option) {
    system("cls");
    printf("Lista dinâmica");

    if(option != -1)
        printf("\n\nOpção atual: %s:", getOptionTitle(option));

    printf("\n\n");

}

void renderOptions() {
    printf("Selecione uma operação: \n");
    printf("1 - Ver listas\n");
    printf("2 - Criar nova lista\n");
    printf("3 - Inserção na cabeça (início) da lista\n");
    printf("4 - Impressão dos Elementos da Lista\n");
    printf("5 - Inserção na cauda (fim) da lista\n");
    printf("6 - Remover elementos da lista\n");
    printf("7 -  Contar o número de elementos da Lista\n");
    printf("8 - Verificar se a lista está vazia e retornar verdadeiro/falso\n");
    printf("9 - Concatenar duas listas\n");
    printf("10 - Copiar uma lista\n");
    printf("11 - Ordenação de uma lista\n");
    printf("12 - Buscar um dado elemento na lista e retornar seu ponteiro\n");
    printf("13 - Inserção ordenada\n");
    printf("0 - Sair\n");
}

char*  getOptionTitle(int option) {
    switch(option){
        case 1:
            return "Ver listas";
        case 2:
            return "Criar nova lista";
        case 3:
            return "Inserção na cabeça (início) da lista";
        case 4:
            return "Impressão dos Elementos da Lista";
        case 5:
            return "Inserção na cauda (fim) da lista";
        case 6:
            return "Remover elementos da lista";
        case 7:
            return "Contar o número de elementos da Lista";
        case 8:
            return "Verificar se a lista está vazia e retornar verdadeiro/falso";
        case 9:
            return "Concatenar duas listas";
        case 10:
            return "Copiar uma lista";
        case 11:
            return "Ordenação de uma lista";
        case 12:
            return "Buscar um dado elemento na lista e retornar seu ponteiro";
        case 13:
            return "Inserção ordenada";
        default:
            return "";
    }
}

void goToOption(int option) {
    renderPresentation(option);
    switch(option){
        case 1:
            showIntLists();
            break;
        case 2:
            createNewIntList(option);
            break;
        case 3:
            insertInIntListBegin(option);
            break;
        case 4:
            showIntList(option);
            break;
        case 5:
            insertInIntListEnd(option);
            break;
        case 6:
            removeIntListElements(option);
            break;
        case 7:
            countIntListElements(option);
            break;
        case 8:
            checkIfIntListIsEmpty(option);
            break;
        case 9:
            concatIntLists(option);
            break;
        case 10:
            copyIntList(option);
            break;
        case 11:
            orderIntList(option);
            break;
        case 12:
            getIntListElement(option);
            break;
        case 13:
            intListOrderedInsert(option);
            break;
    }
    pressAnyKeyToContinue();
}

void showIntLists() {
    intListListPrint(intListList);
}

void createNewIntList(int option){
    IntList* newIntList = intListCreate();
    intListListPush(intListList, newIntList);
    renderPresentation(option);
    printf("Nova lista criada");
}

void insertInIntListBegin (int option){
    int index = getIntUserInput("Digite o index da lista da qual deseja inserir um novo valor ou um valor negativo caso queira voltar ao menu: ");
    if(index < 0) return ;
    else if(index + 1 > intListList->length) {
        renderPresentation(option);
        printf("Index inválido.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return insertInIntListBegin(option);
     }
     else {
         renderPresentation(option);
        int value = getIntUserInput("Digite o novo valor da lista: ");
        IntList* intList = intListListFindByIndex(intListList, index);
        intListUnshift(intList, value);
        renderPresentation(option);
        printf("Valor inserido");
     }
}

void showIntList(int option){
    int index = getIntUserInput("Digite o index da lista da qual deseja visualizar ou um valor negativo caso queira voltar ao menu: ");
    if(index < 0) return ;
    else if(index + 1 > intListList->length) {
        renderPresentation(option);
        printf("Index inválido.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return showIntList(option);
     }
     else {
        renderPresentation(option);
        IntList* intList = intListListFindByIndex(intListList, index);
        renderPresentation(option);
        intListPrint(intList);
     }
}

void insertInIntListEnd (int option){
    int index = getIntUserInput("Digite o index da lista da qual deseja inserir um novo valor ou um valor negativo caso queira voltar ao menu: ");
    if(index < 0) return ;
    else if(index + 1 > intListList->length) {
        renderPresentation(option);
        printf("Index inválido.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return insertInIntListEnd(option);
     }
     else {
         renderPresentation(option);
        int value = getIntUserInput("Digite o novo valor da lista: ");
        IntList* intList = intListListFindByIndex(intListList, index);
        intListPush(intList, value);
        renderPresentation(option);
        printf("Valor inserido");
     }
}

void removeIntListElements(int option){
    int index = getIntUserInput("Digite o index da lista da qual deseja remover um valor ou um valor negativo caso queira voltar ao menu: ");
    if(index < 0) return ;
    else if(index + 1 > intListList->length) {
        renderPresentation(option);
        printf("Index inválido.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return removeIntListElements(option);
     }
     else {
         renderPresentation(option);
        int intListIndex = getIntUserInput("DIgite o index do elemento que deseja remover ou um valor negativo caso queira voltar ao menu");
        if(intListIndex < 0) return ;
        else if(intListIndex + 1 > intListList->length) {
            renderPresentation(option);
            printf("Index inválido.\n");
            pressAnyKeyToContinue();
            renderPresentation(option);
            return removeIntListElements(option);
         }
        IntList* intList = intListListFindByIndex(intListList, index);
        intListRemoveElement(intList, intListIndex);
        renderPresentation(option);
        printf("Elemento removido");
     }
}

void countIntListElements(int option){
    int index = getIntUserInput("Digite o index da lista da qual deseja visualizar a quantidade de elementos ou um valor negativo caso queira voltar ao menu: ");
    if(index < 0) return ;
    else if(index + 1 > intListList->length) {
        renderPresentation(option);
        printf("Index inválido.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return countIntListElements(option);
     }
     else {
        renderPresentation(option);
        IntList* intList = intListListFindByIndex(intListList, index);
        renderPresentation(option);
        printf("A lista possui %d elementos", intList->length);
     }
}

void checkIfIntListIsEmpty(int option){
    int index = getIntUserInput("Digite o index da lista da qual deseja verificar se está vazia ou um valor negativo caso queira voltar ao menu: ");
    if(index < 0) return ;
    else if(index + 1 > intListList->length) {
        renderPresentation(option);
        printf("Index inválido.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return checkIfIntListIsEmpty(option);
     }
     else {
        renderPresentation(option);
        IntList* intList = intListListFindByIndex(intListList, index);
        renderPresentation(option);
        bool isEmpty = intList->length == 0;
        printf("A lista %s vazia", isEmpty  ? "está": "não está");
     }
}

void concatIntLists(int option){
    int index1 = getIntUserInput("Digite o index da primeira lista a ser concatenada ou um valor negativo caso queira voltar ao menu: ");
    if(index1 < 0) return ;
    else if(index1 + 1 > intListList->length) {
        renderPresentation(option);
        printf("Index inválido.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return concatIntLists(option);
     }
     else {
        renderPresentation(option);
        int index2 = getIntUserInput("Digite o index da segunda lista a ser concatenada ou um valor negativo caso queira voltar ao menu: ");
        if(index2 < 0) return ;
        else if(index2 + 1 > intListList->length) {
            renderPresentation(option);
            printf("Index inválido.\n");
            pressAnyKeyToContinue();
            renderPresentation(option);
            return concatIntLists(option);
         }
        intListListConcatIntLists(intListList, index1, index2);
        renderPresentation(option);
        printf("Listas concatenadas");
     }
}

void copyIntList(int option){
    int index1 = getIntUserInput("Digite o index da lista receptora ou um valor negativo caso queira voltar ao menu: ");
    if(index1 < 0) return ;
    else if(index1 + 1 > intListList->length) {
        renderPresentation(option);
        printf("Index inválido.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return copyIntList(option);
     }
     else {
        renderPresentation(option);
        int index2 = getIntUserInput("Digite o index da lista a ser copiada ou um valor negativo caso queira voltar ao menu: ");
        if(index2 < 0) return ;
        else if(index2 + 1 > intListList->length) {
            renderPresentation(option);
            printf("Index inválido.\n");
            pressAnyKeyToContinue();
            renderPresentation(option);
            return copyIntList(option);
         }
        intListListCopyLists(intListList, index1, index2);
        renderPresentation(option);
        printf("Lista copiada");
     }
}

void orderIntList(int option){
    int index = getIntUserInput("Digite o index da lista que será ordenada ou um valor negativo caso queira voltar ao menu: ");
    if(index < 0) return ;
    else if(index + 1 > intListList->length) {
        renderPresentation(option);
        printf("Index inválido.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return orderIntList(option);
     }
    else {
        IntList* intList = intListListFindByIndex(intListList, index);
        intListSort(intList);
        renderPresentation(option);
        printf("Lista ordenada");
     }
}

void getIntListElement(int option){
    int index1 = getIntUserInput("Digite o index da lista da qual deseja recuperar o laço ou um valor negativo caso queira voltar ao menu: ");
    if(index1 < 0) return ;
    else if(index1 + 1 > intListList->length) {
        renderPresentation(option);
        printf("Index inválido.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return getIntListElement(option);
     }
     else {
        renderPresentation(option);
        int index2 = getIntUserInput("Digite o index do elemento da qual deseja recuperar ou um valor negativo caso queira voltar ao menu: ");
        if(index2 < 0) return ;
        else if(index2 + 1 > intListList->length) {
            renderPresentation(option);
            printf("Index inválido.\n");
            pressAnyKeyToContinue();
            renderPresentation(option);
            return getIntListElement(option);
         }
        IntList* intList = intListListFindByIndex(intListList, index1);
        IntListNode* intListNode = intListFindNodeByIndex (intList, index2);
        renderPresentation(option);
        printf("Posição de memória do laço: %p", &intListNode);
     }
}

void intListOrderedInsert(int option){
    int index = getIntUserInput("Digite o index da lista da qual deseja inserir um novo valor ou um valor negativo caso queira voltar ao menu: ");
    if(index < 0) return ;
    else if(index + 1 > intListList->length) {
        renderPresentation(option);
        printf("Index inválido.\n");
        pressAnyKeyToContinue();
        renderPresentation(option);
        return intListOrderedInsert(option);
     }
     else {
         renderPresentation(option);
        int value = getIntUserInput("Digite o novo valor da lista: ");
        IntList* intList = intListListFindByIndex(intListList, index);
        intListInsertOrdered(intList, value);
        renderPresentation(option);
        printf("Valor inserido");
     }
}
