#include <stdio.h>
#include <stdlib.h>

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

