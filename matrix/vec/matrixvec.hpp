
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
class MatrixVec : virtual public Matrix<Data>, virtual protected Vector<Data>
{

private:

  // ...

protected:

  using Matrix<Data>::row;
  using Matrix<Data>::column;


public:

  // Default constructor
  MatrixVec() = default; //Matrice vuota, ROW = 0, COLUMN = 0

  /* ************************************************************************ */

  // Specific constructors
  MatrixVec(unsigned long row, unsigned long column); // A matrix of some specified dimension

  /* ************************************************************************ */
  //Possibile utilizzare il vettore da qui a
    // Copy constructor
    MatrixVec(const MatrixVec&);

    // Move constructor
    MatrixVec(MatrixVec&&) noexcept;

    /* ************************************************************************ */

    // Destructor
    ~MatrixVec() = default;

    /* ************************************************************************ */

    // Copy assignment
    MatrixVec& operator=(const MatrixVec&);

    // Move assignment
    MatrixVec& operator=(MatrixVec&&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const MatrixVec&) const noexcept;
    bool operator!=(const MatrixVec&) const noexcept;

  // qui.
  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

  void RowResize(unsigned long) override; // Override Matrix member     //Resize del vettore
  void ColumnResize(unsigned long) override; // Override Matrix member  //Resize del vettore, attenzione dopo il resize, la matrice non contiene i dati nell'ordine giusto

  bool ExistsCell(unsigned long,unsigned long) noexcept override; // Override Matrix member (should not throw exceptions)


  const Data& operator()() const override; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
  Data& operator()() override; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
  // Già dati dal vettore, fare using senza override se estendiamo vector<Data>
    void Clear() override; // Override Container member // Chiamare prima Clear() e poi Resettare ROW e COLUMN = 0

    /* ************************************************************************ */

    // Specific member functions (inherited from MappableContainer)

    using Vector<Data>::MapPreOrder; // Override MappableContainer member
    using Vector<Data>::MapPostOrder; // Override MappableContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from FoldableContainer)

    using Vector<Data>::FoldPreOrder; // Override FoldableContainer member
    using Vector<Data>::FoldPostOrder; // Override FoldableContainer member
 // fino a qui.
};

/* ************************************************************************** */

}

#include "matrixvec.cpp"

#endif
