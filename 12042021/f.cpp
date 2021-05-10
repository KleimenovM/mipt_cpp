#include <iostream>
using std::cout;
using std::endl;

struct Order {
    unsigned int part_id;
    double total_cost;
    char type; // 'c' -- cpu, 'g' -- gpu, 'm' -- motherboard, 'r' -- ram;
    int count;

};


void process_orders(const Order* all_orders, unsigned int old_n, Order** processed_orders, unsigned int* new_n){
    auto *orders = new Order [256];
    int orders_num = 0, order_len = 256;

    for (int i = 0; i < old_n; i++){
        if (all_orders[i].type == 'g')
            continue;

        for (int j = 0; j < all_orders[i].count; j++) {
            Order new_order{};
            new_order.part_id = all_orders[i].part_id;
            new_order.count = 1;
            new_order.type = all_orders[i].type;
            new_order.total_cost = all_orders[i].total_cost / all_orders[i].count;
            orders[orders_num] = new_order;
            orders_num++;
        }
    }

    auto *new_orders = new Order [orders_num];
    for (int i = 0; i < orders_num; i++)
        new_orders[i] = orders[i];

    *processed_orders = new_orders;
    *new_n = orders_num;
}

int main()
{
    Order orders[] = {
            {12270,  500.0, 'r', 4},
            {15644,  1220.0, 'g', 2},
            {2330,  700.0, 'c', 1},
    };

    Order* processed_orders = nullptr;
    unsigned int new_n = 0;
    process_orders(orders, 5, &processed_orders, &new_n);

    for (unsigned int i = 0; i < new_n; i++)
        cout << processed_orders[i].part_id  << " " << processed_orders[i].total_cost
             << " " <<  processed_orders[i].type << " " << processed_orders[i].count << endl;

// ожидаемый результат:
// 12270 125.0 r 1
// 12270 125.0 r 1
// 12270 125.0 r 1
// 12270 125.0 r 1
// 2330 700.0 c 1

    delete[] processed_orders;
    return 0;
}

