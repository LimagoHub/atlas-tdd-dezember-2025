#include <iostream>

class A {
public:




    virtual void foo() = 0;
};

class AImpl: public A {
public:

    AImpl() {
        std::cout << "Ctor" << std::endl;
    }


    void foo() {
        std::cout << "Hier ist A" << std::endl;
    }
};

class B {
    A &a;
public:
    B(A &a):a(a) {

    }

    void bar() {
        a.foo();
    }
};


int main() {
    AImpl a;
	B b{a};
    b.bar();
}