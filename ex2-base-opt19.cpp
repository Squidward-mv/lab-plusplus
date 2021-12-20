#include <iostream>

using namespace std;

class MathClass{
public:
    
    float x;
    float y;
    
    MathClass(){
        this->x = 0;
        this->y = 0;
    }
    
    void showInfo(){
        cout << "\nИнформация о родительском классе" << endl;
        cout << "\nx = " << this->x << " \ny = " << this->y << endl; 
    }
    
    float perimeter(){
        cout << "P = "; 
        
        return (this->x + this->y) * 2;
    }
};

class ChildOfMathClass : public MathClass{
public:
    float c;
    
    ChildOfMathClass() : MathClass(){
        this->c = 0;
    }
    
    void showInfo(){
        cout << "\nИнформация о классе потомке" << endl;
        cout << "\nx = " << this->x << " \ny = " << this->y << "\nc = " << this->c << endl; 
    }
    
    float childMethod(){
        return (x + c) * (y + c);
    }
};

int main(){

    MathClass first;
    first.x = 3.57;
    first.y = 3.11;
    first.showInfo();
    cout << first.perimeter();
    
    ChildOfMathClass second;
    second.x = 3.1415;
    second.y = 7.1;
    second.c = 1.4838;
    second.showInfo();
    cout << second.childMethod();

    return 0;
}