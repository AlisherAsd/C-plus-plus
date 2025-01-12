#include <iostream>
#include <list>
#include <deque>
#include <fstream>
#include <algorithm>
#include "person.cpp"

int main() {
    // 1) Создание и заполнение контейнера list
    std::list<Person> listContainer;
    listContainer.push_back(Person(1, "Alice", 30.5));
    listContainer.push_back(Person(2, "Bob", 25.3));
    listContainer.push_back(Person(3, "Charlie", 35.7));

    // 2) Просмотр контейнера list
    std::cout << "Initial list container: " << std::endl;
    for (const auto& person : listContainer) {
        std::cout << person << std::endl;
    }

    // 3) Изменение контейнера list
    listContainer.remove(Person(2, "Bob", 25.3)); // Удаление элемента Bob
    listContainer.push_back(Person(4, "David", 28.9)); // Добавление элемента David

    // 4) Просмотр контейнера list с использованием итераторов
    std::cout << "Modified list container: " << std::endl;
    for (auto it = listContainer.begin(); it != listContainer.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // 5) Создание и заполнение контейнера 2
    std::list<Person> list2Container;
    list2Container.push_back(Person(5, "Eve2", 22.1));
    list2Container.push_back(Person(6, "Frank2", 29.4));

    // 6) Изменение первого контейнера list, удаление n элементов после заданного и добавление всех элементов из deque
    auto it = listContainer.begin();
    std::advance(it, 1); // Перемещение на 1 элемент
    listContainer.erase(it, listContainer.end()); // Удаление элементов после первого
    listContainer.insert(listContainer.end(), list2Container.begin(), list2Container.end()); // Добавление элементов из deque

    // 7) Просмотр первого и второго контейнеров
    std::cout << "Final list container: " << std::endl;
    for (const auto& person : listContainer) {
        std::cout << person << std::endl;
    }

    std::cout << "List 2 container: " << std::endl;
    for (const auto& person : list2Container) {
        std::cout << person << std::endl;
    }

    return 0;
}
