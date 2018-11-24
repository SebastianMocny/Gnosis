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

const int GRID_X_COLUMNS = 10;
const int GRID_Y_ROWS = 10;

class Grid {
	private:
		std::vector<std::vector<int>> val_grid;
		std::vector<std::vector<int>> sums_grid;
		std::vector<std::vector<int>> construct_zero_grid(int x_columns, int y_rows);
		void update_sums_grid(); // Worst case o(n^4). This will run through and generate the values to the sums_grid. TODO: If the grid is already generated, then only sections that were affected by an update need to be worked out - implementation is up to debate
	public:
		Grid();
		// Simple and complex do the same thing in a different way, with a tradeoff in time/space complexity
		// TODO: Overload these functions using a prediction method (Bayes prior?) to determine whether to use simple or complex and switch between the two
		// This will require us to keep track of the calls made, and to compare #of calls to update vs. calls to query
		void update_value_simple(const int x, const int y, const int val); // O(1)
		int query_span_simple(const int x1, const int y1, const int x2, const int y2); // O(n^2)

		void update_value_complex(const int x, const int y, const int val); // O(1) - See note below
		int query_span_sum_complex(const int x1, const int y1, const int x2, const int y2); // O(1) if update has not been called. Otherwise, a worst case O(n^4) "update" operation is required
		void test(void);
		void print_grid(void);

};

void Grid::test() {
	std::cout << "yest" << std::endl;
}

std::vector<std::vector<int>> Grid::construct_zero_grid(int x_columns, int y_rows) {
		std::vector<std::vector<int>> zero_grid;
		zero_grid.resize(y_rows);
		for (int i = 0; i < x_columns; i++) {
			zero_grid[i].resize(x_columns);
		}
		return zero_grid;
}

Grid::Grid(void) {
	val_grid = construct_zero_grid(GRID_X_COLUMNS, GRID_Y_ROWS);
	sums_grid = construct_zero_grid(GRID_X_COLUMNS, GRID_Y_ROWS);
}

void Grid::update_sums_grid() {
}

void Grid::update_value_simple(const int x, const int y, const int val) {
	if (val_grid.empty()) {
		//TODO: error checking without throwing exception?
		std::cout << "empty grid error" << std::endl;
		return;
	}
	val_grid[y][x] = val;
}

int Grid::query_span_simple(const int x1, const int y1, const int x2, const int y2) {
	if (x1 > x2 || y1 > y2) {
		std::cout << "Invalid range in grid";
		return -1;
	}
	int span_sum;
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			span_sum += val_grid[i][j];
		}	
	}
	return span_sum;
}

void Grid::update_value_complex(const int x, const int y, const int val) {
}

int Grid::query_span_sum_complex(const int x1, const int y1, const int x2, const int y2) {
}

void Grid::print_grid() {
	for (auto row : val_grid) {
		for (auto in : row) {
				std::cout << in;
		}
		std::cout << "\n";
	}
}
	

int main() {
	Grid grid;
	grid.test();
	grid.update_value_simple(1,1,1);
	grid.print_grid();
	return 0;
}
