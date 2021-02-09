#include <fstream>
#include <string>

std::string Cifrador (std::string str1); //Función cifradora

int main (void)
{
  std::ifstream M ("Mensaje.txt"); //Mensaje de entrada
  std::string Mensaje ((std::istreambuf_iterator<char>(M)), (std::istreambuf_iterator<char>())); //Conversión de .txt a string
  std::ofstream fout; 
  fout.open ("Cifrado.txt"); //Mensaje de salida
  fout <<Cifrador (Mensaje)<<"\n";
  fout.close(); //Cierre del mensaje de salida
  return 0;
}

std::string Cifrador (std::string str1)
{
  std::string Alfabeto, Cifrado;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz"; //Alfabeto inglés
  for (int i = 0, j = 0; i < str1.length(); i++)
  {
    if (str1[i] == Alfabeto [j])
    {
      Cifrado.push_back (Alfabeto[(51-j)%26]); 
      j = 0; //Reemplaza la letra en posición j por su equivalente en el alfabeto invertido, reinicia el entero de comparación
    } 
    else
    {
      if (str1[i] == ' ')
      {
        Cifrado.push_back (' '); 
        j = 0; //Omite los espacios y reinicia el entero de comparación
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
