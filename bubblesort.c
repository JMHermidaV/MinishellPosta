#include "minish.h"
int bubblesort(char **arreglo) //Recibe una lista terminada en null
{
    // Útil para hacer intercambio de cadenas
    char *temp;
    char temporal[MAXIMA_LONGITUD_CADENA];
    int x, indiceActual;
    for (x = 0; arreglo[x] != NULL; x++)
    {
        for (indiceActual = 0; arreglo[indiceActual + 1] != NULL;
             indiceActual++)
        {
            int indiceSiguienteElemento = indiceActual + 1;
            // Si la cadena es mayor que la siguiente (alfabeticamente) entonces intercambiamos
            if (strcmp(arreglo[indiceActual], arreglo[indiceSiguienteElemento]) > 0)
            {

                temp = strdup(arreglo[indiceActual]);
                arreglo[indiceActual] = strdup(arreglo[indiceSiguienteElemento]);
                arreglo[indiceSiguienteElemento] = temp;
                // Movemos la cadena actual a la temporal
                /*
                memcpy(temporal, arreglo[indiceActual], MAXIMA_LONGITUD_CADENA);
                // Movemos al actual el siguiente elemento
                memcpy(arreglo[indiceActual], arreglo[indiceSiguienteElemento], MAXIMA_LONGITUD_CADENA);
                // Y en el siguiente elemento, lo que había antes en el actual pero ahora está en temporal
                memcpy(arreglo[indiceSiguienteElemento], temporal, MAXIMA_LONGITUD_CADENA);
                */
            }
        }
    }
    // No hay necesidad de devolver nada, pues modificamos al arreglo de manera interna
}