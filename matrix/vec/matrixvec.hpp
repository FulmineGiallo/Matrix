
#ifndef MATRIXVEC_HPP
#define MATRIXVEC_HPP

/* ************************************************************************** */

#include "../matrix.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */
//Row Major
template <typename Data>
class MatrixVec : virtual public Matrix<Data>, protected Vector<Data>
{

private:

  // ...

protected:

  // using Matrix<Data>::???;

  // ...

public:

  // Default constructor
  MatrixVec(); //Matrice vuota, ROW = 0, COLUMN = 0

  /* ************************************************************************ */

  // Specific constructors
  MatrixVec(int row, int column); // A matrix of some specified dimension

  /* ************************************************************************ */
  //Possibile utilizzare il vettore da qui a
    // Copy constructor
    // MatrixVec(argument) specifiers;

    // Move constructor
    // MatrixVec(argument) specifiers;

    /* ************************************************************************ */

    // Destructor
    // ~MatrixVec() specifiers;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument) specifiers;

    // Move assignment
    // type operator=(argument) specifiers;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;

  // qui.
  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

  // type RowResize() specifiers; // Override Matrix member     //Resize del vettore
  // type ColumnResize() specifiers; // Override Matrix member  //Resize del vettore, attenzione dopo il resize, la matrice non contiene i dati nell'ordine giusto

  bool ExistsCell() noexcept override; // Override Matrix member (should not throw exceptions)


  // const Data& operator()() const override; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
  // Data& operator()() override; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
  // Già dati dal vettore, fare using senza override se estendiamo vector<Data>
    // type Clear() specifiers; // Override Container member // Chiamare prima Clear() e poi Resettare ROW e COLUMN = 0

    /* ************************************************************************ */

    // Specific member functions (inherited from MappableContainer)

    // type MapPreOrder(arguments) specifiers; // Override MappableContainer member
    // type MapPostOrder(arguments) specifiers; // Override MappableContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from FoldableContainer)

    // type FoldPreOrder(arguments) specifiers; // Override FoldableContainer member
    // type FoldPostOrder(arguments) specifiers; // Override FoldableContainer member
 // fino a qui.
};

/* ************************************************************************** */

}

#include "matrixvec.cpp"

#endif
