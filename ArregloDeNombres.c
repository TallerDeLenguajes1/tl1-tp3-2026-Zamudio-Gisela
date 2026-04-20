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

void BuscarNombre(char *v[], int num, int i)
{
    printf("\n");
    if ((i - 1) >= 0 && (i - 1) <= num)
    {
        puts(v[i - 1]);
    }
    else
    {
        puts("No se encontro el valor buscado\n");
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
    BuscarNombre(V, N, 3);

    return 0;
}