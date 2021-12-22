#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    
    string name;
    float maxSpeed;

public:

    Car(){
        name = "Car";
        maxSpeed = 230.5;
    }
    
    virtual void price(){
        cout  << "\nPrice - " << maxSpeed * 100 << endl;
    }
    
    virtual void updateModel(){
        maxSpeed += 10;
    }
    
    void info(){
        cout << "\nName - " << name << "\nMax speed (km/h) - " << maxSpeed;
        price();
    }
};

class ExecutiveCar : public Car {
public:
    ExecutiveCar(){
      name = "Executive Car"; 
    }
    
    void price() override{
        cout  << "\nPrice - " << maxSpeed * 250 << endl;
    }
    
    void updateModel() override{
        maxSpeed += 5;
    }
};

int main(){
    
    Car bmw;
    bmw.name = "BMW";
    bmw.maxSpeed = 140;
    
    ExecutiveCar bentley;
    bentley.name = "Bentley";
    bentley.maxSpeed = 160;
    
    bmw.info();
    bentley.info();
    
    bmw.updateModel();
    bentley.updateModel();
    
    bmw.info();
    bentley.info();
    
    return 0;
}
