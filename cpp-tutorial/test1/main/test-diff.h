struct S {
  virtual void f() {}
};

void func(S &s); // to be implemented by the library, calls S::f()
