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
};

void BuscarNombrePorID(char *v[], int num, int i)
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
};

void BuscarNombrePorPalabra(char *v[], int num, char *palabra)
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
};

int main()
{
    char buff[TAMA];
    char *V[N];
    char *buscado; // Puntero usado para la funcion "BuscarNombrePorPalabra"
    int posicion;

    printf("*** Ingrese %d nombres de personas ***\n", N);
    // Carga de nombres:
    for (int i = 0; i < N; i++)
    {
        fflush(stdin);
        gets(buff);
        int largo = strlen(buff) + 1;
        V[i] = (char *)malloc(largo * sizeof(char));
        strcpy(V[i], buff);
    }

    // USANDO LA FUNCIONES:
    MostrarPersonas(V, N); // Muestra todos los nmbres cargados

    printf("*** Ingrese el numero de la posicion del nombre que quiere ver ***\n");
    scanf("%d", &posicion);
    BuscarNombrePorID(V, N, posicion); // Muestra nombre almacenado en V[posicion], si existe

    printf("*** Ingrese el nombre que desea buscar ***\n");
    fflush(stdin);
    gets(buscado);

    BuscarNombrePorPalabra(V, N, buscado); // Muestra nombre que coincide con "buscado", si hubiera

    return 0;
}