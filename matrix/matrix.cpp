
namespace lasd {

/* ************************************************************************** */

template <typename Data>
unsigned long Matrix<Data>::RowNumber() const noexcept
{
  return row;
}
template <typename Data>
unsigned long Matrix<Data>::ColumnNumber() const noexcept
{
  return column;
}
/* ************************************************************************** */

}
