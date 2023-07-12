#include "main/test.h"
#include "main/test-diff.h"

void g() {
  S s;
  func(s); // NON_CAMPLIANT -s is no-standard and passed to a library function
}

void h() {
  StdS s;
  func(s); //COMPLIANT - StdS is standard layout and passed to a library
           // function
}
