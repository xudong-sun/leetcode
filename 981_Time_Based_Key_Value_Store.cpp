/*
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".


Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"


Constraints:

1 <= key.length, value.length <= 100
key and value consist of lowercase English letters and digits.
1 <= timestamp <= 107
All the timestamps timestamp of set are strictly increasing.
At most 2 * 105 calls will be made to set and get.
*/


#include "essentials.h"

/*
class TimeMap {
public:
  void set(std::string key, std::string value, int timestamp) {
    kv[key][timestamp] = value;
  }

  std::string get(std::string key, int timestamp) const {
    const auto& it = kv.find(key);
    if (it == kv.end()) return "";
    const auto& values = it->second;
    auto it2 = values.upper_bound(timestamp);
    if (it2 == values.begin()) return "";
    else if (it2 == values.end()) return values.rbegin()->second;
    else return (--it2)->second;
  }
private:
  std::unordered_map<std::string, std::map<int, std::string>> kv;
};
*/

// directly implement the binary search
class TimeMap {
public:
  void set(std::string key, std::string value, int timestamp) {
    kv[key].push_back({timestamp, value});
  }

  std::string get(std::string key, int timestamp) const {
    const auto& it = kv.find(key);
    if (it == kv.end()) return "";
    const auto& values = it->second;
    if (timestamp < values[0].first) return "";
    int l = 0, r = values.size();
    while (l < r - 1) {
      int m = (l + r) / 2;
      if (timestamp < values[m].first) r = m;
      else l = m;
    }
    return values[l].second;
  }

private:
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> kv;
};

int main() {
  TimeMap timeMap;
  timeMap.set("foo", "bar", 1);
  commons::print(timeMap.get("foo", 1));  // bar
  commons::print(timeMap.get("foo", 3));  // bar
  timeMap.set("foo", "bar2", 4);
  commons::print(timeMap.get("foo", 4));  // bar2
  commons::print(timeMap.get("foo", 5));  // bar2
  commons::print(timeMap.get("foo", 0));  // ""
}


