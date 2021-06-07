
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
   for(unsigned int i = 0; i < row; i++)
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
    int scelta = -1;
    lasd::MatrixVec<int>    intMatrix;
    lasd::MatrixVec<float>  floatMatrix;
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

    cout << "Benvenuto nel Menu di MatrixVector" << endl;
    while(scelta != 0)
    {
      cout << "1. Controlla l'esistenza di un valore" << endl;
      cout << "2. Stampa MAP ( Pre-Order | Post - Order )" << endl;
      if(tipo == 1)
      {
        cout << "3. Prodotto Minori di n" << endl;
        cout << "4. 2n per gli interi" << endl;
      }
      if(tipo == 2)
      {
        cout << "3. Somma per i float maggiori di n" << endl;
        cout << "4. (-n)^3 per i float" << endl;
      }
      if(tipo == 3)
      {
        cout << "3. Concatenazione per le stringhe con lunghezza minore o uguale a n" << endl;
        cout << "4. Concatenazione in testa di una specifica stringa" << endl;
      }
      cout << "5. Leggi una cella" << endl;
      cout << "6. Controllo di esistenza" << endl;
      cout << "7. Inserimento di un elemento" << endl;
      cout << "8. Ridmensionamento Matrice" << endl;
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
        cout << "1: Pre  - Order" << endl;
        cout << "2: Post - Order" << endl;
        cin  >> stampa;
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
      if(scelta == 3 && tipo == 1)
      {
        int n2 = 0;
        int prod = 1;
        cout << "Inserisci un intero" << endl;
        cin  >> n2;
        intMatrix.FoldPreOrder([](const int & dat,
            const void * n2, void * prod) {
            if (dat < * ((int * ) n2)) {
              *((int * ) prod) *= dat;
            }
          }, & n2, & prod);
          cout << "Il prodotto degli interi (minori di " << n2 << ") e' : " << prod << endl;
      }
      if(scelta == 3 && tipo == 2)
      {
        float n2 = 0;
        float sum = 0;
        cout << "Inserisci un n(float):" << endl;
        cin  >> n2;
        floatMatrix.FoldPreOrder([](const float & dat,
        const void * n2, void * sum)
        {
          if (dat > * ((float * ) n2))
          {
            *((float * ) sum) += dat;
          }
        }, & n2, & sum);
        cout << "La somma dei float (maggiori di " << n2 << ") e' : " << sum << endl;
      }
      if(scelta == 3 && tipo == 3)
      {
        string stringa = "";
        int n2 = 0;
        cout << "Inserisci la lunghezza" << endl;
        cin >> n2;
        stringMatrix.FoldPreOrder([](const string & dat,
           const void * n2, void * stringa) {
           if (dat.size() <= * ((int * ) n2)) {
             *((string * ) stringa) += dat;
           }
         }, & n2, & stringa);

         cout << "Concatenazione delle stringhe (con lunghezza minore o uguale a " << n2 << ") e' : " << stringa << endl;
      }
      if(scelta == 4 && tipo == 1)
      {
        intMatrix.MapPreOrder([](int & dat, void * )
        {
           dat = 2 * dat;
        }, nullptr);
        cout << "Funzione 2n applicata alla Matrice";
        cout << endl;
      }
      if(scelta == 4 && tipo == 2)
      {
        floatMatrix.MapPreOrder([](float & dat, void * )
        {
            dat = -dat;
            dat = dat * dat * dat;
        }, nullptr);
        cout << "Funzione -n^3 applicata alla Matrice";
        cout << endl;
      }
      if(scelta == 4 && tipo == 3)
      {
        string stringa = "";
        cout << "Inserisci una stringa da concatenare:" << endl;
        cin >> stringa;

        cout << "La stringa "<< stringa <<" e' stata concatenata a tutti gli elementi della matrice" << endl;
        stringMatrix.MapPreOrder([](string& dat, void* parola ){
          dat = *static_cast<string*>(parola)+dat;
        }, &stringa);
      }
      if(scelta == 5)
      {
          int r = 0;
          int c = 0;
          cout << "Inserisci la cella che vuoi leggere" << endl;
          cout << "Inserisci (r , c)" << endl;
          cout << "Inserisci r" << endl;
          cin  >> r;
          cout << "Inserisci c" << endl;
          cin  >> c;
          if(tipo == 1)
          {
            if(intMatrix.ExistsCell(r,c))
              cout << "La cella che vuoi leggere --> " << intMatrix(r,c) << endl;
            else
              cout << "La cella non esiste - Impossibile leggerla" << endl;
          }
          if(tipo == 2)
          {
            if(floatMatrix.ExistsCell(r,c))
              cout << "La cella che vuoi leggere --> " << floatMatrix(r,c) << endl;
            else
              cout << "La cella non esiste - Impossibile leggerla" << endl;
          }
          if(tipo == 3)
          {
            if(stringMatrix.ExistsCell(r,c))
              cout << "La cella che vuoi leggere --> " << stringMatrix(r,c) << endl;
            else
              cout << "La cella non esiste - Impossibile leggerla" << endl;
          }
      }
      if(scelta == 6)
      {
        int r = 0;
        int c = 0;
        cout << "Inserisci la cella" << endl;
        cout << "Inserisci (r , c)" << endl;
        cout << "Inserisci r" << endl;
        cin  >> r;
        cout << "Inserisci c" << endl;
        cin  >> c;
        if(tipo == 1)
        {
          if(intMatrix.ExistsCell(r,c))
            cout << "La cella che vuoi leggere Esiste" << endl;
          else
            cout << "La cella non esiste" << endl;
        }
        if(tipo == 2)
        {
          if(floatMatrix.ExistsCell(r,c))
            cout << "La cella che vuoi leggere Esiste" << endl;
          else
            cout << "La cella non esiste" << endl;
        }
        if(tipo == 3)
        {
          if(stringMatrix.ExistsCell(r,c))
            cout << "La cella che vuoi leggere Esiste" << endl;
          else
            cout << "La cella non esiste" << endl;
        }
      }
      if(scelta == 7)
      {
        int r = 0;
        int c = 0;
        int elemento = 0;
        float elemento1 = 0;
        string elemento2 = "";
        cout << "Inserisci la cella" << endl;
        cout << "Inserisci (r , c)" << endl;
        cout << "Inserisci r" << endl;
        cin  >> r;
        cout << "Inserisci c" << endl;
        cin  >> c;
        cout << "Che elemento vuoi inserire?" << endl;
        if(tipo == 1)
        {
          try{
            cin >> elemento;
            intMatrix(r,c) = elemento;
          }catch(exception e)
          {
            cout << "Non puoi inserie in quella cella, non esiste" << endl;
          }
        }
        if(tipo == 2)
        {
          try{
            cin >> elemento1;
            floatMatrix(r,c) = elemento;
          }catch(exception e)
          {
            cout << "Non puoi inserie in quella cella, non esiste" << endl;
          }
        }
        if(tipo == 3)
        {
          try{
            cin >> elemento2;
            stringMatrix(r,c) = elemento;
          }catch(exception e)
          {
            cout << "Non puoi inserie in quella cella, non esiste" << endl;
          }
        }
      }
      if(scelta == 8)
      {
        int ridmensionamento;
        int newValue = 0;
        cout << "1: Ridmensiona Colonne " << endl;
        cout << "2: Ridmensiona Righe " << endl;
        cin  >> ridmensionamento;
        if(ridmensionamento == 1)
        {
          cout << "Nuove colonne : " << endl;
          cin >> newValue;
          if(tipo == 1)
          {
            if(column == newValue)
              cout << "Hai inserito le stesse colonne, nessun cambiamento" << endl;
            else
              intMatrix.ColumnResize(newValue);
          }
          if(tipo == 2)
          {
            if(column == newValue)
              cout << "Hai inserito le stesse colonne, nessun cambiamento" << endl;
            else
              floatMatrix.ColumnResize(newValue);
          }
          if(tipo == 3)
          {
            if(column == newValue)
              cout << "Hai inserito le stesse colonne, nessun cambiamento" << endl;
            else
              stringMatrix.ColumnResize(newValue);
          }

        }
        if(ridmensionamento == 2)
        {
          cout << "Nuove righe : " << endl;
          cin >> newValue;
          if(tipo == 1)
          {
            if(row == newValue)
              cout << "Hai inserito le stesse colonne, nessun cambiamento" << endl;
            else
              intMatrix.RowResize(newValue);
          }
          if(tipo == 2)
          {
            if(row == newValue)
              cout << "Hai inserito le stesse colonne, nessun cambiamento" << endl;
            else
              floatMatrix.RowResize(newValue);
          }
          if(tipo == 3)
          {
            if(row == newValue)
              cout << "Hai inserito le stesse colonne, nessun cambiamento" << endl;
            else
              stringMatrix.RowResize(newValue);
          }
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

    if(scelta == 1)
      MenuVector(tipo, row, column);
    if(scelta == 2)
      MenuCSR(tipo, row, column);
  }


}
