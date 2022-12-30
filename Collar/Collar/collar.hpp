#ifndef COLLAR_HPP
#define COLLAR_HPP

namespace col{
    class Cell{
    public:
        int dim;
        int type;
        double* buffer_state;
        double* parameters;
        double* state;
        Cell** neighs;
        Cell(int dim, int amount_neighs, int amount_parameters);
        ~Cell();
    };

    int run(int steps, int field_size, col::Cell** field, void calc(int step, Cell** cells));
}

#endif