#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 50 // Longitud maxima del nombre que se va a guardar en buff
#define N 5     // Longitud del vector de punteros, cada puntero apunta a un nombre

// FUNCIONES:
void MostrarPersonas(char *v[], int num)
{
    printf("\n");
    for (int i = 0; i < num; i++)
    {
        puts(v[i]);
    }
}

int main()
{
    char buff[TAMA];
    char *V[N];

    printf("Ingrese %d nombres de personas\n", N);
    // Carga de nombres:
    for (int i = 0; i < N; i++)
    {
        gets(buff);
        int largo = strlen(buff) + 1;
        V[i] = (char *)malloc(largo * sizeof(char));
        strcpy(V[i], buff);
    }

    // USANDO LA FUNCIONES:
    MostrarPersonas(V, N);

    return 0;
}