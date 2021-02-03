// PrbTemplateClaseDeriv
#include "CBaseA.h"
#include "CBaseB.h"

template <typename T> class Derived : public T {
  public:
    Derived() { cout << "::Derived" << endl; }
};
int main() {
    Derived<CBaseA> ob1;
    Derived<CBaseB> ob2;
    return 0;
}
