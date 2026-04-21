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

void BuscarNombre(char *v[], int num, char *palabra)
{
    char *encontrado;
    int control = 0;

    for (int i = 0; i < num; i++)
    {
        encontrado = strstr(v[i], palabra);

        if (encontrado)
        {
            puts(v[i]);
            control++;
        }
    }

    if (control == 0)
    {
        puts("-1");
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
    // MostrarPersonas(V, N);

    printf("Ingrese el nombre que desea buscar:\n");
    char *buscado;
    gets(buscado);

    //BuscarNombre(V, N, buscado);

    return 0;
}