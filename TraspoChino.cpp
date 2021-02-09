#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

std::string Modificador (std::string str, int k, int q); //De ser necesario rellena la cadena original para que no queden vacíos en el arreglo

int main (void)
{
  std::ifstream ifs ("Mensaje.txt"); //Mensaje de entrada
  std::string str ((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>())); //Conversión de .txt a string
  std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
  str.erase(end_pos, str.end()); //Elimina los espacios del texto
  std::cout <<"Escoja el número de columnas que desea usar para el cifrado."<<"\n";
  int M = 0;
  std::cin >> M;
  if (M >= 1 && str.length() >= M)
  {
    int d = str.length(); 
    while (d%M != 0)
    {
      d++;
    }
    int N = d/M; //Selecciona el N entero más cercano
    char A[N][M] = {{0}}; //Declara el arreglo 2D
    if (Modificador(str, M, N) == "a")
    {
      std::cout <<"El uso de este número de columnas puede resultar en un cifrado débil, se recomienda cambiar la elección."<<"\n";
    }
    else 
    {
      for(int ii = 0; ii < M; ii++)
      {
        if (ii%2 == 0)
        {
          for(int jj = 0; jj < N; jj++) 
          {
            A[jj][ii] = Modificador(str, M, N)[ii*N+jj]; //Rellena la columna actual desde el subíndice 0 hasta el N-1
          }
        }
        else
        {
          for(int jj = N-1; jj >= 0; jj--) 
          {
            A[jj][ii] = Modificador(str, M, N)[ii*N+N-1-jj]; //Rellena la columna actual desde el subíndice N-1 hasta el 0
          }
        }
      }
      std::ofstream fout; 
      fout.open ("Cifrado.txt"); //Mensaje de salida
      std::string Imp;
      for(int ii = 0; ii < N; ii++)
      {
        for(int jj = M-1; jj >= 0 ; jj--) 
        {
          Imp.push_back(A[ii][jj]); //Rellena la cadena a imprimir variando las filas desde 0 a N y sobre estas las columnas desde M-1 hasta 0
          std::cout << A[ii][jj] << "  "; //Imprime la matriz en la consola, es opcional mantenerlo con el fin de visualizar mejor el proceso
        }
        std::cout << "\n";
        Imp.push_back (' ');
      }
      fout <<Imp<<"\n";
      fout.close(); //Cierre del mensaje de salida
    }
  }
  else 
  {
    std::cout <<"Ingrese un número de columnas válido."<<"\n";
  }
  return 0;
}
