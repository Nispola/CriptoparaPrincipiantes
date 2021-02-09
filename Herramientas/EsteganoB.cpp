#include <fstream>
#include <iostream>
#include <string>

std::string CaracterN (std::string str, int N); //Determina el número de desplazamientos con respecto al espacio

int main(void)
{
  int N = 0;
  std::cout <<"Escriba la posición de la letra encriptada con respecto a la palabra:"<<"\n";
   std::cin >> N;
  if (N >= 1)
  {
  std::ifstream ifs ("Cifrado.txt"); //Mensaje a cifrar
  std::string str ((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>() ); //Conversión de .txt a string
  std::ofstream fout;
  fout.open ("Descifrado.txt");
  fout <<CaracterN(str, N)<<"\n";
  fout.close();
  }
  else 
  {
    std::cout <<"Entrada incorrecta"<<"\n";
  }
}
	
std::string CaracterN (std::string str, int N)
{
  std::string Descifrado;
  bool v = true;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == ' ')
	  {
	    v = true; //Fija la condición para imprimir tras encontrar el espacio
	  }
    else if (str[i] != ' ' && v == true && str[i+N-1] != ' ')
    {
	    Descifrado.push_back(str[i+N-1]); //Imprime el caracter en la posición N con respecto a la palabra
	    v = false;
	  }
    else if (str[i] != ' ' && v == true && str[i+N-1] == ' ')
	  {
	    Descifrado.push_back(str[i+N]); //Evita la impresión de caracteres vacíos
	    v = false;
	  }
  }
  return Descifrado;
}
