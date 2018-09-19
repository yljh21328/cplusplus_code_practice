#include <iostream>
#include <string>

using namespace std;

class Ball {
public:
    Ball() {
        _radius = 0.0;
        _name = "noname ball";
    }

    Ball(double radius, const char* name) {
        _radius = radius;
        _name = name;
    }

    Ball(double radius, string& name) {
        _radius = radius;
        _name = name;
    }

    double radius() {
        return _radius;
    }
    string& name() {
        return _name;
    }

    void radius(double radius) {
        _radius = radius;
    }

    void name(const char* name) {
        _name = name;
    }
    void name(string& name) {
        _name = name;
    }

    double volumn() {
        return (4/3*3.14159 * _radius * _radius * _radius);
    }
private:
    double _radius;
    string _name;
};
int main()
{
    Ball ball1;
    cout << ball1.name() << "\t" << ball1.volumn() << endl;

    ball1.name("green ball");
    ball1.radius(2.5);
    cout << ball1.name() << "\t" << ball1.volumn() << endl;

    Ball ball2(5.0, "black ball");
    cout << ball2.name() << "\t" << ball2.volumn() << endl;

    string name("yellow ball");
    Ball ball3(10.0, name);
    cout << ball3.name() << "\t" << ball3.volumn() << endl;
    cout << "Hello world!" << endl;
    return 0;
}
