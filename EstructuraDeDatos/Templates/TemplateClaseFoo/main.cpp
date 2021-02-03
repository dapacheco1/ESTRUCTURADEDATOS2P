// TemplateClaseFoo
// Version mejorada de funciones virtuales
#include <iostream>
using namespace std;
template <typename T> class Base {
  public:
    void foo() { cout << "foo in Base" << endl; }
    void callFoo() {
      T* tPtr = static_cast<T*>(this);
      tPtr->foo();
    }
};
class Derived : public Base<Derived> {
  public:
    void foo() { cout << "foo in Derived" << endl; }
};
int main() {
  Derived obj;
  obj.callFoo(); // -> foo in Derived
  return 0;
}
