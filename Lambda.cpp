/* 
1)
Создайте структуру Student, которая будет хранить имя и баллы студента. 
Создайте массив студентов и используйте std::max_element() для поиска студента с наибольшими баллами, 
а затем выведете на экран имя найденного студента. 
Функция std::max_element() принимает begin и end списка и функцию с двумя параметрами, 
которая возвращает true, если первый аргумент меньше второго.
2)
Используйте std::sort() и лямбду в следующем коде для сортировки времён года по возрастанию средней температуры.
*/

#include <iostream>
#include <string_view>
#include <array>
#include <algorithm>

struct Student
{
    std::string_view Name{};
    unsigned short scores;
};

struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

int main()
{
    // PART 1:
    std::array<Student, 8> arr{{ 
        { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan имеет больше всего баллов (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } 
        } };

    // лямбда:
    auto bigger_scores{
        [](const Student& student1, const Student& student2)
        {return (student1.scores < student2.scores); }
        };
    std::cout << "1) The best student is: " << (std::max_element(arr.begin(), arr.end(), bigger_scores))->Name << std::endl;

    // PART 2:
    std::array<Season, 4> seasons{
    { { "Spring", 285.0 },
      { "Summer", 296.0 },
      { "Fall", 288.0 },
      { "Winter", 263.0 } }
    };

    std::sort(seasons.begin(), seasons.end(), [](const Season& s1, const Season& s2)
        {return (s1.averageTemperature < s2.averageTemperature); });

    std::cout << "2) ";
    for (const auto& season : seasons)
    {
        std::cout << season.name << " ";
    }
    std::cout << '\n';

    return 0;
}