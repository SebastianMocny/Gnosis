/*
 *
 * This is my template for document boilerplate. 
 * Last update to this template is: November 12, 2018
 *
 * TODO: Add licensing info. For example, Apache 2.0
 *
 * Containers.cpp is intended to familiarize myself with all the common C++ containers
 * as well as common std tools like std::vector. They all have differences and unique
 * uses so playing with them side by side might clarify these differences.
 * 
 * Author: Sebastian Mocny
 * Date of file creation: November 20, 2018
 */

#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

// Const time insertion/removal from anywhere in the container. Usually implemented as doubly linked list. 
// Bidirectional iteration capabilities, consider using std::forward_list if you only need 1 direction and wish to save some space
void std_list() {
	std::list<int> my_list = { 7, 5, 15, 6, 19 };

	std::cout << "List is:  ";
	for (int i : my_list) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	my_list.push_back(12);
	my_list.push_front(2);

	//add a 1 in front of every number in the list larger than 7
	//auto it = std::find(my_list.begin(), my_list.end() 

	std::cout << "List is now:  ";
	for (int i : my_list) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void std_vector() {
}

void std_array() {
}

void std_deque() {
}

void std_string() {
}

void multiset() {
}

void set() {
}

void unordered_set() {
	std::vector<int> vect_left = {1 , 3, 5, 6, 10, 5, 12, 4};
	std::vector<int> vect_right = {3, 1, 5, 6, 6, 12, 1, 4, 3};
	int sum = 10;
	std::unordered_set<int> left_set(vect_left.begin(), vect_left.end());
	left_set.insert(vect_right.begin(), vect_right.end());
	for (const auto& val : vect_right) {
		int desired_val = sum - val;
		std::cout << desired_val;
	    const auto it = left_set.find(desired_val);
		if (it != left_set.end()) {
			std::cout << "Exists";
		}
	}
	left_set.erase(4);
	left_set.erase(10);
	left_set.erase(10);
	left_set.erase(1);
	for (auto element : left_set) {
		std::cout << element << " - ";
	}
}

void map() {
}

void unordered_map() {
	std::vector<std::pair<std::string, std::string>> dict_words({ {"test", "something written"}, {"class", "something attended"} });
	std::unordered_map<std::string, std::string> dict_map(dict_words.begin(), dict_words.end());
	//dict_words["class"] = " hahaha";
}

void bitfield() {
}

void pair() {
}

void tuple() {
}

void hash_set() {
}

void hash_map() {
}

int main() {
//	std_list();
//	unordered_set();
	unordered_map();
	return 0;
}
