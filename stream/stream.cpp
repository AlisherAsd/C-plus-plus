#include <iostream>
#include <fstream>
  
class Person 
{
public:
    Person(std::string name, unsigned age): name{name}, age{age} {}
    std::string getName() const {return name;}
    unsigned getAge() const {return age;}
 
    void setName(std::string personName){ name = personName;}
    void setAge(unsigned personAge){ age = personAge;}
private:
    std::string name;
    unsigned age;
};


std::ostream& operator << (std::ostream &os, const Person &person)
{
    return os << person.getName() << " " << person.getAge();
}

std::istream& operator >> (std::istream& in, Person& person)
{
    std::string name;
    unsigned age;
    in >> name >> age;
    if (in) {
        person.setName(name);
        person.setAge(age);
    }
    return in;
}




int main()
{
    Person humans[4] = {Person("Tom", 23), Person("Roma", 30), Person("Alina", 45), Person("Egor", 14)}; 
    for (int i = 0; i < 4; i++) {
        std::cout << humans[i] << std::endl;
    }


    std::ofstream out("people.txt");

    if (out.is_open()) {
        for (int i = 0; i < 4; i++) {
            out << humans[i] << std::endl;
        }
    }

    out.close();

    std::ifstream in("people.txt");

    Person newHumans[4];
    Person person{"",0};
    for (int i = 0; i < 4; i++) {
        in >> person;
        newHumans[i] = person;
    }

    for (int i = 0; i < 4; i++) {
        std::cout << humans[i] << std::endl;
    }
}