#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Global variables
    char newValue[19];
    char cValor[19];

int limpaNewValue(){
    cValor[0] = '\0'; //limpa entrada de dados
    newValue[0] = '\0';
    return 0;
}

int iPrintLinha(char *fraseEcra, char operation){
    printf("#");
    for (size_t i = 0; i < (15 - strlen(fraseEcra)); i++)
    {
        printf(" ");
    }
    if (operation != '\0')
    {
        printf(fraseEcra);
        printf("%c", operation);
    }
    else{
        printf(" ");
        printf(fraseEcra);
    }
    printf("#\n");
    return 0;
}

int iUpdateStr(char *fraseEcra, char *valor)
{
    strcat(fraseEcra, valor);
    fraseEcra[strlen(fraseEcra)-1]='\0';
    return 0;
}

int main()
{
    int total;
    int ioldValue;
    int inewValue;
    char oldValue[19];
    limpaNewValue();
    oldValue[0] = '\0';
    char operation = '\0';

    iUpdateStr(oldValue, "");

    while(cValor[0] != 'q')
    {
        //update screen
        printf("##################\n");
        iPrintLinha(oldValue, operation);
        iUpdateStr(newValue, cValor);
        iPrintLinha(newValue, '\0');
        printf("##################\n");

        fgets(cValor, sizeof(cValor), stdin);  // read string

        switch (cValor[0])
        {
        case '+':
            strcpy(oldValue, newValue);
            limpaNewValue();
            operation = '+';
            break;
        case '-':
            strcpy(oldValue, newValue);
            limpaNewValue();
            operation = '-';
            break;
        case '*':
            strcpy(oldValue, newValue);
            limpaNewValue();
            operation = '*';
            break;
        case '/':
            strcpy(oldValue, newValue);
            limpaNewValue();
            operation = '/';
            break;
        case '=':
            ioldValue = atoi(oldValue);
            inewValue = atoi(newValue);

            switch (operation)
            {
            case '+':
                total = ioldValue + inewValue;
                break;
            case '-':
                total = ioldValue - inewValue;
                break;
            case '*':
                total = ioldValue * inewValue;
                break;
            case '/':
                total = ioldValue / inewValue;
                break;
            
            default:
                break;
            }



            oldValue[0] = '\0';
            sprintf(oldValue, "%d", total);
            limpaNewValue();

            break;
        
        default:
            break;
        }

        if (cValor[0] == '+')
        {


        } else if (cValor[0] == '=')
        {

        }
    } 
}