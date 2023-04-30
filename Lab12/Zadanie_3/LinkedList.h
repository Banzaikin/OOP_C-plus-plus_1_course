#pragma once
#include <iostream>
#include <set>
using namespace std;
template<typename T>
class MultiSet
{
private:
    int _size;
    multiset<T> ms;
public:
    MultiSet() { _size = ms.size(); } //конструктор
    void make_multiset(T value);              //метод добавлени¤ элементов
    void print_multiset();                   //метод вывода списка в консоль
    void arithmetic_mean();                //добавить в список элемент со средним арифмитическим значением
    void delete_elem();            //поиск и удаление данных в заданном диапазоне
    void sum_min_max();              //добавлениек каждому элементу максимального и минимального элементов
    int size() { return _size; }    //размер
};

template<typename T>
void MultiSet<T>::make_multiset(T value) {
    for (int i = 0; i < value; i++)
    {
        double a;
        cout << "\n¬ведите " << i + 1 << " элемент: ";
        cin >> a;
        ms.insert(a); //добавление a в конец контейнера множество дубликатами
    }
}

template<typename T>
void MultiSet<T>::print_multiset() {
    int n = 0;
    for (const auto& elem : ms) {
        cout << ++n << ". " << elem << endl;
    }
    cout << endl;
}

template<typename T>
inline void MultiSet<T>::arithmetic_mean()
{
    T midl = 0;
    for (auto& i : ms)
        midl = midl + i;
    ms.insert(midl / ms.size());
    ++_size;
}

template<typename T>
void MultiSet<T>::delete_elem()
{
    double start, finish;
    cout << "\n¬ведите с какого по какой элемент будем удал¤ть: ";
    cin >> start >> finish;
    auto left = ms.lower_bound(start);
    auto right = ms.upper_bound(finish);
    ms.erase(left, right);
    _size = ms.size();
}

template<typename T>
inline void MultiSet<T>::sum_min_max()
{
    multiset<T> temp;
    T min = *ms.begin(), max = *ms.begin();
    for (auto& i : ms)
    {
        if (i < min) 
            min = i;
        if (!(i < max)) 
            max = i;
    }
    for (auto& i : ms)
        temp.insert(i + min + max);
    ms.swap(temp);
}
