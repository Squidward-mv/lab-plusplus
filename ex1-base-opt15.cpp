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
        return this->x/this->y;
    }
};

int main(){

    MathClass first;
    first.showInfo();
    first.x = 13;
    first.y = 3;
    first.showInfo();
    cout << first.wholePart();

    return 0;
}
