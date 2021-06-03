#include <iostream>
namespace lasd {

/* ************************************************************************** */

template <typename Data>
MatrixVec<Data>::MatrixVec(unsigned long newRow, unsigned long newColumn)
{
  Vector<Data>::Resize(newRow * newColumn);
  row    = newRow;
  column = newColumn;

}

//Copy Constructor
template <typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec<Data>& matrice) : Vector<Data>::Vector(matrice)
{
  row    = matrice.row;
  column = matrice.column;

}

//Move constructor
template <typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec<Data>&& matrice) noexcept : Vector<Data>::Vector(std::move(matrice))
{
  std::swap(row, matrice.row);
  std::swap(column, matrice.column);

}

template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(const MatrixVec<Data>& matrice)
{
  Vector<Data>::operator=(matrice);
  row    = matrice.row;
  column = matrice.column;

  return *this;
}
template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(MatrixVec<Data>&& matrice) noexcept
{
  Vector<Data>::operator=(std::move(matrice));
  std::swap(row, matrice.row);
  std::swap(column, matrice.column);

  return *this;
}

template <typename Data>
bool MatrixVec<Data>::operator==(const MatrixVec<Data>& matrice) const noexcept
{
  return Vector<Data>::operator==(matrice);
}

template <typename Data>
bool MatrixVec<Data>::operator!=(const MatrixVec<Data>& matrice) const noexcept
{
  return Vector<Data>::operator!=(matrice);
}

template <typename Data>
void MatrixVec<Data>::Clear()
{
  Vector<Data>::Clear();
  row    = 0;
  column = 0;
}

template <typename Data>
void MatrixVec<Data>::RowResize(unsigned long resizeRow)
{
  // if(resizeRow == 0)
  //   Clear();
  // else
  // {
  //   if(column == 0)
  //     column = 1;
  //   Vector<Data>::Resize(resizeRow * column);
  //   row = resizeRow;
  // }
  unsigned long c = column;
  Vector<Data>::Resize(resizeRow * column); // ci salviamo c, perchè nel resize di Vector viene cambiata.
  column = c;
  row = resizeRow;

}

template <typename Data>
void MatrixVec<Data>::ColumnResize(unsigned long resizeColumn)
{

    if(resizeColumn != column)
    {
      Data* TmpElements = new Data[row * resizeColumn]{};

      int limit = (column < resizeColumn) ? column : resizeColumn;
      for(unsigned long i = 0; i < row; i++)
      {
        for(unsigned long j = 0; j < limit; j++)
        {
            std::swap(Elements[(i * column) + j], TmpElements[(i * resizeColumn) + j]);
        }
      }
      std::swap(Elements, TmpElements);
      delete []TmpElements;
      size = row * resizeColumn;
      column = resizeColumn;
    }
    else if(resizeColumn == 0)
      Clear();


}

template <typename Data>
bool MatrixVec<Data>::ExistsCell(const unsigned long cellRow, const unsigned long cellColumn) const noexcept
{
  if( ( (cellRow * column) + cellColumn ) < ( row * column ))
    return true;
  else
    return false;
}

template <typename Data>
Data& MatrixVec<Data>::operator()(const unsigned long r, const unsigned long c)
{
  return const_cast<Data&>(static_cast<const MatrixVec<Data>*>(this)->operator()(r, c));
}

template <typename Data>
const Data& MatrixVec<Data>::operator()(const unsigned long r, const unsigned long c) const
{
  if(ExistsCell(r,c))
    return Elements[(r * column) + c];
  else
    throw std::out_of_range("Non e' possibile accedere a questa cella, non esiste nella matrice.");
}

template<typename Data>
MatrixVec<Data>::~MatrixVec()
{
  Clear();
}
template<typename Data>
MatrixVec<Data>::MatrixVec()
{
  row = 0;
  column = 0;
  Vector<Data>::Clear();

}
/* ************************************************************************** */

}
