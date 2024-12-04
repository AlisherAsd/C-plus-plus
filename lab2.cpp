#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;

class TObject {
public:
    virtual void Show() = 0;
    virtual ~TObject() {}
};
class Person : public TObject {
protected:
    std::string name;
    int sex; // 1 - man, 0 - women
public:
    Person(const std::string& name, int sex) : name(name), sex(sex){}

    ~Person() {
        cout << "Destroying Person: " << name << endl;
    }
    int getSex(){
        return sex;   
    }

    virtual void Show() override {
        if (sex == 0) cout << "Person: " << name << " sex: woman" << endl;
        else cout << "Person: " << name << " sex: man" << endl;
    }
};

class Employee : public Person {
public:
    Employee(const std::string& name, int sex) : Person(name, sex) {}

    void Show() override {
        if (sex == 0) cout << "Employee: " << name << " sex: woman" << endl;
        else cout << "Employee: " << name << " sex: man" << endl;
    }
    ~Employee() {
        cout << "Destroying Employee: " << name << endl;
}

};

class Worker : public Employee {
public:
    Worker(const std::string& name, int sex) : Employee(name, sex) {}

    void Show() override {
        if (sex == 0) cout << "Worker: " << name << " sex: woman" << endl;
        else cout << "Worker: " << name << " sex: man" << endl;
    }
    ~Worker() {
    cout << "Destroying Worker: " << name << endl;
}

};

class Engineer : public Employee {
public:
    Engineer(const std::string& name, int sex) : Employee(name, sex) {}
    void Show() override {
        if (sex == 0) cout << "Engineer: " << name << " sex: woman" << endl;
        else cout << "Engineer: " << name << " sex: man" << endl;
    }
    ~Engineer() {
    std::cout << "Destroying Engineer: " << name << std::endl;
}
};

struct TItem {
    Person* item;
    TItem* next;
};

class TGroup : public TObject {
protected:
    char name[50];
    TItem* first;
public:
    TGroup(const char* groupName) : first(nullptr) {
        strncpy(name, groupName, 50);
    }

    virtual ~TGroup() {
        TItem* current = first;
        while (current) {
            TItem* next = current->next;
            delete current->item;
            delete current;
            current = next;
        }
    }

    void Insert(Person* person) {
        TItem* newItem = new TItem{person, first};
        first = newItem;
    }
    

    void ForEach(void (*action)(Person*)) {
        TItem* current = first;
        while (current) {
            action(current->item);
            current = current->next;
        }
    }

    void Show() override {
        cout << "Group: " << name << "\n";
        TItem* current = first;
        while (current) {
            current->item->Show();
            current = current->next;
        }
    }
};




class Group : public TGroup {
public:
    Group(const char* enclosureName) : TGroup(enclosureName) {}

    ~Group() override {
        cout << "Destroying Group: " << name << endl;
    }
};

void chooseMen(Person* person) {
    if (person->getSex()) {
        person->Show();
    }
}

int main(void) {
    Group enclosure("Safari Group");

    enclosure.Insert(new Employee("ksenya", 1));
    enclosure.Insert(new Worker("masha", 1));
    enclosure.Insert(new Worker("sergey", 0));
    enclosure.Insert(new Worker("igor", 0));
    enclosure.Insert(new Worker("semen", 0));

    cout << "*** All people in the group ***" << endl;
    enclosure.Show();

    cout << "\n*** List of all man ***" << endl;
    enclosure.ForEach(chooseMen);

    return 0;
}
