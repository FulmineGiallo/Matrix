
namespace lasd
{

/* ************************************************************************** */
template <typename Data>
MatrixCSR<Data>::MatrixCSR(const unsigned long r, const unsigned long c)
{
  // row = r;
  // column = c;
  // vector.Resize(r + 1);
  // for(unsigned long i = 0; i <= r ; ++i)
  //   vector[i] = &testa;
  vector.Resize(r + 1);
  for(unsigned long i = 0; i <= r; i++)
    vector[i] = &testa;

  column = c;
  row = r;
}
/* ************************************************************************** */
//Copy Constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR<Data>& matrice) : MatrixCSR(matrice.row, matrice.column)
{
  for(unsigned long i = 0; i < row; i++)
  {
    for(Node** ptr = matrice.vector[i]; ptr != matrice.vector[i + 1]; ptr = &((*ptr)->next))
    {
      Node& node = **ptr;
      (*this)(i, node.element.first) = node.element.second;
    }
  }
}

//Move constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(MatrixCSR<Data>&& matrice) noexcept : MatrixCSR()
{
  std::swap(size, matrice.size);
  std::swap(testa, matrice.testa);
  std::swap(row, matrice.row);
  std::swap(column, matrice.column);
  std::swap(vector, matrice.vector);
  for(unsigned long i = 0; i< vector.Size() && &matrice.testa == vector[i]; i++)
    vector[i] = &testa;
  for(unsigned long i = 0; i< matrice.vector.Size() && matrice.vector[i] == &testa; i++)
    matrice.vector[i] = &matrice.testa;
}

template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR<Data>& matrice)
{
    Clear();
    vector.Resize(matrice.row + 1);
    for(unsigned long i = 0; i <= matrice.row; i++)
      vector[i] = &testa;

    row = matrice.row;
    column = matrice.column;
    for(unsigned long i = 0; i < row; i++)
    {
      for(Node** ptr = matrice.vector[i]; ptr != matrice.vector[i + 1]; ptr = &((*ptr)->next))
      {
        Node& node = **ptr;
        (*this)(i, node.element.first) = node.element.second;
      }
    }
    return *this;
}

template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR<Data>&& matrice) noexcept
{
   std::swap(size, matrice.size);
   std::swap(testa, matrice.testa);
   std::swap(row, matrice.row);
   std::swap(column, matrice.column);
   std::swap(vector, matrice.vector);
   for(unsigned long i = 0; i< vector.Size() && &matrice.testa == vector[i]; i++)
    vector[i] = &testa;
   for(unsigned long i = 0; i< matrice.vector.Size() && matrice.vector[i] == &testa; i++)
    matrice.vector[i] = &matrice.testa;
   return *this;
}

template <typename Data>
bool MatrixCSR<Data>::operator==(const MatrixCSR<Data>& matrice) const noexcept
{
  // if(row == matrice.row && column == matrice.column)
  // {
  //   int i = 0;
  //   Node** ptr1 = vector[0];
  //   Node** ptr2 = matrice.vector[0];
  //
  //   while(ptr1 != nullptr && ptr2 != nullptr)
  //   {
  //     while(ptr1 != vector[i + 1] && ptr2 != matrice.vector[i + 1])
  //     {
  //       if((*ptr1)->element.second != (*ptr2)->element.second)
  //         return false;
  //     }
  //     ptr1 = *ptr1;
  //     ptr2 = *ptr2;
  //   }
  //   return true;
  // }
  // else
  //   return false;
  if(row == matrice.row && column == matrice.column)
  {
    Node** ptr1 = vector[0];
    Node** ptr2 = matrice.vector[0];
    for(unsigned long i = 0; i < vector.Size() - 1; ++i)
    {
      while(ptr1 != vector[i+1] && ptr2 != matrice.vector[i+1])
      {
        if((*ptr1)->element != (*ptr2)->element) //confronta i pair a prescendire
          return false;
        ptr1 = &(*ptr1)->next;
        ptr2 = &(*ptr2)->next;
      }
      if(ptr1 != vector[i+1] || ptr2 != matrice.vector[i+1]) //Ordine degli elementi
        return false;
    }
  }
  else return false;
  return true;
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
void MatrixCSR<Data>::RowResize(unsigned long newRow)
{
  if(newRow == 0)
  {
    unsigned long tmp = column;
    Clear();
    column = tmp;
  }
  else if(newRow < row)
  {
    Node* tmp;
    Node* curr = *vector[newRow];
    while(curr != nullptr)
    {
      tmp = curr;
      curr = curr->next;
      delete tmp;
      size--;
    }
    row = newRow;
    vector.Resize(row + 1);
    *vector.Back() = nullptr;
  }
  if(newRow > row)
  {
    vector.Resize(newRow + 1);
    for(unsigned long i = row; i < newRow; i++)
      vector[i+1] = vector[i];
    row = newRow;
  }
}

template <typename Data>
void MatrixCSR<Data>::ColumnResize(unsigned long newColumn)
{
  if(newColumn == 0)
  {
    List<std::pair<unsigned long, Data>>::Clear();
    for (unsigned long i = 0; i < vector.Size(); ++i)
    {
        vector[i] = &testa;
    }
    size = 0;
  }
  else if(newColumn < column)
    {
      for (unsigned long i = 0; i < row; ++i)
      {
        Node** tmp = vector[i];
        while (tmp != vector[i+1])
        {
          if ((*tmp)->element.first >= newColumn)
          {
            Node* del = *tmp;
            *tmp = del->next;
            if (&(del->next) == vector[i+1])
            {
              for(unsigned long j = i+1; j < vector.Size() && vector[j] == &(del->next); ++j)
              {
                vector[j] = tmp;
              }
            }
            del->next = nullptr;
            delete del;
            size--;
          }
          else
            tmp = &((*tmp)->next);
          }
        }
       }
       column = newColumn;
}

template <typename Data>
bool MatrixCSR<Data>::ExistsCell(const unsigned long cellRow, const unsigned long cellColumn) const noexcept
{
  if((cellRow < row) && (cellColumn < column))
  {
     Node** ptr = vector[cellRow];
     while(ptr != vector[cellRow + 1])
     {
       Node& nod = **ptr;
       if(nod.element.first == cellColumn)
         return true;

       ptr = &(nod.next);
     }
   }
   return false;

}

template<typename Data>
Data& MatrixCSR<Data>::operator()(const unsigned long currRow, const unsigned long currCol)
{
  if((currRow < row) && (currCol < column))
  {
        Node** pointer = vector[currRow];
        Node** ext = vector[currRow + 1];
        while((pointer != ext)  && (*pointer)->element.first <= currCol)
        {
            Node& node = **pointer;
            if(node.element.first == currCol){
                return node.element.second;
            }
            pointer = &(node.next);
        }

        Node* nodo = new Node();
        Node* tmp = (*pointer);
        *pointer = nodo;
        (*pointer)->next = tmp;
        nodo->element.first = currCol;
        size++;
        int i = currRow+1;
        if(pointer == ext){
            for(; i < row && vector[i] == vector[i+1]; ++i){
                vector[i] = &((*pointer)->next);
            }
            vector[i] = &((*pointer)->next);
        }
        return nodo->element.second;
    }
    else
    {
        throw std::out_of_range("Out of range error");
    }

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
    Node** ptr = vector[r];
    while(ptr != vector[r + 1])
    {
      Node& nod = **ptr;
      if(nod.element.first == c)
        return nod.element.second;

      ptr = &(nod.next);
    }
    throw std::length_error("Cella Non esiste!");
  }
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
  vector[0] = &testa;
}
/* ************************************************************************** */
// MapPreOrder
template <typename Data>
void MatrixCSR<Data>::MapPreOrder(const MapFunctor fun, void* v){
  List<std::pair<unsigned long, Data>>::MapPreOrder(
    [&fun](std::pair<unsigned long, Data>& data, void* v2){fun(data.second, v2); }
    , v);
}

// MapPostOrder
template <typename Data>
void MatrixCSR<Data>::MapPostOrder(const MapFunctor fun, void* v){
  List<std::pair<unsigned long, Data>>::MapPostOrder(
    [&fun](std::pair<unsigned long, Data>& data, void* v2){fun(data.second, v2); }
    , v);
}

// FoldPreOrder
template <typename Data>
void MatrixCSR<Data>::FoldPreOrder(const FoldFunctor fun, const void* v, void* v2) const{
  List<std::pair<unsigned long, Data>>::FoldPreOrder(
    [&fun](const std::pair<unsigned long, Data>& data, const void* v3, void* v4){ fun(data.second, v3, v4);}
  , v, v2);
}

// FoldPostOrder
template <typename Data>
void MatrixCSR<Data>::FoldPostOrder(const FoldFunctor fun, const void* v, void* v2) const{
  List<std::pair<unsigned long, Data>>::FoldPostOrder(
    [&fun](const std::pair<unsigned long, Data>& data, const void* v3, void* v4){ fun(data.second, v3, v4);}
  , v, v2);
}




/* ************************************************************************** */

}
