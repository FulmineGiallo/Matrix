
namespace lasd {

/* ************************************************************************** */

template <typename Data>
MatrixVec<Data>::MatrixVec(unsigned long row, unsigned long column)
{
  Vector<Data>::Resize(row*column);
}

//Copy Constructor
template <typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec& matrice) : Vector<Data>::Vector(matrice) {}

//Move constructor
template <typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec&& matrice) noexcept : Vector<Data>::Vector(std::move(matrice)) {}

template <typename Data>
MatrixVec& MatrixVec<Data>::operator=(const MatrixVec& matrice)
{
  Vector<Data>::operator=(matrice);
  return *this;
}
template <typename Data>
MatrixVec& MatrixVec<Data>::operator=(MatrixVec&& matrice) noexcept
{
  Vector<Data>::operator=(std::move(matrice));
  return *this;
}

template <typename Data>
bool MatrixVec<Data>::operator==(const MatrixVec& matrice)
{
  return Vector<Data>::operator==(matrice);
}

template <typename Data>
bool MatrixVec<Data>::operator!=(const MatrixVec& matrice)
{
  return Vector<Data>::operator!=(matrice);
}
/* ************************************************************************** */

}
