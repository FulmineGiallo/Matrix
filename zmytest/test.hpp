
#ifndef ZMYTEST_HPP
#define ZMYTEST_HPP
#include "../vector/vector.hpp"
#include "../matrix/vec/matrixvec.hpp"
#include <iostream>
/* ************************************************************************** */
namespace lasd
{
  /* Oppure non passare row e column, ma usare i metodi rowNumber e columnNumber */
  template <typename Data>
  void riempi(lasd::MatrixVec<Data>& v, int row, int column);
  template <typename Data>
  void riempiStringa(lasd::MatrixVec<std::string>& v, int row, int column);
  void MenuUtente();
  void MenuCSR(int tipo, int row, int column);
  void MenuVector(int tipo, int row, int column);

}

/* ************************************************************************** */

#endif
