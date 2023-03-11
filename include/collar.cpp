#include "collar.hpp"
#include <stdio.h>

col::Cell::Cell(int dim, int amount_neighs, int amount_parameters){
    this->dim = dim;
    state = new double[dim];
    buffer_state = new double[dim];
    neighs = new col::Cell* [amount_neighs];
    parameters = new double[amount_parameters];
}
col::Cell::~Cell(){
    delete[] state;
    delete[] neighs;
    delete[] parameters;
}

int col::run(int steps, int field_size, col::Cell** field, void calc(int step, col::Cell** field)){
    for(int step = 0; step < steps; ++step){

        for(int k = 0; k < field_size; ++k){
            for(int s = 0; s < field[k]->dim; ++s){
                field[k]->buffer_state[s] = field[k]->state[s];
            }
        }
        calc(step, field);

    }
    return 0;
}