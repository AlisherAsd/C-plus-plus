#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <functional>
#include "person.cpp"

bool comp(const Person& a, const Person& b) {
    return a.getValue() > b.getValue();
}

bool condition(const Person& p) {
    return p.getValue() > 30.0;
}

int main() {
    // 1) Создание контейнера deque и заполнение его объектами

    // ----------DEQUE-------------
    std::deque<Person> dequeContainer = {
        Person(1, "Alice", 30.5),
        Person(2, "Bob", 25.3),
        Person(3, "Charlie", 35.7),
        Person(4, "David", 28.9),
        Person(5, "Eve", 22.1)
    };

    // 2) Сортировка контейнера по убыванию элементов
    std::sort(dequeContainer.begin(), dequeContainer.end(), comp);

    // 3) Просмотр контейнера
    std::cout << "Sorted deque container: " << std::endl;
    for (const auto& person : dequeContainer) {
        std::cout << person << std::endl;
    }

    // 4) Поиск элемента, удовлетворяющего заданному условию
    auto it = std::find_if(dequeContainer.begin(), dequeContainer.end(), condition);
    if (it != dequeContainer.end()) {
        std::cout << "Found person: " << *it << std::endl;
    } else {
        std::cout << "No person found with value > 30.0" << std::endl;
    }

    // ----------LIST----------------

    // 5) Перемещение элементов, удовлетворяющих заданному условию, в другой контейнер
    std::list<Person> anotherContainer;

    std::remove_copy_if(dequeContainer.begin(), dequeContainer.end(), std::back_inserter(anotherContainer), condition);

    // 6) Просмотр второго контейнера
    std::cout << "Another list container: " << std::endl;
    for (const auto& person : anotherContainer) {
        std::cout << person << std::endl;
    }

    // 7) Сортировка первого и второго контейнеров по возрастанию элементов
    std::sort(dequeContainer.begin(), dequeContainer.end());
    anotherContainer.sort();

    // 8) Просмотр контейнеров
    std::cout << "Sorted deque container: " << std::endl;
    for (const auto& person : dequeContainer) {
        std::cout << person << std::endl;
    }

    std::cout << "Sorted another list container: " << std::endl;
    for (const auto& person : anotherContainer) {
        std::cout << person << std::endl;
    }

    // ---------LIST + DEQUE == DEQUE ----------
    // 9) Слияние первых двух контейнеров в третий контейнер
    std::deque<Person> mergedContainer;
    std::merge(dequeContainer.begin(), dequeContainer.end(), anotherContainer.begin(), anotherContainer.end(), std::back_inserter(mergedContainer));


    // 10) Просмотр третьего контейнера
    std::cout << "Merged deque container: " << std::endl;
    for (const auto& person : mergedContainer) {
        std::cout << person << std::endl;
    }

    // 11) Подсчет количества элементов, удовлетворяющих заданному условию, в третьем контейнере
    int count = std::count_if(mergedContainer.begin(), mergedContainer.end(), condition);
    std::cout << "Number of persons with value > 30.0: " << count << std::endl;

    // 12) Определение, есть ли в третьем контейнере элемент, удовлетворяющий заданному условию
    if (std::any_of(mergedContainer.begin(), mergedContainer.end(), condition)) {
        std::cout << "There is a person with value > 30.0 in the merged container." << std::endl;
    } else {
        std::cout << "There is no person with value > 30.0 in the merged container." << std::endl;
    }

    return 0;
}
