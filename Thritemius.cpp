#include <fstream>
#include <iostream>
#include <string>

std::string Cifrador (std::string str1); //Función cifradora
std::string Descifrador (std::string str1); //Función descifradora

int main (void)
{ 
  std::cout <<"Cifrar (c) o Descifrar (d):"<<"\n";
  char Election;
  std::cin >> Election;
  if (Election == 'c')
  {
  std::ifstream M ("Mensaje.txt"); //Mensaje de entrada
  std::string Mensaje ((std::istreambuf_iterator<char>(M)), (std::istreambuf_iterator<char>())); //Conversión de .txt a string
  std::ofstream fout; 
  fout.open ("Cifrado.txt"); //Mensaje de salida
  fout <<Cifrador (Mensaje)<<"\n";
  fout.close(); //Cierre del mensaje de salida
  }
  else if (Election == 'd')
  {
    std::ifstream M ("Code.txt"); //Mensaje de entrada
  std::string Code ((std::istreambuf_iterator<char>(M)), (std::istreambuf_iterator<char>())); //Conversión de .txt a string
  std::ofstream fout; 
  fout.open ("Decode.txt"); //Mensaje de salida
  fout <<Descifrador (Code)<<"\n";
  fout.close(); //Cierre del mensaje de salida
  }
  else 
  {
    std::cout <<"Entrada incorrecta"<<"\n";
  }
  return 0;
}

std::string Cifrador (std::string str1)
{
  std::string Alfabeto, Cifrado;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0, j = 0, k = 0; i < str1.length(); i++)
  {
    if (str1[i] == Alfabeto [j])
      {
        Cifrado.push_back (Alfabeto[(j+k+26)%26]); //Aplica una sustitución adicional según la posición del caracter en el mensaje
        k++; //Cuenta el caracter actual omitiendo espacios
        j = 0; //Reinicia el entero de comparación
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

std::string Descifrador (std::string str1)
{
  std::string Alfabeto, Descifrado;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0, j = 0, k = 0; i < str1.length(); i++)
  {
    if (str1[i] == Alfabeto [j])
      {
        Descifrado.push_back (Alfabeto[(j+(26*str1.length())-k)%26]); //Efectúa sustituciones que se reducen según la posición del caracter en el mensaje
        k++; //Cuenta el caracter actual omitiendo espacios
        j = 0; //Reinicia el entero de comparación
      } 
    else
    {
      if (str1[i] == ' ')
      {
        Descifrado.push_back (' '); 
        j = 0;  //Mantiene el espacio y reinicia el entero de comparación
      }
      else 
      {
        i--; //Permanece en la misma letra
        j++; //Cambia el entero de comparación
      }
    }
  }
  return Descifrado;
}
