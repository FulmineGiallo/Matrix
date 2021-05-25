
namespace lasd
{

/* ************************************************************************** */
template <typename Data>
MatrixCSR<Data>::MatrixCSR(const unsigned long r, const unsigned long c)
{
  vector.Resize(r + 1);
  for(unsigned long i = 0; i < r + 1; i++)
  {
    vector[i] = testa;
  }
  row = r;
  column = c;
}


/* ************************************************************************** */


//Copy Constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR<Data>& matrice)
{
  row    = matrice.row;
  column = matrice.column;

}

//Move constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(MatrixCSR<Data>&& matrice) noexcept
{
  std::swap(row, matrice.row);
  std::swap(column, matrice.column);

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
  return Vector<Data>::operator==(matrice);
}

template <typename Data>
bool MatrixCSR<Data>::operator!=(const MatrixCSR<Data>& matrice) const noexcept
{
  return Vector<Data>::operator!=(matrice);
}

template <typename Data>
void MatrixCSR<Data>::Clear()
{
  Vector<Data>::Clear();
  row    = 0;
  column = 0;
}

template <typename Data>
void MatrixCSR<Data>::RowResize(unsigned long resizeRow)
{


}

template <typename Data>
void MatrixCSR<Data>::ColumnResize(unsigned long resizeColumn)
{


}

template <typename Data>
bool MatrixCSR<Data>::ExistsCell(const unsigned long cellRow, const unsigned long cellColumn) const noexcept
{

  if( ( (cellRow * column) + cellColumn ) < ( row * column ))
    return true;
  else
    return false;
}

template <typename Data>
Data& MatrixCSR<Data>::operator()(const unsigned long r, const unsigned long c)
{
  return const_cast<Data&>(static_cast<const MatrixCSR<Data>*>(this)->operator()(r, c));
}

template <typename Data>
const Data& MatrixCSR<Data>::operator()(const unsigned long r, const unsigned long c) const
{
  if(ExistsCell(r,c))
    return vector[(r * column) + c];
  else
    throw std::out_of_range("Non e' possibile accedere a questa cella, non esiste nella matrice.");
}

template<typename Data>
MatrixCSR<Data>::~MatrixCSR()
{
  Clear();
}
template<typename Data>
MatrixCSR<Data>::MatrixCSR()
{
  row = 0;
  column = 0;

}
/* ************************************************************************** */
template<typename Data>
void MatrixCSR<Data>::MapPreOrder(const MapFunctor fun, void* acc){

}

template<typename Data>
void MatrixCSR<Data>::MapPostOrder(const MapFunctor fun, void* acc){

}

template<typename Data>
void MatrixCSR<Data>::FoldPreOrder(const FoldFunctor fun, const void* data, void* acc) const{

}

template<typename Data>
void MatrixCSR<Data>::FoldPostOrder(const FoldFunctor fun, const void* data, void* acc) const{

}


/* ************************************************************************** */

}
