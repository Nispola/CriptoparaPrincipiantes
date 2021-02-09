#include <algorithm>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

std::string Reemplazo(std::string str); //Impide la manifestación del caracter 'j' en la cadena

int main(void)
{
 std::ifstream ifs ("Mensaje.txt"); //Mensaje de entrada
  std::string str ((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>())); //Conversión de .txt a string
  std::string::iterator end_pos = std::remove(str.begin(),str.end(), ' ');
  str.erase(end_pos, str.end()); //Elimina los espacios del texto
  std::string Alfabeto;
  Alfabeto = "abcdefghiklmnopqrstuvwxyz"; //Alfabeto base, nótese la omisión de la j
  std::ofstream fout; 
  fout.open ("Cifrado.txt"); //Mensaje de salida
  for (int i = 0, j = 0; i < Reemplazo(str).length(); i++)
  {
    if (Reemplazo(str)[i] == Alfabeto[j])
    {
      int Fila = floor((j+5)/5); //Por la distribución de los digitos siempre se va a cumplir que la división por 5 de todos los elementos en una fila es mayor o igual que el índice de la fila en la que se encuentran y estrictamente menor que el de la próxima. Con el uso de la función piso puede encontrarse dicho índice, el 5 se agrega para empezar el conteo en 1
      int Columna = (j+5)%5 + 1; //Dada la distribución de la matriz, cada elemento en una misma columna está a 5 espacios del próximo o el anterior. A partir de los restos puede identificarse la columna en la que se encuentra el caracter y el 1 se añade para que el conteo empiece en 1 en lugar de 0
      fout <<Fila<<Columna<<"/";
      j = 0; //Reinicia el entero de comparación
    }
    else 
    {
      i--; //Mantiene el mismo caracter
      j++; //Cambia el entero de comparación
    }
  }
  fout.close(); //Cierre del mensaje de salida
  return 0;
}

std::string Reemplazo(std::string str)
{
  std::string Alfabeto;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz";
  std::string Corregida;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == 'j')
    {
      Corregida.push_back('i'); 
    else 
    {
      Corregida.push_back(str[i]);
    }
  }
  return Corregida;
}
