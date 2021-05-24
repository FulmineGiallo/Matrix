
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"
#include "vector/vector.hpp"
#include "matrix/vec/matrixvec.hpp"
/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2020" << std::endl;
  lasdtest();
  // lasd::MatrixVec<int> mat(1,1);
  // int r = 3;
  // int c = 3;
  // mat.RowResize(r);
  // mat.ColumnResize(c);
  // int a = 1;
  // for(unsigned long i = 0; i < r; i++){
  //   for(unsigned long j = 0; j < c; j++){
  //     mat(i,j) = a++;
  //     std::cout << mat(i,j) << "  ";
  //   }
  //   std::cout << '\n';
  // }
  // c = 4;
  // mat.ColumnResize(c);
  //
  // for(unsigned long i = 0; i < r; i++){
  //   for(unsigned long j = 0; j < c; j++){
  //     std::cout << mat(i,j) << "  ";
  //   }
  //   std::cout << '\n';
  // }
  //
  // std::cout << "Column " << mat.ColumnNumber();
  return 0;
}
