#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void pressAnyKeyToContinue() {
    printf("\n\n\nPressione enter para continuar...\n");
    fflush(stdin);
    getchar();
}

int getIntUserInput(char* message)  {
    int value = 0;
    printf("%s\n", message);
    scanf("%d", &value);
    return value;
}

float getFloatUserInput(char* message)
{
        float value = 0;
    printf("%s\n", message);
    scanf("%f", &value);
    return value;
}

void getStringUserInput(char* message, char* str)
{
        fflush(stdin);
        printf("%s\n", message);
        scanf("%[^\n]%*c", str);
}
