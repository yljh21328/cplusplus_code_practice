#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

mutex gMutex;

class Singleton {
public:
    static Singleton* getInstance() {
        if (instance == NULL) {
            lock_guard<mutex> mLock(gMutex);
            if (instance == NULL) {
                instance = new Singleton();
            }
        }
        return instance;
    }
    void setTemp(int temp) {
        _temp = temp;
    }
    int getTemp() {
        return _temp;
    }

private:
    int _temp;
    static Singleton* volatile instance;
    Singleton(){}
};
//Initialize static member of class Singleton
//Eager initialization
//Singleton *Singleton::instance = Singleton::getInstance();
//Lazy initialization
Singleton* volatile Singleton::instance = NULL;

void testSingleton() {
    Singleton *instance = Singleton::getInstance();
    int addr = (int)instance;
    cout << addr << endl;
}

int main()
{
    // Multi-thread environment
    thread t1(testSingleton);
    thread t2(testSingleton);
    thread t3(testSingleton);
    thread t4(testSingleton);
    thread t5(testSingleton);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    bool test = true;
    if (test) {
        return 0;
    }

    // Single-thread environment
    Singleton *instance1 = Singleton::getInstance();
    Singleton *instance2 = Singleton::getInstance();
    int addr1 = (int)instance1;
    int addr2 = (int)instance2;
    instance1->setTemp(5);
    cout << instance1->getTemp() << endl;
    cout << instance2->getTemp() << endl;
    cout << addr1 << endl;
    cout << addr2 << endl;
    //instance1 = Singleton::getInstance();
    cout << addr1 << endl;
    cout << addr2 << endl;
    instance1->setTemp(10);
    cout << instance1->getTemp() << endl;
    cout << instance2->getTemp() << endl;
    return 0;
}
