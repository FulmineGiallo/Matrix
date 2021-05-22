
#ifndef MATRIX_HPP
#define MATRIX_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Matrix : virtual public MappableContainer<Data>, virtual public FoldableContainer<Data> 
{ // Must extend MappableContainer<Data> and FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~Matrix() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  unsigned long RowNumber()    const noexcept; // (concrete function should not throw exceptions) //implementare a questo livello
  unsigned long ColumnNumber() const noexcept; // (concrete function should not throw exceptions) //implementare a questo livello

  virtual RowResize() = 0;  
  virtual ColumnResize() = 0;

  virtual bool ExistsCell(unsigned long row, unsigned long column) noexcept = 0; // (concrete function should not throw exceptions) // Se va fuori alle ROW/COLUMN direttamente false. (IF)
  //Se esiste la cella, è tutto uno con il dato, se esiste una cella esiste il dato in essa.

  virtual Data& operator()() = 0; // Mutable access to the element (concrete function should throw exceptions only when out of range)
  virtual const Data& operator()() const = 0; // Immutable access to the element (concrete function should throw exceptions when not present)

};

/* ************************************************************************** */

}

#include "matrix.cpp"

#endif
