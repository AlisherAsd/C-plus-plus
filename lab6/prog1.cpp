#include <iostream>
#include <list>
#include <deque>
#include <algorithm>

int main() {
    // 1) Создание и заполнение контейнера list
    std::list<long> listContainer = {1, 2, 3, 4, 5};

    // 2) Просмотр контейнера list
    std::cout << "Initial list container: ";
    for (long val : listContainer) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 3) Изменение контейнера list
    listContainer.remove(3); // Удаление элемента 3
    listContainer.push_back(6); // Добавление элемента 6

    // 4) Просмотр контейнера list с использованием итераторов
    std::cout << "Modified list container: ";
    for (auto it = listContainer.begin(); it != listContainer.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 5) Создание и заполнение контейнера list
    std::list<long> list2Container = {1, 2, 3, 4, 5};

    // 6) Изменение первого контейнера list, удаление n элементов после заданного и добавление всех элементов из deque
    auto it = listContainer.begin();
    std::advance(it, 2); // Перемещение на 2 элемента
    listContainer.erase(it, listContainer.end()); // Удаление элементов после второго
    listContainer.insert(listContainer.end(), list2Container.begin(), list2Container.end()); // Добавление элементов из deque

    // 7) Просмотр первого и второго контейнеров
    std::cout << "Final list container: ";
    for (long val : listContainer) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "List 2 container: ";
    for (long val : list2Container) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
