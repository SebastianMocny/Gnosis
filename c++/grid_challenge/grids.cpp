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

// ************************* PRIVATE METHODS ******************************************

Grid::Grid(void) {
	val_grid = construct_zero_grid(GRID_ROW_COUNT, GRID_ROW_LENGTH);
	sums_grid = construct_zero_grid(GRID_ROW_COUNT, GRID_ROW_LENGTH);
	// A zero grid will be correctly represented by a zero sums_grid
	sums_grid_is_valid = true;
}

std::vector<std::vector<int>> Grid::construct_zero_grid(const int& rows, const int& row_length) {
		std::vector<std::vector<int>> zero_grid;
		zero_grid.resize(rows);
		for (auto& row : zero_grid) {
			row.resize(row_length);
		}
		return zero_grid;
}

// For now, we will regenerate all values above and to the right of the updated co-ordinate. 
// We can do this optimization, rather than generating an entire sums grid each time, because only sums at positions after the updated value are affected
// TODO: Only run UPDATE when explicitly called. We need to keep a reference (KV store?) of all the updates since this was run last. Then it becomes 
// a runtime of (number of calls since last update)*(rows*length) aka calls*n^2
void Grid::update_sums_grid(const int& x, const int& y, const int& val) {
	// Shouldn't need bounds checking since it was done in update_val
	for (auto row = y; row < sums_grid.size(); row++) {
		for (auto pos = x; pos < sums_grid[row].size(); pos++) {
			sums_grid[row][pos] += val;
		}
	}
	sums_grid_is_valid = true;
}

int Grid::query_span_brute_force(const int& x1, const int& y1, const int& x2, const int& y2) {
	int span_sum;
	for (auto i = y1; i <= y2; i++) {
		for (auto j = x1; j <= x2; j++) {
			span_sum += val_grid[i][j];
		}	
	}
	return span_sum;
}

// The algorithm works by taking the sum at position x2, y2, and subtracting the regions that are not part of the queried span
// Note, we add the region below x1,y1 because it is subtracted out twice
int Grid::query_span_sums_grid(const int& x1, const int& y1, const int& x2, const int& y2) {
	if (!sums_grid_is_valid) {
		return query_span_brute_force(x1, y1, x2, y2);
	}
	int query_sum = sums_grid[y2][x2];

	if (y1 <= 0 && x1 <= 0) { //Edge case 1: the span is from x2,y2 to 0,0
		return query_sum;
	}

	// Edge case 2&3: Span is from x2,y2 to one of x1 = 0 or y1 = 0. Here we only remove 1 section from the total
	if (x1 <= 0) { 
		query_sum -= sums_grid[y1 - 1][x2];
	} else if (y1 <= 0) {
		query_sum -= sums_grid[y2][x1 - 1];
	} else {
		query_sum -= sums_grid[y2][x1 - 1];
		query_sum -= sums_grid[y1 - 1][x2];
		query_sum += sums_grid[y1 - 1][x1 - 1];
	}
	return query_sum;
}

// ************************* PUBLIC METHODS ******************************************

int Grid::query_span(const int& x1, const int& y1, const int& x2, const int& y2) {
	if (x1 > x2 || y1 > y2 || x2 >= GRID_ROW_LENGTH || y2 >= GRID_ROW_COUNT) {
		std::cout << "Invalid query range in grid";
		return -1;
	}
	if (sums_grid_is_valid) {
		query_span_sums_grid(x1, y1, x2, y2);
	} else {
		query_span_brute_force(x1, y1, x2, y2);
	}
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
	update_sums_grid(x, y, val);
}

void Grid::print_grid(void) {
	std::cout << "_________ GRID ________ \n";
	for (auto row : val_grid) {
		for (auto in : row) {
			if (in == 0) {
				std::cout << " ";
			} else {
				std::cout << in;
			}
		}
		std::cout << "\n";
	}
	std::cout << "_____ SUMS GRID _____";
	if (sums_grid_is_valid) {
		std::cout << "Is up to date\n";
	} else {
		std::cout << "NOT up to date!!\n";
	}
	for (auto row : sums_grid) {
		for (auto in : row) {
			if (in == 0) {
				std::cout << " ";
			} else {
				std::cout << in;
			}
		}
		std::cout << "\n";
	}
}

