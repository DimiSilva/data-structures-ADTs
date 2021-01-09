#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "binary_tree.h"

BinaryTree* binaryTreeRoot;

void renderPresentation(int option);
void renderOptions();
char*  getOptionTitle(int option);
void goToOption(int option);

void interactIsEmptyBinaryTree(int option);
void interactGetHeightOfBinaryTree(int option);
void interactCountNodesOfBinaryTree(int option);
void interactPrintPreOrderBinaryTree(int option);
void interactPrintInOrderBinaryTree(int option);
void interactPrintPostOrderBinaryTree(int option);
void interactInsertInBinaryTree(int option);
void interactRemoveFromBinaryTree(int option);
void interactIncludesInBinaryTree(int option);

int main()
{
    system("chcp 65001  > nul");
    binaryTreeRoot = createBinaryTree();

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
    printf("Arvore binária");

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
        interactIsEmptyBinaryTree(option);
        break;
    case 2:
        interactGetHeightOfBinaryTree(option);
        break;
    case 3:
        interactCountNodesOfBinaryTree(option);
        break;
    case 4:
        interactPrintPreOrderBinaryTree(option);
        break;
    case 5:
        interactPrintInOrderBinaryTree(option);
        break;
    case 6:
        interactPrintPostOrderBinaryTree(option);
        break;
    case 7:
        interactInsertInBinaryTree(option);
        break;
    case 8:
        interactRemoveFromBinaryTree(option);
        break;
    case 9:
        interactIncludesInBinaryTree(option);
        break;
    }
    pressAnyKeyToContinue();
}

void interactIsEmptyBinaryTree(int option)
{
    renderPresentation(option);
    int isEmpty = isEmptyBinaryTree(binaryTreeRoot);
    printf("A arvore %s vazia", isEmpty ? "está" : "não está");
}

void interactGetHeightOfBinaryTree(int option)
{
    renderPresentation(option);
    int height = getHeightOfBinaryTree(binaryTreeRoot);
    printf("A altura da arvore é %d", height);
}

void interactCountNodesOfBinaryTree(int option)
{
    renderPresentation(option);
    int nodes = countNodesOfBinaryTree(binaryTreeRoot);
    printf("A arvore tem %d nós", nodes);
}

void interactPrintPreOrderBinaryTree(int option)
{
    renderPresentation(option);
    printPreOrderBinaryTree(binaryTreeRoot);
}

void interactPrintInOrderBinaryTree(int option)
{
    renderPresentation(option);
    printInOrderBinaryTree(binaryTreeRoot);
}

void interactPrintPostOrderBinaryTree(int option)
{
    renderPresentation(option);
    printPostOrderBinaryTree(binaryTreeRoot);
}

void interactInsertInBinaryTree(int option)
{
    int value = getIntUserInput("digite o novo valor da arvore: ");

    renderPresentation(option);
    insertInBinaryTree(binaryTreeRoot, value);
    printf("Valor inserido");
}

void interactRemoveFromBinaryTree(int option)
{
    int value = getIntUserInput("digite o valor a ser removido: ");

    renderPresentation(option);
    int result = removeFromBinaryTree(binaryTreeRoot, value);
    printf("Valor %s", result == 0 ? "não encontrado" : "removido");
}

void interactIncludesInBinaryTree(int option)
{
    int value = getIntUserInput("digite o valor a ser removido: ");

    renderPresentation(option);
    int result = includesInBinaryTree(binaryTreeRoot, value);
    printf("A arvore %s o valor", result == 0 ? "não inclui" : "inclui");
}
