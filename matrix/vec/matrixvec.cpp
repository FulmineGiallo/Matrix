
namespace lasd {

/* ************************************************************************** */

template <typename Data>
MatrixVec<Data>::MatrixVec(unsigned long row, unsigned long column)
{
  Vector<Data>::Resize(row*column);
}

//Copy Constructor
template <typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec<Data>& matrice) : Vector<Data>::Vector(matrice) {}

//Move constructor
template <typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec<Data>&& matrice) noexcept : Vector<Data>::Vector(std::move(matrice)) {}

template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(const MatrixVec<Data>& matrice)
{
  Vector<Data>::operator=(matrice);
  return *this;
}
template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(MatrixVec<Data>&& matrice) noexcept
{
  Vector<Data>::operator=(std::move(matrice));
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
  row = 0;
  column = 0;
}

template <typename Data>
void MatrixVec<Data>::RowResize(unsigned long resizeRow)
{
  Vector<Data>::Resize(resizeRow * column);
}

template <typename Data>
void MatrixVec<Data>::ColumnResize(unsigned long resizeColumn)
{
  if(resizeColumn < column)
  {
    Vector<Data> vec(row * resizeColumn);
    unsigned long j = 0;
    unsigned long k = 0;
    for(unsigned long i = 0; i < row * column; i++, k++)
    {
      if( j == resizeColumn )
      {
        i = i + (column - resizeColumn);
        j = 0;
      }
      if( i < row * column)
        vec[k] = this[i];
      j++;
    }
    std::swap(this.Element, vec.Elements);
    vec.Clear();
  }
  if(resizeColumn > column)
  {
    Vector<Data> vec(row * resizeColumn);
    unsigned long j = 0;
    unsigned long i = 0;
    for(int i = 0; i < vec.Size(); i++)
      vec[i] = {};

    for(int k = 0; k < row * resizeColumn; i++, k++)
    {
      if(j == column)
      {
        i = i + (resizeColumn - column);
        j = 0;
      }
      if(i < row * resizeColumn)
        vec[i] = this[k];
      j++;
    }
    std::swap(this.Element, vec.Elements);
    vec.Clear();
  }
}

template <typename Data>
bool MatrixVec<Data>::ExistsCell(unsigned long cellRow, unsigned long cellColumn) noexcept
{
  if(cellRow <= row - 1 && cellColumn <= column - 1)
    return true;
  else
    return false;
}
/* ************************************************************************** */

}
