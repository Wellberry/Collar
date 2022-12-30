#include <stdio.h>
#include "collar.hpp"

int height = 0;
int vel = 1;
int field_size = 10;
int S = 5e7;
double dt = 5.0/S;

void calc(int step, col::Cell** cells){
    for(int k = 0; k < 10; ++k){
        col::Cell* neigh = cells[k]->neighs[0];
        double dist = cells[k]->buffer_state[height] - neigh->buffer_state[height];
        cells[k]->state[vel] += dist*dt;
        cells[k]->state[height] -= cells[k]->buffer_state[vel]*dt;
    }
    if(step%1000 == 0){
        printf("%6.3d ", step);
        for(int k = 0; k < 10; ++k){
            printf("%6.3f ", cells[k]->state[height]);
        }
        printf("\n");
    }
}

int main(){
    //setup field, states and boundary condition
    col::Cell* cells[field_size];
    for(int k=0; k<field_size; ++k){
        cells[k] = new col::Cell(2, 1, 0);
        cells[k]->state[height] = 0;
        cells[k]->state[vel] = 0;
    }
    cells[0]->neighs[0] = cells[9];
    for(int k=1; k<10; ++k){
        cells[k]->neighs[0] = cells[k-1];
    }
    cells[5]->state[height] = 1;
    col::run(S, field_size, cells, calc);

    //deleting field
    for(int k=0; k<10; ++k){
        delete cells[k];
    }
    return 0;
}