
namespace lasd
{

/* ************************************************************************** */
template <typename Data>
MatrixCSR<Data>::MatrixCSR(const unsigned long r, const unsigned long c)
{
  row = r;
  column = c;
  vector.Resize(r + 1);
  for(unsigned long i = 0; i <= r ; ++i)
    vector[i] = &testa;
}
/* ************************************************************************** */
//Copy Constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR<Data>& matrice)
{
  /* scorrere vecchia matrice, e fare la nuova matrice per inserimento */

}

//Move constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(MatrixCSR<Data>&& matrice) noexcept
{
  std::swap(row, matrice.row);
  std::swap(column, matrice.column);
  std::swap(vector, matrice.vector);
  std::swap(head, matrice.head);
}

template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR<Data>& matrice)
{

  row    = matrice.row;
  column = matrice.column;

  return *this;
}

template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR<Data>&& matrice) noexcept
{
  std::swap(row, matrice.row);
  std::swap(column, matrice.column);

  return *this;
}

template <typename Data>
bool MatrixCSR<Data>::operator==(const MatrixCSR<Data>& matrice) const noexcept
{
  if(row == matrice.row && column == matrice.column)
  {
    int i = 0;
    Node** ptr1 = vector[0];
    Node** ptr2 = matrice.vector[0];

    while(ptr1 != nullptr && ptr2 != nullptr)
    {
      while(ptr1 != vector[i + 1] && ptr2 != matrice.vector[i + 1])
      {
        if((*ptr1)->element.second != (*ptr2)->element.second)
          return false;
      }
      ptr1 = *ptr1;
      ptr2 = *ptr2;
    }
    return true;
  }
  else
    return false;
}

template <typename Data>
bool MatrixCSR<Data>::operator!=(const MatrixCSR<Data>& matrice) const noexcept
{
  return !(*this == matrice);
}

template <typename Data>
void MatrixCSR<Data>::Clear()
{
  vector.Resize(1);
  List<std::pair<unsigned long, Data>>::Clear();
  row = 0;
  column = 0;
}

template <typename Data>
void MatrixCSR<Data>::RowResize(unsigned long resizeRow)
{

  // resizeRow == 3; row 5
  // Vettore.Size() == 6
  if( resizeRow < row)
  {
    Node* tmp = *vector[resizeRow];
    vector[resizeRow] = &coda->next;

    Node* curr = nullptr;
    while(tmp != nullptr)
    {
      curr = tmp;
      tmp = tmp->next;
      delete curr;
    }
    row = resizeRow;
    vector.Resize(row + 1);
  }
  else
  {
    vector.Resize(resizeRow + 1);
    for(int i = row + 1; i < resizeRow + 1; i++)
      vector[i] = &coda->next;

    row = resizeRow;
  }
}

template <typename Data>
void MatrixCSR<Data>::ColumnResize(unsigned long resizeColumn)
{
  if(resizeColumn < column)
  {
    if(resizeColumn == 0)
      Clear();
    else
    {

    }
  }
  else if(resizeColumn > column)
          coulmn = resizeColumn;

}

template <typename Data>
bool MatrixCSR<Data>::ExistsCell(const unsigned long cellRow, const unsigned long cellColumn) const noexcept
{


}

template <typename Data>
Data& MatrixCSR<Data>::operator()(const unsigned long r, const unsigned long c)
{
  //Inserimento in coda alla riga
  //Esempio Riga:   1 -  -  - - 3 - - - voglio inserire dopo il tre
  Node** ptr = vector[rigaScelta];
  bool inserimento = false;
  while(ptr != vector[rigaScelta + 1])
  {
    //In questo while posso inserire anche in mezzo
    if((*ptr)->element.second > c)
      //Inserisci prima in Ptr il nuovo nodo
      inserimento = true;
    else
      ptr = *ptr;
  }
  //Se sei uscito dal while senza inserire
  if(inserimento = false)
  //Inserisci dopo ptr
  //Aggiornamento vector
  vector[rigaScelta] = ptr;
}

template <typename Data>
const Data& MatrixCSR<Data>::operator()(const unsigned long r, const unsigned long c) const
{
  //Una volta inserita il dato, il dato esiterà sempre
  //Bisogna controllare anche se è il primo elemento di una riga, se lo è, dobbiamo collegare la riga (vett) al nuovo nodo creato.
  //Ogni volta, se quel elemento inserito viene prima in ordine di riga, bisogna cambiare il puntatore del vettore di riga.
  // Operator ()() (const)
    if(r > row || c > column)
      throw std::out_of_range("Impossibile accedere alla posizione, matrice di dimensioni minori!");
    else
    {
      Node** ptr = Nodes[r];
      while(ptr != Nodes[r + 1])
      {
        Node& nod = **ptr;
        if(nod.element.first == c)
        {
          return nod.element.second;
        }
        ptr = &(nod.next);
      }
    }
     throw std::length_error("Cella non presenta all'interno della Matrice!");

}

template<typename Data>
MatrixCSR<Data>::~MatrixCSR()
{
  Clear();
}
template<typename Data>
MatrixCSR<Data>::MatrixCSR()
{
  vector.Resize(1);
  vector[0] = &head;
  row = 0;
  column = 0;
}
/* ************************************************************************** */
template<typename Data>
void MatrixCSR<Data>::MapPreOrder(const MapFunctor fun, void* acc)
{

}

template<typename Data>
void MatrixCSR<Data>::MapPostOrder(const MapFunctor fun, void* acc)
{

}

template<typename Data>
void MatrixCSR<Data>::FoldPreOrder(const FoldFunctor fun, const void* data, void* acc) const
{

}

template<typename Data>
void MatrixCSR<Data>::FoldPostOrder(const FoldFunctor fun, const void* data, void* acc) const
{

}



/* ************************************************************************** */

}
