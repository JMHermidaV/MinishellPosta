#include "minish.h"
void bubblesort(char **arreglo) //Recibe una lista terminada en null
{
    // Útil para hacer intercambio de cadenas
    char *temp;
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

            }
        }
    }
    // No hay necesidad de devolver nada, pues modificamos al arreglo de manera interna
}