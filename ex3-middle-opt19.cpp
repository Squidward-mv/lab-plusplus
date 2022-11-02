#include <iostream>
#include <cmath>

using namespace std;

class Triangle{
public:
    
    float a, b, c;
    
    Triangle(){
        this->a = 0;
        this->b = 0;
        this->c = 0;
    }
    
    Triangle(float a, float b, float c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    
    virtual void showInfo(){
        cout << "\n\tИнформация о классе треугольник\n" << endl;
        cout << "A = " << this->a << "\nB = " << this->b << "\nC= " << this->c << "\nP = " << perimeter() << "\nS = " << area() << endl;
    }
    
    virtual float perimeter(){
        return this->a + this->b + this->c;
    }
    
    virtual float area(){
        return sqrt(perimeter() / 2 * ((perimeter() / 2) - a) * ((perimeter() / 2) - b) * ((perimeter() / 2) - c));
    }
};

class Quadrangle: public Triangle{
public:

    float d, e, f;
    
    Quadrangle(): Triangle(){
        this->d = 0;
        this->e = 0;
        this->f = 0;
    }
    
    Quadrangle(float a, float b, float c, float d, float e, float f){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->e = e;
        this->f = f;
    }

    void showInfo() override{
        cout << "\n\tИнформация о классе четырехугольник \n" << endl;
        cout << "A = " << this->a << "\nB = " << this->b << "\nC= " << this->c << "\nD = " << this->d << "\nE = " << this->e << "\nF = " << this->f << "\nP = " << perimeter() << "\nS = " << area() << endl;
    }
    
    float perimeter() override{
        return this->a + this->b + this->c + this->d;
    }
    
    float area() override{
        return sqrt((4*e*e*f*f - (b*b + d*d - a*a - c*c)*(b*b + d*d - a*a - c*c))/(16)); 
    }
};

int main(){
    
    Triangle first = {2, 2, sqrt(8)};
    first.showInfo();

    Quadrangle second = {2, 2, 2, 2, sqrt(8), sqrt(8)};
    second.showInfo();

    return 0;
}
