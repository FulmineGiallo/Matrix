
#ifndef MATRIXCSR_HPP
#define MATRIXCSR_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MatrixCSR : virtual public Matrix<Data>, public List<Data> 
{

private:

  // ...

protected:

  // using Matrix<Data>::???;

  //using Vector<Data> vec;
  //Vector per le righe puntatori
  //Colonne e dati tramite List, meglio ereditarla.
public:

  // Default constructor
  // MatrixCSR() specifiers; //matrice vuota, dim 0 x 0 senza dati

  /* ************************************************************************ */

  // Specific constructors
  // MatrixCSR(int row, int column) specifiers; // A matrix of some specified dimension
  // Non contiene dati, ma viene creata una matrice row x column
  // Vector(1) per poterlo estendere, il valore di quella cella è il riferiemento alla head.
  
  /* ************************************************************************ */

  // Copy constructor   //stare attenti alla copia, non è possibile copiare il vettore di righe.
  // scorrere la vecchia matrice, fare un nuova matrice per inserimento.
  // Head = nullptr, tutte le altre celle puntano ad Head.
  // MatrixCSR(argument) specifiers;

  // Move constructor, swap di puntatori.
  // MatrixCSR(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~MatrixCSR() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators, non si possono controllare i puntatori delle righe, si devono controllare i dati.
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

  // type RowResize() specifiers; // Override Matrix member
  // type ColumnResize() specifiers; // Override Matrix member

  // bool ExistsCell() noexcept override; // Override Matrix member (should not throw exceptions)

  // type operator()() specifiers; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
  // type operator()() specifiers; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member, row = 0 column = 0

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // type MapPreOrder(arguments) specifiers; // Override MappableContainer member
  // type MapPostOrder(arguments) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Override FoldableContainer member
  // type FoldPostOrder(arguments) specifiers; // Override FoldableContainer member

};

/* ************************************************************************** */

}

#include "matrixcsr.cpp"

#endif
