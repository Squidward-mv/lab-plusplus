#include <iostream>

using namespace std;

class MathClass{
public:

    float a, b;

    MathClass(){
        this->a = 0;
        this->b = 0;
    }

    void showInfo(){
        cout << "\na = " << this->a << "\nb = " << this->b << endl;
    }    
    
    float difference(){
        return (a*a - b*b);
    }
    
};

int main(){
    
    MathClass first;
    first.showInfo();
    
    first.a = 10;
    first.b = 5;
    first.showInfo();
    
    cout << "\nРазность квадратов = " << first.difference();

    return 0;
}
