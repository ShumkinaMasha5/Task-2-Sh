//Данное решение было написано при ручном вводе данных с клавитуры. Впоследствии я это изменю.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    double weight;
    double value;
    double price;
    double ub; //верхняя граница
};


double calculateUB(double v, double w, double W, const Item& nextItem) {
    return ((double) v) + ((double) (W - w)) * (nextItem.value / nextItem.weight);
}


bool compare(const Item& a, const Item& b) {
    return a.price > b.price; 
}

int main() {
    int N;
    double max_weight;
    cout << "Введите количество предметов: ";
    cin >> N;
    cout << "Введите максимальный вес рюкзака: ";
    cin >> max_weight;

    vector<Item> items(N);
    cout << "Введите пары (вес, ценность):" << endl;
    for (int i = 0; i < N; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    for (int i = 0; i < N; i++) {
        items[i].price = items[i].value/items[i].weight;
    }

    sort(items.begin(), items.end(), compare); //сортируем в порядке убывания
    
    double weight_now = 0;
    double value_now = 0;

    for(int i = 0; i < N - 1; i++) {
        if((calculateUB(value_now + items[i].value, weight_now + items[i].weight, max_weight, items[i + 1]) > calculateUB(value_now, weight_now, max_weight, items[i + 1])) && (weight_now + items[i].weight <= max_weight)) {
            value_now += items[i].value;
            weight_now += items[i].weight;
        }
    }
    
    cout << "Максимальная ценность: " << value_now << endl;
    cout << "Общий вес: " << weight_now << endl;
    return 0;
}


