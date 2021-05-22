
#ifndef MATRIX_HPP
#define MATRIX_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Matrix : virtual public MappableContainer<Data>, virtual public FoldableContainer<Data>
{

private:

  // ...

protected:

  unsigned long row = 0;
  unsigned long column = 0;

public:

  // Destructor
  virtual ~Matrix() = default;

  /* ************************************************************************ */

  // Copy assignment
  Matrix& operator=(const Matrix&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Matrix& operator=(Matrix&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Matrix<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Matrix<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  unsigned long RowNumber()    const noexcept; // (concrete function should not throw exceptions) //implementare a questo livello
  unsigned long ColumnNumber() const noexcept; // (concrete function should not throw exceptions) //implementare a questo livello

  virtual void RowResize(unsigned long) = 0;
  virtual void ColumnResize(unsigned long) = 0;

  virtual bool ExistsCell(unsigned long row, unsigned long column) noexcept = 0; // (concrete function should not throw exceptions) // Se va fuori alle ROW/COLUMN direttamente false. (IF)
  //Se esiste la cella, è tutto uno con il dato, se esiste una cella esiste il dato in essa.

  Data& operator()(unsigned long row, unsigned long column) = 0; // Mutable access to the element (concrete function should throw exceptions only when out of range)
  const Data& operator()(unsigned long row, unsigned long column) const = 0; // Immutable access to the element (concrete function should throw exceptions when not present)

};

/* ************************************************************************** */

}

#include "matrix.cpp"

#endif
