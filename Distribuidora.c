#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAMA 100

typedef struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos          // El tamaño de este arreglo depende de la variable
                                 // “CantidadProductosAPedir”
} Cliente;

// DECLARACION DE FUNCIONES:
float costoTotalXProducto(Producto P);
void mostrarInfoXcliente(Cliente cliente[], int cantidadClientes);

int main()
{
    srand(time(NULL)); // inicio + rand() % (fin - inicio + 1))

    char *TipoProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    int cantClientes;

    do
    {
        printf("Ingrese la cantidad de clientes que desea cargar (hasta 5 clientes): ");
        scanf("%d", &cantClientes);
    } while (cantClientes < 0 || cantClientes > 5);

    Cliente *v_Clientes = (Cliente *)malloc(cantClientes * sizeof(Cliente)); // Reserva de memoria para arreglo Clientes

    printf("    CARGA DE CLIENTES\n"); // ------------------------------------------------------------------------------------------------------------------------
    for (int i = 0; i < cantClientes; i++)
    { // ID de Cliente
        v_Clientes[i].ClienteID = i + 1;
        // Nombre de Cliente
        printf("Ingrese el nombre del Cliente: ");
        char buff[TAMA];
        fflush(stdin);
        gets(buff);
        v_Clientes[i].NombreCliente = (char *)malloc((strlen(buff) + 1) * sizeof(char)); // Reserva de memoria para el nombre de cada cliente en particular
        strcpy(v_Clientes[i].NombreCliente, buff);
        // Cantidad de Productos ---------------------------------------------------------------------------------------------------------------------------------
        v_Clientes[i].CantidadProductosAPedir = 1 + rand() % 5;
        v_Clientes[i].Productos = (Producto *)malloc(v_Clientes[i].CantidadProductosAPedir * sizeof(Producto)); // Reserva de memoria para *Productos
        int numP;
        for (int j = 0; j < v_Clientes[i].CantidadProductosAPedir; j++)
        { // ID de Productos
            v_Clientes[i].Productos[j].ProductoID = j + 1;
            // Nombre del Producto
            numP = rand() % 5; // Seleccion aleatoria de un producto del arreglo TipoProductos
            v_Clientes[i].Productos[j].TipoProducto = (char *)malloc((strlen(TipoProductos[numP]) + 1) * sizeof(char));
            strcpy(v_Clientes[i].Productos[j].TipoProducto, TipoProductos[numP]);
            // Cantidad del Producto
            v_Clientes[i].Productos[j].Cantidad = 1 + rand() % 10;
            // Precio unitario del Producto
            v_Clientes[i].Productos[j].PrecioUnitario = 10 + rand() % 91;
        }
    }

    mostrarInfoXcliente(v_Clientes, cantClientes);

    return 0;
}

// IMPLEMENTACION DE FUNCIONES:
float costoTotalXProducto(Producto P) // Funcion para calcular el costo de un producto en particular por cliente
{
    return (P.Cantidad * P.PrecioUnitario);
}

void mostrarInfoXcliente(Cliente cliente[], int cantidadClientes)
{
    for (int i = 0; i < cantidadClientes; i++)
    {
        float costoTotalXCliente = 0;

        puts("-------------------------------------------------------------------------------------------------------------------------");
        printf("CLIENTE NUMERO %d\n", cliente[i].ClienteID);
        printf("    Nombre del Cliente: %s\n", cliente[i].NombreCliente);
        printf("    Cantidad de Productos a pedir: %d\n", cliente[i].CantidadProductosAPedir);
        puts("*********************************************************");
        printf("        PRODUCTOS A PEDIR\n");

        for (int j = 0; j < cliente[i].CantidadProductosAPedir; j++)
        {
            printf("            Producto numero %d\n", cliente[i].Productos[j].ProductoID);
            printf("            Tipo de Producto: %s\n", cliente[i].Productos[j].TipoProducto);
            printf("            Cantidad del Producto: %d\n", cliente[i].Productos[j].Cantidad);
            printf("            Precio por Unidad: %.2f\n", cliente[i].Productos[j].PrecioUnitario);
            printf("            Total a pagar por el Producto = $ %.2f\n", costoTotalXProducto(cliente[i].Productos[j]));
            puts("*********************************************************");
            costoTotalXCliente = costoTotalXCliente + costoTotalXProducto(cliente[i].Productos[j]);
        }

        printf("Total a pagar por el Cliente numero %d = $ %.2f\n", cliente[i].ClienteID, costoTotalXCliente);
    }
}