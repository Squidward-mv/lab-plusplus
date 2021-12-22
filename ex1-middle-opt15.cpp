#include <iostream>
#include <string>

using namespace std;

class Employee{
public:
    
    string lastName;
    float salary;
    int yearOfHire;
    
    Employee(){
        this->lastName = " ";
        this->salary = 25500.75;
        this->yearOfHire = 2007;
    }
    
    Employee(string lastName, float salary, int yearOfHire){
        this->lastName = lastName;
        this->salary = salary;
        this->yearOfHire = yearOfHire;
    }
    
    void showInfo(){
        cout << "_____________________________________________________________________________";
        cout << "\nФамилия: " << this->lastName << "\nОклад: " << this->salary << "\nГод поступления на работу: " << this->yearOfHire << endl;
    }
    
    int experience(int currentYear){
        return currentYear - this->yearOfHire;
    }
    
    int daysOfExperience(int year, int month, int day){
        return ((year - this->yearOfHire)* 365) - ((12 - month) * 31 + 31 - day);
    }
    
    ~Employee(){
        cout << "\nThe object was successfully deleted!";
    }
};

int main(){

    Employee first = {"Иванов", 23100, 2009};
    
    first.showInfo();
    first.lastName = "Иванович";
    first.salary = 25800.30;
    first.showInfo();
    
    cout << "Стаж работы: " << first.experience(2021) << " года/лет" << endl;
    cout << "В днях: " << first.daysOfExperience(2021, 12, 10) << endl;

    return 0;
}
