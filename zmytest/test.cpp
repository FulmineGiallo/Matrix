
#include "test.hpp"
#include <string>
#include <string.h>
#include <string>
#include <typeinfo>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>    // std::shuffle
#include <iostream>
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
  void riempiStringa(lasd::MatrixVec<string>& v, int row, int column)
  {
   for(unsigned int i=0; i < row; i++)
   {
     for(unsigned int j = 0; j < column; j++)
     {
        v(i, j) = rand_str(5);
     }
   }
  }
  template<typename Data>
  void riempi(lasd::MatrixVec<Data>& v, int row, int column)
  {
      Data dataRandom;
      srand ((unsigned int)time(NULL));
      std::string type_name();
      for(unsigned int i = 0; i < row; i++)
      {
        for(unsigned int j = 0; j < column; j++)
        {
           dataRandom = (Data)rand() / 100 + 1;
           v(i, j) = dataRandom;
        }
      }
  }
  void MenuVector(int tipo, int row, int column)
  {
    lasd::MatrixVec<int> intMatrix;
    lasd::MatrixVec<float> floatMatrix;
    lasd::MatrixVec<string> stringMatrix;
    if(tipo == 1)
    {
      intMatrix.RowResize(row);
      intMatrix.ColumnResize(column);
      riempi(intMatrix, row, column);
    }
    if(tipo == 2)
    {
      floatMatrix.RowResize(row);
      floatMatrix.ColumnResize(column);
      riempi(floatMatrix, row, column);
    }
    if(tipo == 3)
    {
      stringMatrix.RowResize(row);
      stringMatrix.ColumnResize(column);
      riempiStringa(stringMatrix, row, column);
    }

    int scelta = 1;
    cout << "Benvenuto nel Menu di MatrixVector" << endl;
    while(scelta != 0)
    {
      cout << "1. Controlla l'esistenza di un valore" << endl;
      cout << "2. Stampa MAP ( Pre-Order | Post - Order |)" << endl;
      cout << "3. " << endl;
      cout << "0. Per uscire dal programma" << endl;
      cin >> scelta;

      if(scelta == 1)
      {
        if(tipo == 1)
        {
          int trova = 0;
          cout << "Inserisci l'elemento che vuoi cercare" << endl;
          cin  >> trova;
          if(intMatrix.Exists(trova))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
        }
        if(tipo == 2)
        {
          float trova = 0;
          cout << "Inserisci l'elemento che vuoi cercare" << endl;
          cin  >> trova;
          if(floatMatrix.Exists(trova))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
        }
        if(tipo == 3)
        {
          string trova = "";
          cout << "Inserisci l'elemento che vuoi cercare" << endl;
          cin  >> trova;
          if(stringMatrix.Exists(trova))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
        }
      }
      if(scelta == 2)
      {
        int stampa = 0;
        cout << "1: Pre - Order" << endl;
        cout << "2: Post - Order" << endl;
        cin >> stampa;
        if(stampa == 1)
        {
          if(tipo == 1)
            intMatrix.MapPreOrder([](int& dat, void*){std::cout << dat << std::endl;}, nullptr);
          if(tipo == 2)
            floatMatrix.MapPreOrder([](float& dat, void*){std::cout << dat << std::endl;}, nullptr);
          if(tipo == 3)
            stringMatrix.MapPreOrder([](string& dat, void*){std::cout << dat << std::endl;}, nullptr);
        }
        if(stampa == 2)
        {
          if(tipo == 1)
            intMatrix.MapPostOrder([](int& dat, void*){std::cout << dat << std::endl;}, nullptr);
          if(tipo == 2)
            floatMatrix.MapPostOrder([](float& dat, void*){std::cout << dat << std::endl;}, nullptr);
          if(tipo == 3)
            stringMatrix.MapPostOrder([](string& dat, void*){std::cout << dat << std::endl;}, nullptr);
        }
      }
    }
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
