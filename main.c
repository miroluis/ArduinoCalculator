#include <stdio.h>
#include <string.h>

int iPrintStr(char *c)
{
    printf(c);
}

int iUpdateStr(char *fraseEcra, char *valor)
{
    printf("#");
    strcat(fraseEcra, valor);
    fraseEcra[strlen(fraseEcra)-1]='\0';
    for (size_t i = 0; i < (16 - strlen(fraseEcra)); i++)
    {
        printf(" ");
    }
    printf(fraseEcra);
    printf("#\n");
}

int main()
{
    char oldValue[19];
    char newValue[19];
    char cValor[19];
    cValor[0] = '\0'; //limpa entrada de dados
    oldValue[0] = '\0';
    newValue[0] = '\0';

    while(cValor[0] != 'q')
    {
        //update screen
        printf("##################\n");
        iUpdateStr(oldValue, "");
        iUpdateStr(newValue, cValor);
        printf("##################\n");


        fgets(cValor, sizeof(cValor), stdin);  // read string
// || cValor == '*'
        if (cValor[0] == '+')
        {
            cValor[0] = '\0';
            strcpy(oldValue, newValue);
            newValue[0] = '\n';
        }
        
        printf(" cValor = %s\n", cValor);
    } 
}