#include <fstream>
#include <iostream>
#include <string>

std::string Cifrador (std::string str1, int k); //Función cifradora

int main (void)
{
  int k = 0; //Número de desplazamientos con respecto al alfabeto base
  std::cin >> k; 
  if (k >= 0)
  {
    std::ifstream M ("Mensaje.txt"); //Mensaje de entrada
    std::string Mensaje ((std::istreambuf_iterator<char>(M)), (std::istreambuf_iterator<char>())); //Conversión de .txt a string
    std::ofstream fout; 
    fout.open ("Cifrado.txt"); //Mensaje de salida
    fout <<Cifrador (Mensaje, k)<<"\n";
    fout.close(); //Cierre del mensaje de salida
  }
  else  //Si no se ingresa un k válido
  {
    std::cout <<"Inserte un k mayor que cero"<<"\n";
  }
  return 0;
}

std::string Cifrador (std::string str1, int k)
{
  std::string Alfabeto, Cifrado;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0, j = 0; i < str1.length(); i++)
  {
    if (str1[i] == Alfabeto [j])
    {
      Cifrado.push_back (Alfabeto[(j+k+26)%26]);
      j = 0; //Reemplaza la letra en posición j por su versión desplazada y reinicia el entero de comparación
    } 
    else
    {
      if (str1[i] == ' ')
      {
        Cifrado.push_back (' '); 
        j = 0; //Mantiene el espacio y reinicia el entero de comparación
      }
      else 
      {
        i--; //Permanece en la misma letra
        j++; //Cambia el entero de comparación
      }
    }
  }
  return Cifrado;
}
