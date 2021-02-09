#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string Deposit (std::string str); //Transforma el mensaje de entrada en forma de cadena en un número binario en forma de cadena calculado a partir de las representaciones en ASCII de los caracteres 
std::string Cifrador (std::string str1, std::string str2); //Aplica la operación XOR al mensaje
std::string Transcriptor (std::string str); //Transforma la cadena binaria resultante de la operación XOR en los respectivos caracteres ASCII de ser posible

int main(void)
{
  std::string Clave;
  std::cin >> Clave;
  std::cout <<"Cifrar (c) o Descifrar (d):"<<"\n";
  char Election;
  std::cin >> Election;
  if (Election == 'c')
  {
    std::ifstream M ("Mensaje.txt"); //Mensaje de entrada
    std::string Mensaje ((std::istreambuf_iterator<char>(M)), (std::istreambuf_iterator<char>())); //Conversión de .txt a string
    std::ofstream fout; 
    fout.open ("Cifrado.txt"); //Mensaje de salida
    fout <<"Mensaje cifrado:"<<Cifrador(Deposit(Mensaje), Deposit(Clave))<<"\n"<<"En caracteres ASCII:"<<Transcriptor(Cifrador(Deposit(Mensaje), Deposit(Clave)))<<"\n";
    fout.close(); //Cierre del mensaje de salida
  }
  else if (Election == 'd')
  {
    std::ifstream M ("Code.txt"); //Mensaje de entrada
    std::string Code ((std::istreambuf_iterator<char>(M)), (std::istreambuf_iterator<char>())); //Conversión de .txt a string
    std::ofstream fout; 
    fout.open ("Decode.txt"); //Mensaje de salida
    fout <<"Mensaje descifrado:"<<Cifrador(Code, Deposit(Clave))<<"\n"<<"En caracteres ASCII:"<<Transcriptor(Cifrador(Code, Deposit(Clave)))<<"\n";//Por simetría la clave para cifrar y descifrar es la misma
    fout.close(); //Cierre del mensaje de salida
  }
  else 
  {
    std::cout <<"Escriba una opción válida."<<"\n";
  }
  return 0;
}

std::string Deposit (std::string str)
{
  std::vector <int> V(str.length());
  for (int i = 0; i < str.length(); i++)
  {
    V[i] = str[i]; //Almacena las representaciones ASCII decimales de los caracteres
  }
  std::string Binario;
  for (int i = 0; i < V.size(); i++)
  {
    Binario += std::bitset<7>(V[i]).to_string(); //Transforma la representación decimal en la binaria y almacena en una cadena 
  }
  return Binario;
}

std::string Cifrador (std::string str1, std::string str2)
{
  std::vector <bool> M(str1.length()); //Declara un vector booleano que será rellenado con true o false según la cadena mensaje tenga 1 o 0 en la posición actual
  for (int i = 0; i < str1.length(); i++)
  {
    if (str1[i] == '1')
    {
      M[i] = true;
    }
    else 
    {
      M[i] = false;
    }
  }
  std::vector <bool> C(str2.length()); //Declara un vector booleano que será rellenado con true o false según la cadena clave tenga 1 o 0 en la posición actual
  for (int i = 0; i < str2.length(); i++)
  {
    if (str2[i] == '1')
    {
      C[i] = true;
    }
    else 
    {
      C[i] = false;
    } 
  }
  std::string K; //Declara una cadena K que será rellenada con 1 o 0 a partir del resultado de la operación XOR entre las cadenas mensaje y clave 
  for (int j = 0; j < str1.length(); j++)
  {
    if (((M[j] || C[(j+str2.length())%str2.length()]) && (!M[j] || !C[(j+str2.length())%str2.length()])) == true)
    {
      K.push_back('1');
    }
    else 
    {
      K.push_back('0');
    }
  }
return K; 
}

std::string Transcriptor (std::string str)
{
  std::vector <int> Alm (str.length()/7);
  std::string Cad;
  for (int i = 0, j = 0; i < str.length(); i++)
  {
    Cad += str[i];
    if ((i+1)%7 == 0)
    {
      Alm[j] = std::stoi(Cad,0, 2); //Cada vez que se recorren 7 caracteres de la cadena binaria, estos se transforman en un valor decimal que se almacena en el vector Alm
      j++; //Cambia la posición de guardado
      Cad = ""; //Reinicia la cadena
    }
  }
  std::string Final;
  for (int i = 0; i < Alm.size(); i++)
  {
    if (Alm[i] > 31 && Alm[i] != 127) //Límita los caracteres a los estrictamente imprimibles
    {
      char L = Alm[i]; //Convierte el entero almacenado en el vector en el caracter que representa 
      Final += L; //Añade dichos caracteres a la cadena
    }
    else 
    {
      Final += "NP"; //Non-Printable
    }
  }
  return Final;
}
