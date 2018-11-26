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

const uint64_t GRID_ROW_COUNT = 10;
const uint64_t GRID_ROW_LENGTH = 20;

class Grid {
	private:
		std::vector<std::vector<int>> val_grid;
		std::vector<std::vector<int>> sums_grid;
		std::vector<std::vector<int>> construct_zero_grid(const uint64_t& x_columns, const uint64_t& y_rows);
		void update_sums_grid(); // Worst case o(n^4). This will run through and generate the values to the sums_grid. TODO: If the grid is already generated, then only sections that were affected by an update need to be worked out - implementation is up to debate
	public:
		Grid();
		// Simple and complex do the same thing in a different way, with a tradeoff in time/space complexity
		// TODO: Overload these functions using a prediction method (Bayes prior?) to determine whether to use simple or complex and switch between the two
		// This will require us to keep track of the calls made, and to compare #of calls to update vs. calls to query
		void update_value_simple(const uint64_t& x, const uint64_t& y, const int& val); // O(1)
		int query_span_simple(const uint64_t& x1, const uint64_t& y1, const uint64_t& x2, const uint64_t& y2); // O(n^2)

		void update_value_complex(const uint64_t& x, const uint64_t& y, const int& val); // O(1) - See note below
		int query_span_sum_complex(const uint64_t& x1, const uint64_t& y1, const uint64_t& x2, const uint64_t& y2); // O(1) if update has not been called. Otherwise, a worst case O(n^4) "update" operation is required
		void print_grid(void);

};

std::vector<std::vector<int>> Grid::construct_zero_grid(const uint64_t& rows, const uint64_t& row_length) {
		std::vector<std::vector<int>> zero_grid;
		zero_grid.resize(rows);
		for (auto& row : zero_grid) {
			row.resize(row_length);
		}
		return zero_grid;
}

Grid::Grid(void) {
	val_grid = construct_zero_grid(GRID_ROW_COUNT, GRID_ROW_LENGTH);
	sums_grid = construct_zero_grid(GRID_ROW_COUNT, GRID_ROW_LENGTH);
}

void Grid::update_sums_grid() {
}

void Grid::update_value_simple(const uint64_t& x, const uint64_t& y, const int& val) {
	if (val_grid.empty()) {
		//TODO: error checking without throwing exception?
		std::cout << "empty grid error" << std::endl;
		return;
	}
	if (x >= GRID_ROW_LENGTH || y >= GRID_ROW_COUNT) {
		std::cout << "Invalid update position in grid";
		return;
	}
	val_grid[y][x] = val;
}

int Grid::query_span_simple(const uint64_t& x1, const uint64_t& y1, const uint64_t& x2, const uint64_t& y2) {
	if (x1 > x2 || y1 > y2 || x2 >= GRID_ROW_LENGTH || y2 >= GRID_ROW_COUNT) {
		std::cout << "Invalid query range in grid";
		return -1;
	}
	int span_sum;
	for (uint64_t i = y1; i <= y2; i++) {
		for (uint64_t j = x1; j <= x2; j++) {
			span_sum += val_grid[i][j];
		}	
	}
	return span_sum;
}

void Grid::update_value_complex(const uint64_t& x, const uint64_t& y, const int& val) {
}

int Grid::query_span_sum_complex(const uint64_t& x1, const uint64_t& y1, const uint64_t& x2, const uint64_t& y2) {
}

void Grid::print_grid(void) {
	for (auto row : val_grid) {
		for (auto in : row) {
				std::cout << in;
		}
		std::cout << "\n";
	}
}
	

int main() {
	Grid grid;
	grid.update_value_simple(1,1,6);
	grid.update_value_simple(1,2,3);
	grid.update_value_simple(11,9,2);
	grid.update_value_simple(15,9,1);
	grid.print_grid();
	std::cout << grid.query_span_simple(0,0,15,9);
	return 0;
}
