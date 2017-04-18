/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

/*
Solution using heap O(n lg n)

#include <vector>
using namespace std;

struct Node
{
	long long value;
	int last_factor;
	Node(long long x, int f) { value = x; last_factor = f; }
};

class Heap
{
public:
	Heap() { heap.clear(); }
	void add(Node x)
	{
		heap.push_back(x);
		int index = heap.size() - 1;
		while (index > 0)
		{
			int father = (index - 1) / 2;
			if (heap[father].value < heap[index].value) break;
			swap(heap[father], heap[index]);
			index = father;
		}
	}
	void deleteHead()
	{
		swap(heap[0], heap[heap.size() - 1]);
		heap.erase(heap.end() - 1);
		int index = 0;
		while (index <= ((int)heap.size() - 2) / 2)
		{
			int c1 = index * 2 + 1, c2 = index * 2 + 2;
			if (c2 < (int)heap.size() && heap[c1].value > heap[c2].value) c1 = c2;
			if (heap[c1].value > heap[index].value) break;
			swap(heap[c1], heap[index]);
			index = c1;
		}
	}
	Node getHead() { return heap[0]; }
private:
	vector<Node> heap;
};

class Solution {
public:
	int nthUglyNumber(int n) 
	{
		Heap heap;
		Node node(1, 2);
		heap.add(node);
		while (n > 1)
		{
			Node head = heap.getHead();
			heap.deleteHead();
			if (head.last_factor == 2)
			{
				Node node(head.value * 2, 2);
				heap.add(node);
			}
			if (head.last_factor < 5)
			{
				Node node(head.value * 3, 3);
				heap.add(node);
			}
			Node node(head.value * 5, 5);
			heap.add(node);
			n--;
		}
		return heap.getHead().value;
	}
};
*/


/*
Solution using 3 lists O(n)

#include <list>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n)
	{
		if (n == 1) return 1;
		list<long long> list2, list3, list5;
		list2.push_back(2); list3.push_back(3); list5.push_back(5);
		while (1)
		{
			n--;
			int f = 2;
			long long v = list2.front();
			if (list3.front() < v) { f = 3; v = list3.front(); }
			if (list5.front() < v) { f = 5; v = list5.front(); }
			if (n == 1) return v;
			switch (f)
			{
			case 2:
				list2.pop_front(); list2.push_back(v * 2); list3.push_back(v * 3); list5.push_back(v * 5); break;
			case 3:
				list3.pop_front(); list3.push_back(v * 3); list5.push_back(v * 5); break;
			case 5:
				list5.pop_front(); list5.push_back(v * 5); break;
			}
		}
	}
};
*/


/*
Solution using three pointers O(n)
*/
#include <vector>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n)
	{
		if (n == 1) return 1;
		vector<long long> ans;
		ans.push_back(1);
		int i = 0, j = 0, k = 0;
		while (1)
		{
			n--;
			long long v = ans[i] * 2;
			if (ans[j] * 3 < v) v = ans[j] * 3;
			if (ans[k] * 5 < v) v = ans[k] * 5;
			if (n == 1) return v;
			ans.push_back(v);
			if (v == ans[i] * 2) i++;
			if (v == ans[j] * 3) j++;
			if (v == ans[k] * 5) k++;
		}
	}
};