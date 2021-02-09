#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector <int> Registro (std::string str1); //Registro de la posición de los caracteres de la clave
std::string Cifrador (std::string str2, const std::vector <int> & V); //Función cifradora
std::string Descifrador (std::string str2, const std::vector <int> & V); //Función descifradora

int main (void)
{ 
  std::string Clave; 
  std::cin >> Clave; //Registra la clave de la cual se extraerán el número de trasposiciones a aplicar
  std::cout <<"Cifrar (c) o Descifrar (d):"<<"\n";
  char Election;
  std::cin >> Election;
  if (Election == 'c')
  {
    std::ifstream M ("Mensaje.txt"); //Mensaje de entrada
    std::string Mensaje ((std::istreambuf_iterator<char>(M)), (std::istreambuf_iterator<char>())); //Conversión de .txt a string
    std::ofstream fout; 
    fout.open ("Cifrado.txt"); //Mensaje de salida
    fout <<Cifrador (Mensaje, Registro(Clave))<<"\n";
    fout.close(); //Cierre del mensaje de salida
  }
  else if (Election == 'd')
  {
    std::ifstream M ("Code.txt"); //Mensaje de entrada
    std::string Code ((std::istreambuf_iterator<char>(M)), (std::istreambuf_iterator<char>())); //Conversión de .txt a string
    std::ofstream fout; 
    fout.open ("Decode.txt"); //Mensaje de salida
    fout <<Descifrador (Code, Registro(Clave))<<"\n";
    fout.close(); //Cierre del mensaje de salida
  }
  else
  {
    std::cout <<"Entrada incorrecta"<<"\n";
  }
  return 0;
}

std::vector <int> Registro (std::string str1)
{
  int N = str1.length();
  std::string Alfabeto;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz";
  std::vector <int> V(N); //Declara el vector en el que se guardarán las posiciones de los caracteres contenidos en la cadena "Clave" con respecto al alfabeto base
  for (int x = 0, y = 0; x < N; x++)
  {
    if (str1[x] == Alfabeto[y])
    {
      V[x] = y; //Guarda la posición en el vector
      y = 0; //Reinicia el entero de comparación
    } 
    else 
    {
      x--; //Permanece en la misma letra
      y++; //Cambia el entero de comparación
    }
  }
  return V;
}

std::string Cifrador (std::string str2, const std::vector <int> & V)
{
  std::string Alfabeto, Cifrado;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0, j = 0, k = 0; i < str2.length(); i++)
  {
    if (str2[i] == Alfabeto[j])
    {
      Cifrado.push_back (Alfabeto[(j+V[(i-k+V.size())%V.size()]+26)%26]); //Sustituye la letra del mensaje según la posición con respecto al alfabeto original del caracter de la clave con el que está relacionado
      j = 0; //Reinicia el entero de comparación
    } 
    else
    {
      if (str2[i] == ' ')
      {
        Cifrado.push_back (' '); //Evita que se intente cifrar el espacio
        j = 0; //Reinicia el entero de comparación
        k++; //Contabiliza el espacio para no asociarlo a ningún caracter de la clave
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

std::string Descifrador (std::string str2, const std::vector <int> & V)
{
  std::string Alfabeto, Descifrado;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0, j = 0, k = 0; i < str2.length(); i++)
  {
    if (str2[i] == Alfabeto[j])
    {
      Descifrado.push_back (Alfabeto[(j+(26*str2.length())-V[(i-k+V.size())%V.size()]+26)%26]); //Aplica una sustitución inversa de la letra del mensaje según la posición con respecto al alfabeto original del caracter de la clave con el que está relacionado
      j = 0;
    } 
    else
    {
      if (str2[i] == ' ')
      {
        Descifrado.push_back (' '); //Evita que se intente cifrar el espacio
        j = 0; //Reinicia el entero de comparación
        k++; //Contabiliza el espacio para no asociarlo a ningún caracter de la clave
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
