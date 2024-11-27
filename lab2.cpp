#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;

class TPerson {
public:
    virtual void Show() = 0;
    virtual ~TPerson() = default;
};

struct TItem {
    TPerson* person;
    TItem* next;
};

class TGroup : public TPerson {
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
            delete current->person;
            delete current;
            current = next;
        }
    }

    void Insert(TPerson* obj) {
        TItem* newItem = new TItem{obj, first};
        first = newItem;
    }

    void ForEach(void (*action)(TPerson*)) {
        TItem* current = first;
        while (current) {
            action(current->person);
            current = current->next;
        }
    }

    void Show() override {
        cout << "Group: " << name << "\n";
        TItem* current = first;
        while (current) {
            current->person->Show();
            current = current->next;
        }
    }
};

class Student : public TPerson {
protected:
    char name[50];
    int course;
public:
    Student(const char* studentName, int courseNumber) : course(courseNumber) {
        strncpy(name, studentName, 50);
    }

    virtual ~Student() {
        cout << "Destroying Student: " << name << endl;
    }

    void Show() override {
        cout << "Student: " << name << ", Course: " << course << endl;
    }

    int GetCourse() const {
        return course;
    }
};

class Course : public TGroup {
public:
    Course(const char* courseName) : TGroup(courseName) {}

    ~Course() override {
        cout << "Destroying Course: " << name << endl;
    }
};

void ShowStudentsInCourse(TPerson* person) {
    if (Student* student = dynamic_cast<Student*>(person)) {
        student->Show();
    }
}

int main(void) {
    Course course("Computer Science");

    course.Insert(new Student("Alice", 2));
    course.Insert(new Student("Bob", 1));
    course.Insert(new Student("Charlie", 2));
    course.Insert(new Student("David", 3));

    cout << "*** All students in the course ***" << endl;
    course.Show();

    cout << "\n*** List of all students in course 2 ***" << endl;
    course.ForEach([](TPerson* person) { 
        Student* student = dynamic_cast<Student*>(person);
        if (student && student->GetCourse() == 2) {
            student->Show();
        }
    });

    return 0;
}
