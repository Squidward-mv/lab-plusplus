#include <iostream>

using namespace std;

class MathClass{
public:
    
    int x;
    int y;
    
    MathClass(){
        this->x = 0;
        this->y = 0;
    }
    
    void showInfo(){
        cout << "x = " << this->x << " \ny = " << this->y << endl; 
    }
    
    int wholePart(){
        cout << endl;
        return this->x/this->y;
    }
};

class ChildOfMathClass: public MathClass{
public:

  float z;
  
  ChildOfMathClass() : MathClass(){
    this->z = 0;
  }
  
  void showInfo(){
    cout << "x = " << this->x << " \ny = " << this->y << "\nz = " << this->z << endl; 
  }
  
  float childMethod(){
    cout << endl;
    return this->x / this->z + this->y / this->z;
  }
  
};

int main(){

    MathClass first;
    first.x = 13;
    first.y = 3;
    cout << "Информация о классе родителе:" << endl;
    
    first.showInfo();
    cout << first.wholePart();

    ChildOfMathClass second;
    second.x = 19;
    second.y = 12;
    second.z = 2;
    cout << "\n\nИнформация о классе потомке:" << endl;
    
    second.showInfo();
    cout << second.childMethod();

    return 0;
}