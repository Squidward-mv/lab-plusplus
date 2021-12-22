#include <iostream>
#include <string>

using namespace std;

class Tv{
public:

    string brand;
    float diagonal;
    float soundPower;
    
    Tv(){
        this->brand = "LG";
        this->diagonal = 12.2;
        this->soundPower = 28.4;
    }
    
    Tv(string brand, float diagonal, float soundPower){
        this->brand = brand;
        this->diagonal = diagonal;
        this->soundPower = soundPower;
    }
    
    virtual void showInfo(){
        cout << "Марка: " << this->brand << "\nДиагональ экрана(в дюймах): " << this->diagonal << "\nЗвуковая мощность: " << this->soundPower << endl;
    }
    
    virtual float q(){
        return this->diagonal + (0.5 * soundPower);
    }
};

class childOfTv: public Tv{
public: 

    string country;
    
    childOfTv() : Tv(){
        this-> country = "Россия";
    }
    
    childOfTv(string brand, float diagonal, float soundPower, string country){
        this->brand = brand;
        this->diagonal = diagonal;
        this->soundPower = soundPower;
        this->country = country;
    }
    
    void showInfo() override{
        cout << "Марка: " << this->brand << "\nДиагональ экрана(в дюймах): " << this->diagonal << "\nЗвуковая мощность: " << this->soundPower << "\nСтрана производитель: " << this->country << endl;
    }
    
    float q() override{
        if(this->country == "Япония"){
            return 2 * (this->diagonal + (0.5 * soundPower));
        }
        else if((this->country == "Сингапур") || (this->country == "Корея")){
            return 1.5 * (this->diagonal + (0.5 * soundPower));
        }
        else{
            return this->diagonal + (0.5 * soundPower);
        }
    }
};

int main(){
    
    Tv lx_3001 = {"Samsung", 14.1, 20.1};
    lx_3001.showInfo();
    cout << "Q = " << lx_3001.q() << endl;

    childOfTv mvc_1781 = {"Sony", 18.2, 38.9, "Япония"};
    mvc_1781.showInfo();
    cout << "Q = " << mvc_1781.q() << endl;

    return 0;
}
