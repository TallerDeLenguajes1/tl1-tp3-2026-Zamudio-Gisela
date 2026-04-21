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
    MostrarPersonas(V, N); // Muestra todos los nombres cargados, solo para control

    printf("----------- Busqueda por ID (posicion) o por Nombre (parcial o completo) -------------\n");
    int eleccion;
    do
    {
        printf("    Para busqueda por ID presione -------->   1\n");
        printf("    Para busqueda por Nombre presione ---->   2\n");
        scanf("%d", &eleccion);

    } while (eleccion != 1 && eleccion != 2);

    if (eleccion == 1)
    {
        int posicion;
        printf("*** Ingrese el numero de la posicion del nombre que quiere ver ***\n");
        scanf("%d", &posicion);
        BuscarNombrePorID(V, N, posicion); // Muestra nombre almacenado en V[posicion], si existe
    }
    else
    {
        char *buscado; // Puntero usado para la funcion "BuscarNombrePorPalabra"
        printf("*** Ingrese el Nombre que desea buscar ***\n");
        fflush(stdin);
        gets(buscado);
        BuscarNombrePorPalabra(V, N, buscado); // Muestra nombre que coincide con "buscado", si hubiera
    }

    return 0;
}