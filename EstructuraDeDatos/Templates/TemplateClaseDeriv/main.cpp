// TemplateClaseDeriv
#include <iostream>
using namespace std;
class BaseA {
  public:
    BaseA() { cout << "BaseA"; }
};
class BaseB {
  public:
    BaseB() { cout << "BaseB"; }
};
template <typename T> class Derived : public T {
  public:
    Derived() { cout << "::Derived" << endl; }
};
int main() {
  Derived<BaseA> ob1;
  Derived<BaseB> ob2;
  return 1;
}

