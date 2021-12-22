#include <iostream>
#include <string>

using namespace std;

const int size = 7;

class Human{
public:
    
    string name;
    int age, trainingExperience;
    
    Human(){
        this->name = "Human";
        this->age = 0;
        this->trainingExperience = 0;
    }
    
    virtual void showInfo() = 0;
    virtual bool shoot() = 0;
};

class Begginer: public Human{
public:

    void showInfo() override{
        cout << "\n\tИнформация о стрелке" << endl;
        cout << "\nИмя: " << this->name << "\nВозраст: " << this->age << "\nОпыт в стрельбе: " << this->trainingExperience << "\nЗвание: новичок" << endl;
    }

    bool shoot() override{
        if ((rand() % 100) < 0.01 * trainingExperience * 100){
            return 1;
        }
        else{
            return 0;
        }
    }
};

class Experienced: public Human{
public:

    void showInfo() override{
        cout << "\n\tИнформация о стрелке" << endl;
        cout << "\nИмя: " << this->name << "\nВозраст: " << this->age << "\nОпыт в стрельбе: " << this->trainingExperience << "\nЗвание: опытный" << endl;
    }

    bool shoot() override{
        if ((rand() % 100) < 0.05 * trainingExperience * 100){
            return 1;
        }
        else{
            return 0;
        }
    }
};

class Veteran: public Human{
public:

    void showInfo() override{
        cout << "\n\tИнформация о стрелке" << endl;
        cout << "\nИмя:" << this->name << "\nВозраст: " << this->age << "\nОпыт в стрельбе: " << this->trainingExperience << "\nЗвание: Ветеран" << endl;
    }

    bool shoot() override{
        if ((rand() % 100) < (0.9 - 0.01 * age) * 10){
            return 1;
        }
        else{
            return 0;
        }
    }
};

int main(){
    Human **persons = new Human*[size];
    persons[0] = new Begginer;
    persons[1] = new Experienced;
    persons[2] = new Veteran;
    persons[3] = new Experienced;
    persons[4] = new Begginer;
    persons[5] = new Veteran;
    persons[6] = new Begginer;
    
    for(int i = 0; i < size; i++){
        cout << "\nВведите имя " << i + 1 << " го человека:" << endl;
        cin >> persons[i]->name;
        
        cout << "\nВведите возраст " << i + 1 << " го человека:" << endl;
        cin >> persons[i]->age;
        
        cout << "\nВведите опыт в стрельбе" << i + 1 << " го человека:" << endl;
        cin >> persons[i]->trainingExperience;
    }
    
    for(int i = 0; i < size; i++){
        persons[i]->showInfo();
        
        if(persons[i]->shoot()){
            cout << "____________________________________________" << endl;
            cout << "Стрелок под номером " << i + 1 << " попал!" << endl;
            cout << "\n\tСтрельба окончена!";
            break;
        }
        if((i == 6) && !(persons[i]->shoot())){
            cout << "____________________________________________" << endl;
            cout << "Последний стрелок не попал!" << endl;
            cout << "\n\tСтрельба окончена!";
            break;
        }
        else{
            cout << "____________________________________________" << endl;
            cout << "Стрелок под номером " << i + 1 << " не попал!" << endl;
            cout << "стрельба продолжается!";
        }
    }
    
    return 0;
}
