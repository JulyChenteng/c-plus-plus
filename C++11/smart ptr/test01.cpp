#include <iostream>
#include <memory>

#include "shape.h"
using namespace std;

int main() {
  unique_ptr<shape> ptr1{create_shape(shape_type::circle)};
  unique_ptr<shape> ptr2(ptr1);
  return 0;
}