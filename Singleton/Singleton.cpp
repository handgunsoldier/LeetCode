#include <iostream>

template <typename T>
class SingletonEager{
public:
    static SingletonEager* pSingletonEager;
    static SingletonEager* instance(){
        return pSingletonEager;
    }
    class GarbageCollector{
    public:
        ~GarbageCollector(){
            if(pSingletonEager!= nullptr){
                delete(pSingletonEager);
                pSingletonEager = nullptr;
            }
        }
    };
    static GarbageCollector gc;
    void display(){std::cout << data_ << std::endl;}
private:
    SingletonEager(){};
    ~SingletonEager(){};
    T data_ = static_cast<double>(-1.5);
};

template <typename T>
typename SingletonEager<T>::GarbageCollector SingletonEager<T>::gc =
        SingletonEager<T>::GarbageCollector();
template <typename T>
SingletonEager<T>* SingletonEager<T>::pSingletonEager = new SingletonEager();

template <typename T>
class SingletonLazy{
public:
    static SingletonLazy* pSingletonLazy;
    static SingletonLazy* instance(){
        if(pSingletonLazy== nullptr){
            pSingletonLazy = new SingletonLazy();
        }
        return pSingletonLazy;
    }
    class GarbageCollector{
    public:
        ~GarbageCollector(){
            if(pSingletonLazy!= nullptr){
                delete(pSingletonLazy);
                pSingletonLazy = nullptr;
            }
        }
    };
    static GarbageCollector gc;
    void display(){std::cout << data_ << std::endl;}
private:
    SingletonLazy(){};
    ~SingletonLazy(){};
    T data_ = static_cast<T>(0.5);
};

template <typename T>
typename SingletonLazy<T>::GarbageCollector SingletonLazy<T>::gc =
        SingletonLazy<T>::GarbageCollector();
template <typename T>
SingletonLazy<T>* SingletonLazy<T>::pSingletonLazy = nullptr;

int main(int argc, char** argv){
    auto p = SingletonEager<double>::instance();
    p->display();

    auto q = SingletonLazy<double>::instance();
    q->display();

    return -2;
}