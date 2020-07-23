#include "shape.h"
#include "shapefunctions.h"

namespace shape_functions{

  // Function definition here should match fn prototype in shapefuncions.h.
  //
  // Shape *, or pointer to a Shape class is kind of like a pointer to
  // a struct in c, hence dereferencing is with the -> operator.
  double getAreaOfBoundingShapes(vector<Shape *> &shapeContainer,
  				 int num_shapes, double x, double y){
    
    double total_area = 0;
    for (int i = 0; i < num_shapes; i++) {
      if (shapeContainer[i]->pointIsInShape(x,y)) {
  	total_area += shapeContainer[i]->area();
      }
    }
    
    return total_area;
  }
  
  
} // end namespace shape_functions
