/*
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
*/


#include "essentials.h"

class StockSpanner {
public:
  StockSpanner() : day_(0), index_(0) {
    prices_.reserve(10000);
  }

  int next(int price) {
    day_++;
    if (prices_.size() == 0 or prices_[0].second <= price) {
      AppendPrice(0, price);
      index_ = 0;
      return day_;
    }
    int i = index_;
    while (prices_[i].second <= price) {
      i--;
    }
    AppendPrice(i + 1, price);
    index_ = i + 1;
    return day_ - prices_[i].first;
  }

private:
  void AppendPrice(int index, int price) {
    if (index >= int(prices_.size())) {
      prices_.push_back({day_, price});
    } else {
      prices_[index] = {day_, price};
    }
  }

  std::vector<std::pair<int, int>> prices_;
  int day_;
  int index_;
};


int main() {
  auto sol = std::make_unique<StockSpanner>();
  assert(sol->next(100) == 1);
  assert(sol->next(80) == 1);
  assert(sol->next(60) == 1);
  assert(sol->next(70) == 2);
  assert(sol->next(60) == 1);
  assert(sol->next(75) == 4);
  assert(sol->next(85) == 6);
  assert(sol->next(75) == 1);
  assert(sol->next(85) == 8);
  assert(sol->next(85) == 9);
  assert(sol->next(75) == 1);
  assert(sol->next(90) == 11);
  assert(sol->next(100) == 13);
  assert(sol->next(105) == 14);
  assert(sol->next(100) == 1);
}


