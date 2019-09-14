//
// Created by zhang on 9/7/19.
//

#include <iostream>

// class A: heap only
class A{
public:
    static A* create(){
        return new A();
    };

    void destroy(){
        delete(this);
    }

protected:
    A(){};
    virtual ~A(){};
};

class ADerived: public A{
public:
    static ADerived* create(){
        return new ADerived();
    }
};

// class B: stack only
class B{
public:
    B(){};
    ~B(){};
    void* operator new(size_t) = delete;
    void operator delete(void*) = delete;
};

int main(int argc, char** argv){
    A* a = A::create();
    a->destroy();
    ADerived* ad = ADerived::create();
    ad->destroy();
    B b;
    B* pb = &b;
}