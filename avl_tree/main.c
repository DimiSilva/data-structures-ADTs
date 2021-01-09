#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "avl_tree.h"

AVLTree* AVLTreeRoot;

void renderPresentation(int option);
void renderOptions();
char*  getOptionTitle(int option);
void goToOption(int option);

void interactIsEmptyAVLTree(int option);
void interactGetHeightOfAVLTree(int option);
void interactCountNodesOfAVLTree(int option);
void interactPrintPreOrderAVLTree(int option);
void interactPrintInOrderAVLTree(int option);
void interactPrintPostOrderAVLTree(int option);
void interactInsertInAVLTree(int option);
void interactRemoveFromAVLTree(int option);
void interactIncludesInAVLTree(int option);

int main()
{
    system("chcp 65001  > nul");
    AVLTreeRoot = createAVLTree();

    insertInAVLTree(AVLTreeRoot, 1);
    insertInAVLTree(AVLTreeRoot, 2);
    insertInAVLTree(AVLTreeRoot, 3);
    insertInAVLTree(AVLTreeRoot, 4);
    insertInAVLTree(AVLTreeRoot, 5);
    insertInAVLTree(AVLTreeRoot, 6);

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
    printf("Arvore avl");

    if(option != -1)
        printf("\n\nOpção atual: %s:", getOptionTitle(option));

    printf("\n\n");
}

void renderOptions()
{
    printf("Selecione uma operação: \n");
    printf("1 - Verificar se a arvore está vazia\n");
    printf("2 - Verificar a altura da arvore\n");
    printf("3 - Contar nós da arvore\n");
    printf("4 - Imprimir arvore em pré ordem\n");
    printf("5 - Imprimir arvore em ordem\n");
    printf("6 - Imprimir arvore em pós ordem\n");
    printf("7 - Inserir elemento na arvore\n");
    printf("8 - Remover elemento da arvore\n");
    printf("9 - Verificar se a arvore inclui um valor\n");
    printf("0 - Sair\n");
}

char* getOptionTitle(int option)
{
    switch(option)
    {
    case 1:
        return "Verificar se a arvore está vazia";
    case 2:
        return "Verificar a altura da arvore";
    case 3:
        return "Contar nós da arvore";
    case 4:
        return "Imprimir arvore em pré ordem";
    case 5:
        return "Imprimir arvore em ordem";
    case 6:
        return "Imprimir arvore em pós ordem";
    case 7:
        return "Inserir elemento na arvore";
    case 8:
        return "Remover elemento da arvore";
    case 9:
        return "Verificar se a arvore inclui um valor";
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
        interactIsEmptyAVLTree(option);
        break;
    case 2:
        interactGetHeightOfAVLTree(option);
        break;
    case 3:
        interactCountNodesOfAVLTree(option);
        break;
    case 4:
        interactPrintPreOrderAVLTree(option);
        break;
    case 5:
        interactPrintInOrderAVLTree(option);
        break;
    case 6:
        interactPrintPostOrderAVLTree(option);
        break;
    case 7:
        interactInsertInAVLTree(option);
        break;
    case 8:
        interactRemoveFromAVLTree(option);
        break;
    case 9:
        interactIncludesInAVLTree(option);
        break;
    }
    pressAnyKeyToContinue();
}

void interactIsEmptyAVLTree(int option)
{
    renderPresentation(option);
    int isEmpty = isEmptyAVLTree(AVLTreeRoot);
    printf("A arvore %s vazia", isEmpty ? "está" : "não está");
}

void interactGetHeightOfAVLTree(int option)
{
    renderPresentation(option);
    int height = getHeightOfAVLTree(AVLTreeRoot);
    printf("A altura da arvore é %d", height);
}

void interactCountNodesOfAVLTree(int option)
{
    renderPresentation(option);
    int nodes = countNodesOfAVLTree(AVLTreeRoot);
    printf("A arvore tem %d nós", nodes);
}

void interactPrintPreOrderAVLTree(int option)
{
    renderPresentation(option);
    printPreOrderAVLTree(AVLTreeRoot);
}

void interactPrintInOrderAVLTree(int option)
{
    renderPresentation(option);
    printInOrderAVLTree(AVLTreeRoot);
}

void interactPrintPostOrderAVLTree(int option)
{
    renderPresentation(option);
    printPostOrderAVLTree(AVLTreeRoot);
}

void interactInsertInAVLTree(int option)
{
    int value = getIntUserInput("digite o novo valor da arvore: ");

    renderPresentation(option);
    insertInAVLTree(AVLTreeRoot, value);
    printf("Valor inserido");
}

void interactRemoveFromAVLTree(int option)
{
    int value = getIntUserInput("digite o valor a ser removido: ");

    renderPresentation(option);
    int result = removeFromAVLTree(AVLTreeRoot, value);
    printf("Valor %s", result == 0 ? "não encontrado" : "removido");
}

void interactIncludesInAVLTree(int option)
{
    int value = getIntUserInput("digite o valor a ser encontrado: ");

    renderPresentation(option);
    int result = includesInAVLTree(AVLTreeRoot, value);
    printf("A arvore %s o valor", result == 0 ? "não inclui" : "inclui");
}
