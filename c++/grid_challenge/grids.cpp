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

#include "grids.h"
#include <iostream>
#include <vector>

std::vector<std::vector<int>> Grid::construct_zero_grid(const int& rows, const int& row_length) {
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
	// A zero grid will be correctly represented by a zero sums_grid
	sums_grid_is_valid = true;
}

void Grid::update_sums_grid() {
	//TODO: loop through grid and calculate the sums
	sums_grid_is_valid = true;
}

void Grid::update_value(const int& x, const int& y, const int& val) {
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
	sums_grid_is_valid = false;
}

int Grid::query_span_simple(const int& x1, const int& y1, const int& x2, const int& y2) {
	if (x1 > x2 || y1 > y2 || x2 >= GRID_ROW_LENGTH || y2 >= GRID_ROW_COUNT) {
		std::cout << "Invalid query range in grid";
		return -1;
	}
	int span_sum;
	for (auto i = y1; i <= y2; i++) {
		for (auto j = x1; j <= x2; j++) {
			span_sum += val_grid[i][j];
		}	
	}
	return span_sum;
}

int Grid::query_span_complex(const int& x1, const int& y1, const int& x2, const int& y2) {
	return query_span_simple(x1, y1, x2, y2);
}

void Grid::print_grid(void) {
	for (auto row : val_grid) {
		for (auto in : row) {
			std::cout << in;
		}
		std::cout << "\n";
	}
}
	

/*int main() {
	Grid grid;
	grid.update_value(1,1,6);
	grid.update_value(1,2,3);
	grid.update_value(11,9,2);
	grid.update_value(15,9,1);
	grid.print_grid();
	std::cout << grid.query_span_complex(0,0,15,9) << std::endl;
	return 0;
}
*/
