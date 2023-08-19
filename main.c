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
    double total;
    double ioldValue;
    double inewValue;
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
            //printf("o tamanho do newValue é: %d\n", strlen(newValue));
            // if (strlen(newValue) > 0) // assume negative values
            // {
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
        case 'z': //change signal
            inewValue = atol(newValue);
            inewValue = inewValue * -1;
            newValue[0] = '\0';
            sprintf(newValue, "%f", inewValue);
            //cValor[0] = '\0';
        break;
        case '=':
            //ioldValue = atol(oldValue);
            //char str[30] = "20.30300 This is test";
            char *ptr;
            //double ret;

            ioldValue = strtod(oldValue, &ptr);

            //inewValue = atol(newValue);
            inewValue = strtod(newValue, &ptr);

            switch (operation)
            {
            case '+':
                total = ioldValue + inewValue;
                printf (" valor: %f\n", ioldValue);
                printf (" valor: %f\n", inewValue);
                printf (" valor: %f\n", total);
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
            //ltoa(total, oldValue, 10);
            limpaNewValue();

            break;
        
        default:
            break;
        }
    } 
}