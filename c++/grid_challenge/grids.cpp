/*
 * This is my template for document boilerplate. 
 * Last update to this template is: November 23, 2018
 *
 * TODO: Add licensing info. For example, Apache 2.0
 *
 * Author: Sebastian Mocny
 * File description: A grid of values that receives updates at X Y coordinates, and retreives a sum of values over a span
 * Date of file creation: Nov 23, 2018
 */

#include <iostream>
#include <vector>

class Grid_2d {
	private:
		std::vector<std::vector<int>> val_grid;
		std::vector<std::vector<int>> sums_grid;
		void update_sums_grid(); // Worst case o(n^4). This will run through and generate the values to the sums_grid. TODO: If the grid is already generated, then only sections that were affected by an update need to be worked out - implementation is up to debate
	public:
		// Simple and complex do the same thing in a different way, with a tradeoff in time/space complexity
		// TODO: Overload these functions using a prediction method (Bayes prior?) to determine whether to use simple or complex and switch between the two
		// This will require us to keep track of the calls made, and to compare #of calls to update vs. calls to query
		void update_value_simple(const int x, const int y, const int val); // O(1)
		int query_span_simple(const int x1, const int y1, const int x2, const int y2); // O(n^2)

		void update_value_complex(const int x, const int y, const int val); // O(1) - See note below
		int query_span_sum_complex(const int x1, const int y1, const int x2, const int y2); // O(1) if update has not been called. Otherwise, a worst case O(n^4) "update" operation is required

};

void Grid_2d::update_sums_grid() {

}

void Grid_2d::update_value_simple(const int x, const int y, const int val) {
}

int Grid_2d::query_span_simple(const int x1, const int y1, const int x2, const int y2) {
}

void Grid_2d::update_value_complex(const int x, const int y, const int val) {
}

int Grid_2d::query_span_sum_complex(const int x1, const int y1, const int x2, const int y2) {
}

int main() {
	return 0;
}
