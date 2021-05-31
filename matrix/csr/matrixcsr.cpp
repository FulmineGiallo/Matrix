
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
  std::swap(testa, matrice.testa);
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
void MatrixCSR<Data>::RowResize(unsigned long newRow)
{
  if(newRow < row){
      Node* tmp = *vector[newRow];
      Node* current = nullptr;
      while(tmp != nullptr){
        current = tmp;
        tmp = tmp->next;
        delete current;
      }
      row = newRow;
      vector.Resize(row + 1);
    }
    if(newRow > row){
      if(row == 0){
          vector.Resize(newRow + 1);
          for(unsigned long i = row; i < newRow + 1; i++) vector[i] = &testa;
          row = newRow;
      }
      else{
        vector.Resize(newRow + 1);
        for(unsigned long i = row; i < newRow; i++) vector[i+1] = vector[i];
        row = newRow;
      }
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
          column = resizeColumn;

}

template <typename Data>
bool MatrixCSR<Data>::ExistsCell(const unsigned long cellRow, const unsigned long cellColumn) const noexcept
{
  if ((cellRow < row) && (cellColumn < column)){
     Node** ptr = vector[cellRow];
     while(ptr != vector[cellRow + 1])
     {
       Node& nod = **ptr;
       if(nod.element.first == cellColumn){
         return true;
       }
       ptr = &(nod.next);
     }
   }
   return false;

}

template<typename Data>
Data& MatrixCSR<Data>::operator()(const unsigned long currRow, const unsigned long currCol)
{
  if((currRow < row) && (currCol < column)){
        Node** pointer = vector[currRow];
        Node** ext = vector[currRow + 1];
        while((pointer != ext)  && (*pointer)->element.first <= currCol){
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
    }else{
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
      if(nod.element.first == c){
        return nod.element.second;
      }
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
  row = 0;
  column = 0;
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
