#include <iostream>
#include <string>

using namespace std;

class Human{
public:
    
    string name;
    int age;
    
public:

    Human(){
        this->name = "Human";
        this->age = 20 + rand() % 21;    
    }

    virtual string greet(Human* human) = 0;
    virtual void tellAboutYourself() = 0;

    ~Human(){};
};

class Formalist : public Human {
public:

    Formalist(){
        this->name = name;
        this->age = age;
    }

    string greet(Human* human) override{
        cout << "Здравствуй, " << human->name << endl; 
        
        return human->name;
    }
    
    void tellAboutYourself() override{
        if((age % 10 >= 5) || (age % 10 == 0) || (age >= 10 && age <= 20)){
            cout << "\nМеня зовут " << name << ", мой возраст " << age << " лет, я формалист" << endl;
        }
        else{
            cout << "\nМеня зовут " << name << ", мой возраст " << age << " года, я формалист" << endl;
        }
    }
    
    ~Formalist(){};
};

class Informal : public Human {
public:

    string greet(Human* human) override{
        cout << "Привет, " << human->name << "!" << endl;
        
        return human->name;
    }
    
    void tellAboutYourself() override{
        if((age % 10 >= 5) || (age % 10 == 0) || (age >= 10 && age <= 20)){
            cout << "\nМеня зовут " << name << ", мой возраст " << age << " лет, я неформал" << endl;
        }
        else{
            cout << "\nМеня зовут " << name << ", мой возраст " << age << " года, я неформал" << endl;
        }
    }    
    
    ~Informal(){};
};

class Realist : public Human {
public:

    string greet(Human* human) override{
        if(abs(this->age - human->age) <= 5){
            cout << "Привет, " << human->name << "!" << endl;        
        }
        else{
            cout << "Здравствуй, " << human->name << endl; 
        }
        
        return human->name;
    }
    
    void tellAboutYourself() override{
        if((age % 10 >= 5) || (age % 10 == 0) || (age >= 10 && age <= 20)){
            cout << "\nМеня зовут " << name << ", мой возраст " << age << " лет, я реалист" << endl;
        }
        else{
            cout << "\nМеня зовут " << name << ", мой возраст " << age << " года, я реалист" << endl;
        }
    }
    
    ~Realist(){};
};

int main(){
    int size = 5;
    
    string names[10] = {"Александр", "Андрей", "Анастасия", "Ирина", "Наталья", "Павел", "Роман", "Светлана", "Сергей", "Татьяна"};
    
    Human **persons = new Human*[size];
    
    for(int i = 0; i < size; i++){
        int pQual = 1 + rand() % 3;
        cout << pQual << endl;
        switch(pQual){
            case 1:
                persons[i] = new Formalist;
                persons[i]->name = names[rand() % 10];
                persons[i]->age = 20 + rand() % 21;
                
            case 2:
                persons[i] = new Informal;
                persons[i]->name = names[rand() % 10];
                persons[i]->age = 20 + rand() % 21;
                
            case 3:
                persons[i] = new Realist;
                persons[i]->name = names[rand() % 10];
                persons[i]->age = 20 + rand() % 21;
        }
    }
    
    for(int i = 0; i < size; i++){
        cout << "Человек №:" << i + 1 << " Имя: " << persons[i]->name << "\n\t    Возраст: " << persons[i]->age << endl;
    
        persons[i]->tellAboutYourself();
    }

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++){
            cout << "\n" << persons[i]->name << ": ";
            persons[i]->greet(persons[j]);
            
            cout << "\n" << persons[j]->name << ": ";
            persons[j]->greet(persons[i]);
        }
    }
    
    return 0;
}