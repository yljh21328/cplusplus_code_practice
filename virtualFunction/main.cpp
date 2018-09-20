#include <iostream>

using namespace std;

class Foo1 {
public:
    virtual void show() {
        cout << "Foo1" << endl;
    }
};

class Foo2: public Foo1 {
    virtual void show() {
        cout << "Foo2" << endl;
    }
};
int main()
{
    Foo1 *fPtr;
    fPtr = new Foo1;
    fPtr->show();
    fPtr = new Foo2;
    fPtr->show();

    Foo1 f1;
    Foo2 f2;

    Foo1 &f1Ref = f1;
    f1Ref.show();
    Foo1 &f2Ref = f2;
    f2Ref.show();
    cout << "Hello world!" << endl;
    return 0;
}
