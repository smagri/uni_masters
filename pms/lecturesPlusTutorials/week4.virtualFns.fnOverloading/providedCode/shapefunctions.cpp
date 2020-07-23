#include "shape.h"

namespace shape_functions {

double getAreaOfBoundingShapes(Shape ** shape_array, int num_shapes, double x, double y) {
    double total_area = 0;
    for (int i = 0; i < num_shapes; i++) {
        if (shape_array[i]->pointIsInShape(x,y)) {
            total_area += shape_array[i]->area();
        }
    }
    return total_area;
}

}
