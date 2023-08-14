#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int iPrintStr(char *c)
{
    printf(c);
}

int iPrintLinha(char *fraseEcra){
    printf("#");
    for (size_t i = 0; i < (16 - strlen(fraseEcra)); i++)
    {
        printf(" ");
    }
    printf(fraseEcra);
    printf("#\n");
}

int iUpdateStr(char *fraseEcra, char *valor)
{
    strcat(fraseEcra, valor);
    fraseEcra[strlen(fraseEcra)-1]='\0';
}

int main()
{
    char oldValue[19];
    char newValue[19];
    char cValor[19];
    cValor[0] = '\0'; //limpa entrada de dados
    oldValue[0] = '\0';
    newValue[0] = '\0';
    char operation = '\0';

    iUpdateStr(oldValue, "");

    while(cValor[0] != 'q')
    {
        //update screen
        printf("##################\n");
        iPrintLinha(oldValue);
        iUpdateStr(newValue, cValor);
        iPrintLinha(newValue);
        printf("##################\n");


        fgets(cValor, sizeof(cValor), stdin);  // read string
// || cValor == '*'
        if (cValor[0] == '+')
        {
            cValor[0] = '\0';
            strcpy(oldValue, newValue);
            newValue[0] = '\0';
            operation = '+';

        } else if (cValor[0] == '=')
        {
            int ioldValue = atoi(oldValue);
            printf("O oldValue %d\n", ioldValue);
            int inewValue = atoi(newValue);
            printf("O newValue %d\n", inewValue);

            int total = ioldValue + inewValue;

            oldValue[0] = '\0';
            sprintf(oldValue, "%d", total);
            
            //iUpdateStr(oldValue, cValor);
        }
        
        
        printf(" cValor = %s\n", cValor);
    } 
}