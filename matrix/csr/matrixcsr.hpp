
#ifndef MATRIXCSR_HPP
#define MATRIXCSR_HPP

/* ************************************************************************** */

#include "../matrix.hpp"
#include <utility>
using namespace std;
#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MatrixCSR : virtual public Matrix<Data>, virtual protected List<Data>
{

private:

  // ...

protected:

  using Matrix<Data>::row;
  using Matrix<Data>::column;
  using List<Data>::testa;
  using List<Data>::coda;
  using typename List<Data>::Node;
  Vector<Node*> vector;
  //Vector per le righe puntatori
  //Colonne e dati tramite List, meglio ereditarla.
  pair<unsigned long, Data> pairColonna; // campo element di Node
  /*
  vector[i] = new Node();
  vector[i].element = pairColonna;
  vector[i].next = pairColonna.first;
  pairColonna(1, 100);
  */


public:

  // Default constructor
  MatrixCSR(); //matrice vuota, dim 0 x 0 senza dati

  /* ************************************************************************ */

  // Specific constructors
  MatrixCSR(const unsigned long, const unsigned long); // A matrix of some specified dimension
  // Non contiene dati, ma viene creata una matrice row x column
  // Vector(1) per poterlo estendere, il valore di quella cella è il riferiemento alla head.

  /* ************************************************************************ */

  // Copy constructor   //stare attenti alla copia, non è possibile copiare il vettore di righe.
  // scorrere la vecchia matrice, fare un nuova matrice per inserimento.
  // Head = nullptr, tutte le altre celle puntano ad Head.
  MatrixCSR(const MatrixCSR&);

  // Move constructor, swap di puntatori.
  MatrixCSR(MatrixCSR&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~MatrixCSR();

  /* ************************************************************************ */

  // Copy assignment
  MatrixCSR& operator=(const MatrixCSR&);
  // Move assignment
  MatrixCSR& operator=(MatrixCSR&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators, non si possono controllare i puntatori delle righe, si devono controllare i dati.
  bool operator==(const MatrixCSR&) const noexcept;
  bool operator!=(const MatrixCSR&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

  void RowResize(unsigned long) override;// Override Matrix member
  void ColumnResize(unsigned long) override; // Override Matrix member

  bool ExistsCell(const unsigned long, const unsigned long) const noexcept override; // Override Matrix member (should not throw exceptions)

  const Data& operator()(const unsigned long r, const unsigned long c) const override; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
  Data& operator()(const unsigned long r, const unsigned long c) override; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member, row = 0 column = 0

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)
  using typename MappableContainer<Data>::MapFunctor;
  void MapPreOrder(const MapFunctor, void*) override; // Override MappableContainer member
  void MapPostOrder(const MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)
  using typename MappableContainer<Data>::FoldFunctor;
  void FoldPreOrder(const FoldFunctor, const void*, void*) const override; // Override MappableContainer member
  void FoldPostOrder(const FoldFunctor,const void*, void*) const override; // Override MappableContainer member

};

/* ************************************************************************** */

}

#include "matrixcsr.cpp"

#endif
