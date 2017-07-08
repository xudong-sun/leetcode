/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

#include "essentials.h"

class Solution {
public:
	std::string numberToWords(int num) {
		if (num >= 1000000000) {
			if (num % 1000000000 == 0) return numberToWords(num / 1000000000) + " Billion";
			else return numberToWords(num / 1000000000) + " Billion " + numberToWords(num % 1000000000);
		}
		if (num >= 1000000) {
			if (num % 1000000 == 0) return numberToWords(num / 1000000) + " Million";
			else return numberToWords(num / 1000000) + " Million " + numberToWords(num % 1000000);
		}
		if (num >= 1000) {
			if (num % 1000 == 0) return numberToWords(num / 1000) + " Thousand";
			else return numberToWords(num / 1000) + " Thousand " + numberToWords(num % 1000);
		}
		if (num >= 100) {
			if (num % 100 == 0) return numberToWords(num / 100) + " Hundred";
			else return numberToWords(num / 100) + " Hundred " + numberToWords(num % 100);
		}
		if (num >= 20) {
			if (num % 10 == 0) return tens[num / 10 - 2];
			else return tens[num / 10 - 2] + ' ' + lessThanTwenty[num % 10];
		}
		else return lessThanTwenty[num];
	}
private:
	const static std::array<std::string, 20> lessThanTwenty;
	const static std::array<std::string, 8> tens;
};
const std::array<std::string, 20> Solution::lessThanTwenty = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
const std::array<std::string, 8> Solution::tens = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

int main() {
	auto sol = std::make_unique<Solution>();
	assert(sol->numberToWords(123) == "One Hundred Twenty Three");
	assert(sol->numberToWords(12345) == "Twelve Thousand Three Hundred Forty Five");
	assert(sol->numberToWords(1234567) == "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven");
	assert(sol->numberToWords(1234567890) == "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety");
	assert(sol->numberToWords(1000000001) == "One Billion One");
	assert(sol->numberToWords(1000000000) == "One Billion");
	assert(sol->numberToWords(100200) == "One Hundred Thousand Two Hundred");
}