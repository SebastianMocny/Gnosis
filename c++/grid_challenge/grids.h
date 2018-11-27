#ifndef GRIDS_H
#define GRIDS_H

#include <vector>

const int GRID_ROW_COUNT = 10;
const int GRID_ROW_LENGTH = 20;

class Grid {
    private:
        std::vector<std::vector<int>> val_grid;
        std::vector<std::vector<int>> sums_grid;
        std::vector<std::vector<int>> construct_zero_grid(const int& x_columns, const int& y_rows);
        bool sums_grid_is_valid = false;
        
		// Worst case o(n^4). 
		// This will run through and generate the values to the sums_grid.
		// TODO: If the grid is already generated, then only sections that were affected by an update need to be worked out - implementation is up to debate
		void update_sums_grid(const int& x, const int& y, const int& val);
        
		int query_span_brute_force(const int& x1, const int& y1, const int& x2, const int& y2); // O(n^2)
        int query_span_sums_grid(const int& x1, const int& y1, const int& x2, const int& y2); // O(1) if update has not been called. Otherwise, a worst case O(n^4) "update" operation is required
    public:
        Grid();
        // Simple and complex do the same thing in a different way, with a tradeoff in time/space complexity
        // TODO: Overload these functions using a prediction method (Bayes prior?) to determine whether to use simple or complex and switch between the two
        // This will require us to keep track of the calls made, and to compare #of calls to update vs. calls to query
        void update_value(const int& x, const int& y, const int& val); // O(1) 
        int query_span(const int& x1, const int& y1, const int& x2, const int& y2); // O(n^2)
        void print_grid(void);
};

#endif
