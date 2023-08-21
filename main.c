#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Global variables
    char newValue[19];
    char cValor[19];
    char *ptr;

    double total;
    double ioldValue;
    double inewValue;

int limpaNewValue(){
    cValor[0] = '\0'; //limpa entrada de dados
    newValue[0] = '\0';
    return 0;
}

int calculate(char lcOperation, char* l_oldValue){
    ioldValue = strtod(l_oldValue, &ptr);
    inewValue = strtod(newValue, &ptr);

    switch (lcOperation)
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
        if (inewValue != 0)
        {
            total = ioldValue / inewValue;
        }
        else{
            printf("erro div by zero");
        }
        
        break;

    default:
        break;
    }
    //Debug
    printf (" valor: %f\n", ioldValue);
    printf (" valor: %f\n", inewValue);
    printf (" valor: %.3f\n", total);


    l_oldValue[0] = '\0';
    sprintf(l_oldValue, "%g", total);

    limpaNewValue();
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
        printf("%s", fraseEcra);
        printf("%c", operation);
    }
    else{
        printf(" ");
        printf("%s", fraseEcra);
    }
    printf("#\n");
    return 0;
}

int iUpdateStr(char *fraseEcra, char *valor)
{
    if (valor[0] < '*' || valor[0] > '9' ) // update if value is number
    {
        return 0;
    }
    char point[] = ".";
    if (strstr(fraseEcra, point) != 0 && valor[0] == '.') //already have a point
    {
        return 0;
    }
    
    strcat(fraseEcra, valor);
    fraseEcra[strlen(fraseEcra)-1]='\0';
    return 0;
}

int main()
{
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
            if (oldValue[0] != '\0')
            {
                calculate(operation, oldValue);
            }
            else{
                strcpy(oldValue, newValue);
                limpaNewValue();
            }
            operation = '+';
            break;
        case '-':
            if (oldValue[0] != '\0')
            {
                calculate(operation, oldValue);
            }
            else{
                strcpy(oldValue, newValue);
                limpaNewValue();
            }
            operation = '-';
            break;
        case '*':
            if (oldValue[0] != '\0')
            {
                calculate(operation, oldValue);
            }
            else{
                strcpy(oldValue, newValue);
                limpaNewValue();
            }
            operation = '*';
            break;
        case '/':
            if (oldValue[0] != '\0')
            {
                calculate(operation, oldValue);
            }
            else{
                strcpy(oldValue, newValue);
                limpaNewValue();
            }
            operation = '/';
            break;
        case 'z': //change signal
            inewValue = atol(newValue);
            inewValue = inewValue * -1;
            newValue[0] = '\0';
            sprintf(newValue, "%g", inewValue);
        break;
        case '=':
            calculate(operation, oldValue);
            break;
        
        default:
            break;
        }
    } 
}