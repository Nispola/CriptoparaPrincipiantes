#include <algorithm>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>

void printVector (const std::vector <int> & data);

int main (void)
{
  std::ifstream ifs ("Texto.txt");
  std::string str ((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>() ); //Convierte el texto en una cadena
  std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
  str.erase(end_pos, str.end()); //Elimina los espacios del texto
  for (auto & x:str) //Expresa todos los caracteres en minúscula
  {
    x = std::tolower(x);
  }
  std::string Alfabeto;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz";
  int N = Alfabeto.length();
  std::vector <int> V(N); 
  for (int i = 0, j = 0; i < str.size(); i++)
  {
    if (str[i] == Alfabeto[j])
    {
      V[j] += 1; //Cuenta las repeticiones de una misma letra
      j = 0; //Reinicia el entero de comparación
    } 
    else 
    {
      i--; //Permanece en la misma letra
      j++; //Cambia el entero de comparación
    }
  }  
printVector(V);
system("gnuplot -p -e \"plot 'Contado.txt' u 1:3 with boxes fillstyle solid 0.5 \""); //Dibuja un histograma
return 0;
}

void printVector (const std::vector <int> & data)
{
  std::ofstream fout;
  fout.open ("Contado.txt"); 
  std::string Alfabeto;
  Alfabeto = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < data.size(); i++) 
  {
    fout <<i+1<<"\t"<<Alfabeto[i]<<"\t"<<data[i]<<"\n"; 
  }
  fout.close();
}
