
#ifndef ZMYTEST_HPP
#define ZMYTEST_HPP
#include "../vector/vector.hpp"
#include <iostream>
/* ************************************************************************** */
namespace lasd
{
  void MenuUtente();
  void MenuCSR(int tipo, int row, int column);
  void MenuVector(int tipo, int row, int column);
  void riempi(MatrixVec<Data>& v, int row, int column);
  void riempiStringa(MatrixVec<Data>& v, int row, int column);
}

/* ************************************************************************** */

#endif
