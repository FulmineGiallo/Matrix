
// ...
#include "../vector/vector.hpp"
#include <iostream>
using namespace std;
namespace lasd
{
  std::string chars {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
  std::random_device rd;
  std::mt19937 generator(rd());
  std::string rand_str (int length)
  {
    std::string output (chars);
    std::shuffle(output.begin(), output.end(), generator);
    return output.substr(0, length);
 }
  void riempiStringa(MatrixVec<Data>& v, int row, int column)
  {
   for(unsigned int i=0; i < row * column; i++)
   {
      v[i] = rand_str(5);
   }
 }
  template<typename Data>
  void riempi(MatrixVec<Data>& v, int row, int column)
  {
      Data dataRandom;
      srand ((unsigned int)time(NULL));
      std::string type_name();
      for(unsigned int i = 0; i < row * column; i++)
      {
         dataRandom = (Data)rand() / 100 + 1;
         v[i] = dataRandom;
      }
  }
  void MenuVector(int tipo, int row, int column)
  {
    lasd::MatrixVector<int> intMatrix;
    lasd::MatrixVector<int> floatMatrix;
    lasd::MatrixVector<int> stringMatrix;
    if(tipo == 1)
    {
      intMatrix.resize(row * column);
      riempi(intMatrix);
    }
    if(tipo == 2)
    {
      floatMatrix.resize(row * column);
      riempi(floatMatrix);
    }
    if(tipo == 3)
    {
      stringMatrix.resize(row * column);
      riempi(stringMatrix);
    }


    cout << "Benvenuto nel Menu di MatrixVector" << endl;
    cout << "1. " << endl;
    cout << "2. " << endl;
    cout << "3. " << endl;
  }

  void MenuCSR(int tipo, int row, int column)
  {}
  void MenuUtente()
  {
    int scelta = 0;
    int tipo = 0;
    int row, column;
    cout << "Benvenuto" << endl;
    cout << "Cosa vuoi scegliere?" << endl;
    cout << "1: Matrix Vector" << endl;
    cout << "2: Matrix CSR"    << endl;
    cin  >> scelta;
    cout << "Che tipo vuoi utilizzare?" << endl;
    cout << "1: int" << endl;
    cout << "2: float" << endl;
    cout << "3: string" << endl;
    cin  >> tipo;
    cout << "Inserisci la dimensione di ROW" << endl;
    cin  >> row;
    cout << "Inserisci la dimensione di Column" << endl;
    cin  >> column;

    cin  >> tipo;
    if(scelta == 1)
      MenuVector(tipo, row, column);
    if(scelta == 2)
      MenuCSR(tipo, row, column);
  }


}
