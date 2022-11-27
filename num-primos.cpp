#include <iostream>
#include "mpi.h"
using namespace std;

int main(int argc, char *argv[])
{
    int rank, size;
    int n = atoi(argv[1]);
    int i = 0; 
    int cont = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtenemos el numero de procesos en el comunicador global
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    for (i = 3+rank; i < n; i+= size)

    {
        cout << "Número a evaluar: " << i ;
        
        // hallar si es primo o no
        cont = 0;
        for (int j = 1; j < i; j++)
        {
            if (i%j==0)
            {
                cont++;
            }
        }
        if (cont >= 2)
        {
            cout << " no es primo. RANK -> " << rank << endl;
        }
        else
        {
            cout << " es primo. RANK -> " << rank << endl;
        }
    }
}