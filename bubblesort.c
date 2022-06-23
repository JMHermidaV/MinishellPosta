#include "minish.h"
void bubblesort(char arreglo[MAXLINE][MAXLINE], int length) //Recibe una lista terminada en null
{
    // Útil para hacer intercambio de cadenas
    
    char temp[MAXLINE];
    int x, indiceActual;
    for (x = 0; x < length; x++)
    {
        
        for (indiceActual = 0; indiceActual + 1 < length;
             indiceActual++)
        {
            
            int indiceSiguienteElemento = indiceActual + 1;
            // Si la cadena es mayor que la siguiente (alfabeticamente) entonces intercambiamos
            if (strcmp(arreglo[indiceActual], arreglo[indiceSiguienteElemento]) > 0)
            {
                strcpy(temp, arreglo[indiceActual]);
                strcpy(arreglo[indiceActual], arreglo[indiceSiguienteElemento]);
                strcpy(arreglo[indiceSiguienteElemento], temp);
                /*
                temp = strdup(arreglo[indiceActual]);
                arreglo[indiceActual] = strdup(arreglo[indiceSiguienteElemento]);
                arreglo[indiceSiguienteElemento] = temp;
                */

            }
        }
    }
    // No hay necesidad de devolver nada, pues modificamos al arreglo de manera interna
}