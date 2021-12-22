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
        cout << "\nx = " << this->x << " \ny = " << this->y << endl; 
    }
    
    float perimeter(){
        cout << "P = "; 
        
        return (this->x + this->y) * 2;
    }
};

int main(){

    MathClass first;
    first.showInfo();
    first.x = 3.57;
    first.y = 3.11;
    first.showInfo();
    cout << first.perimeter();

    return 0;
}
