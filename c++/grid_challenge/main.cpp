/*
 * This is my template for document boilerplate. 
 * Last update to this template is: November 23, 2018
 *
 * TODO: Add licensing info. For example, Apache 2.0
 *
 * Author: Sebastian Mocny
 * File description: Main for grid challenge. We want to set values within a grid, and then query that grid for the values spanning a portion of the grid. 
 * Date of file creation: Nov 23, 2018
 */

#include <iostream>
#include "grids.h"

int main() {
    Grid grid;
    grid.update_value(1,1,6);
    grid.update_value(1,2,3);
    grid.update_value(11,9,2);
    grid.update_value(15,9,1);
    grid.print_grid();
    std::cout << grid.query_span_complex(0,0,15,9) << std::endl;
    return 0;
}
