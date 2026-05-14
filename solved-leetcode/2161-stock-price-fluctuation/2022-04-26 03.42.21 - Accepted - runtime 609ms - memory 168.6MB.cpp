#include <map>
#include <set>
using namespace std;

class StockPrice {
public:
    StockPrice() {}

    void update(int timestamp, int price) {
        if (stock.find(timestamp) != stock.end()) {
            prices.erase(prices.find(stock[timestamp]));
        }

        stock[timestamp] = price;
        prices.insert(price);

        last_ts = max(last_ts, timestamp);
    }

    int current() { return stock[last_ts]; }

    int maximum() { return *prices.rbegin(); }

    int minimum() { return *prices.begin(); }

    map<int, int> stock;
    multiset<int> prices;
    int last_ts = 0;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */