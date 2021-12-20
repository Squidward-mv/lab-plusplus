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
    }
    
    Vector(float x1, float x2, float y1, float y2){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    
    void showInfo(){
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

int main(){

    Vector first = {-2,0,3,0};
    
    first.showInfo();
    first.doubleLength();
    first.x2 = -1;
    first.x1 = -3;
    first.showInfo();
    cout << "S = " << first.triangleArea() << endl;

    return 0;
}
