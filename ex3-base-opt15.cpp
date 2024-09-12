#include <iostream>
#include <string>

using namespace std;

const int currentYear = 2021;

class Car{
public:
  
    string brand;
    float power;
    int numberOfSeats;
    
    Car(){
        this->brand = " ";
        this->power = 100.7;
        this->numberOfSeats = 4;
    }
    
    Car(string brand, float power, int numberOfSeats){
        this->brand = brand;
        this->power = power;
        this->numberOfSeats = numberOfSeats;
    }
    
    virtual void showInfo(){
        cout << "\nМарка: " << this->brand << "\nМощность двигателя(кВт): " << this->power << "\nКоличество мест: " << this->numberOfSeats << endl;
    }
    
    virtual float q(){
        return this->numberOfSeats * 0.1;
    }
};

class ChildOfCar: public Car{
public:
    
    int yearOfManufacture;
    
    ChildOfCar(): Car(){
        this->yearOfManufacture = 2002;
    }
    
    ChildOfCar(string brand, float power, int numberOfSeats, int yearOfManufacture){
        this->brand = brand;
        this->power = power;
        this->numberOfSeats = numberOfSeats;
        this->yearOfManufacture = yearOfManufacture;
    }
    
    void showInfo() override{
        cout << "\nМарка: " << this->brand << "\nМощность двигателя(кВт): " << this->power << "\nКоличество мест: " << this->numberOfSeats << "\nГод изготовления: " << yearOfManufacture << endl;
    }
    
    float q() override{
        return (0.1 * numberOfSeats) - 1.5 * (currentYear - yearOfManufacture);
    }
};

int main(){
    
    Car first = {"BMW", 234.4, 4};
    first.showInfo();
    cout << "Q = " << first.q() << endl;
    
    ChildOfCar second = {"Toyota", 251.7, 4, 2014};
    second.showInfo();
    cout << "Q = " << second.q() << endl;

    return 0;
}
