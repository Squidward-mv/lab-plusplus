#include <iostream>
#include <string>

using namespace std;

class Vector{
public:
    
    float x1, x2, y1, y2;
    
    Vector(){
        this->x1 = 0;
        this->x2 = 0;
        this->y1 = 0;
        this->y2 = 0;
        
        showInfo();
    }
    
    Vector(float x1, float x2, float y1, float y2){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        
        showInfo();
    }
    
    void showInfo(){
        cout << "\n\tДанные класса родителя" << endl;
        cout << "\n Координата x1: " << this->x1 << "\n Координата x2: " << this->x2 << "\n Координата y1: " << this->y1 << "\n Координата y2: " << this->y2 << endl;
    }
    
    void doubleLength(){
        cout << "\n Координаты вектора удвоенный длинны"; 
        cout << "\n Координата x1: " << this->x1 << "\n Координата x2: " << this->x2 + (this->x2 - this->x1);
        cout << "\n Координата y1: " << this->y1 << "\n Координата y2: " << this->y2 + (this->y2 - this->y1) << endl;
    }
    
    float triangleArea(){
        return abs(this->x1 - this->x2) * abs(this->y1 - this->y2) / 2;
    }
    
    ~Vector(){
        cout << "\nОбъект успешно удален!";
    }
};

class childOfVector : public Vector{
public:
    
    float a, b, cx1, cx2, cy1, cy2;
    
    childOfVector() : Vector(){
        this->a = 0;
        this->b = 0;
        this->cx1 = 0;
        this->cx2 = 0;
        this->cy1 = 0;
        this->cy2 = 0;
        
        showInfo();
    }
    
    childOfVector(float x1, float x2, float y1, float y2, float a, float b){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        this->cx1 = x1 + a;
        this->cx2 = x2 + a;
        this->cy1 = y1 - b;
        this->cy2 = y2 - b;
        this->a = a;
        this->b = b;
        
        showInfo();
    }
    
    void showInfo(){
        cout << "\n\tДанные класса потомка" << endl;
        cout << "\n Координата x1: " << this->x1 << "\n Координата x2: " << this->x2 << "\n Координата y1: " << this->y1 << "\n Координата y2: " << this->y2 << endl;
        cout << " Координата x1 второго вектора: " << this->cx1 << "\n Координата x2 второго вектора: " << this->cx2 << "\n Координата y1 второго вектора: " << this->cy1 << "\n Координата y2 второго вектора: " << this->cy2 << endl;
        cout << " Смещение вправо(a) = " << this->a << "\n Смещение вниз(b) = " << this->b << endl;
    }
    
    float parallelogramArea(){
        float c1 = abs(this->y1 - this->cy1);
        float c2 = abs(this->y1 - this->y2);
        float d1 = abs(this->x1 - this->cx1);
        float d2 = abs(this->x1 - this->x2);
        return c1*d1 + c2*d2;
    }
    
};

int main(){

    Vector first = {-2,0,3,0};
    
    first.doubleLength();
    first.x2 = -1;
    first.x1 = -3;

    childOfVector second = {0,2,0,2,0,2};
    cout << "S = " << second.parallelogramArea();

    return 0;
}