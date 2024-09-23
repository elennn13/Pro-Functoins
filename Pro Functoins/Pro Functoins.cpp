#include <iostream>
#include <functional> // подключение библиотеки содержащей в себе шаблонный класс std::functional, являющийся полиморфной оболочкой для любых функций
#include <vector>
#include <string>
#include "Array.hpp"

void foo() { std::cout << "foo()\n"; }
void poo() { std::cout << "poo()\n"; }
double sum(double num1, double num2) {
    return num1 + num2;
}
double multiply(double num1, double num2) {
    return num1 * num2;
}
double divide(double num1, double num2) {
    return num1 / num2;
}
double sumAB(double A, double B) {
    if (A > B) std::swap(A, B);
    double result = 0.;
    for (double i = A; i <= B; ++i)
        result += i;
    return result;
}
void do_every(std::vector<std::function<double(double, double)>>funcs, double num1, double num2) {
    for (size_t i{}; i < funcs.size(); ++i)
        std::cout << i + 1 << ". " << funcs[i](num1, num2) << std::endl;

}


int main() {
    setlocale(LC_ALL, "ru");
    int n;


    // Класс std::function
    /*
    std::function<void()> f1; // функция которая ничего не принимает и ничего не возвращает
    f1 = foo;
    f1();
    f1 = poo;
    f1();

    std::function<double(double, double)> f2;
    f2 = sum;   
    std::cout << "1 вызов. f2(5,2) = " << f2(5, 2) << std::endl;
    f2 = multiply;
    std::cout << "2 вызов. f2(5,2) = " << f2(5, 2) << std::endl;
*/
    
    // Массив функций
    /*
    do_every({ sum, multiply, divide, sumAB }, 10, 2);
*/

    // Лямбда - функции / Лямбда - выражение / Анонимные(безымянные) функции
    /*
    std::function<void(std::string)> f3(
        [](std::string name) {
        std::cout << "Hi, " << name << "!\n";
        }
    );

    f3("Tom");

    n = 2;
    std::function<bool(double)> f4(
        [&n](double num) {

            return num > n;
        }
    );

    if (f4(1))
        std::cout << "More then n\n"; 
    else
        std::cout << "Not More then n\n"; 

*/


    // Callback -функции
    Array<int> arr{ 10,7,5,6,1,0,14 };
    std::cout << arr << std::endl;

    std::cout << arr.every([](const int& el) {
        if (el % 2 == 0) // сумма только четных элементов
        return el;
        return 0;
        }) << std::endl;









     arr.for_each([](int& el) { // каждый элемент обнуляется ил иувеличивается в зависимости от числа:)//функция обработчик
        el = 0; // el *= 2;
        });
    std::cout << arr << std::endl;

    Array<int> filtered_arr = arr.filter([](const int& el) {  // отфильтрованный массив копия// от -5 до 5//только четные элменты
        return el > 5 || el < -5; // el % 2 == 0;
        });

    std::cout << filtered_arr << std::endl;




    return 0;
}
