#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void partition(vector<string>& sort, int begin, int end, int& location) {
	int left = begin;
	int right = end;
	 location = begin;
	bool flag = 0;
	while (!flag) {
		while (sort[location] <= sort[right] && location != right) {
			right = right - 1;
		}
		if (location == right) {
			flag = 1;
		}
		else if (sort[location] > sort[right]) {
			swap(sort[location], sort[right]);
			location = right;
		}
		if (!flag) {
			while (sort[location] >= sort[left] && location != left) {
				left += 1;
			}
			if (location == left) {
				flag = 1;
			}
			else if (sort[location] < sort[left]) {
				swap(sort[location], sort[left]);
				location = left;
			}
		}
	}
}

void show(vector<string> sort) {
	for (int i = 0; i < sort.size(); i++)
	{
		cout << sort[i] << " ";
	}
}

void quicksort(vector<string>& sort, int begin, int end) {
	int location = 0;
	if (begin < end) {
		
		partition(sort, begin, end,location);
		quicksort(sort, begin, location - 1);
		quicksort(sort, location + 1, end);
	}
}

int main() {
	vector<string>sort;
	string input;
	while(cin >> input){
		if (input == "end") {
			break;
		}
		sort.push_back(input);
	}
	quicksort(sort, 0, sort.size()-1);
	show(sort);


	return 0;
}