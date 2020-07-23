

// Do we need the default constructor and destructor at all???

Rectangle(double width, double height, double xCentre, double yCentre){

  width_ = width;
  height_ = height;
  
  xCentre_ = xCentre; // centre coordinate of the rectangle
  yCentre_ = yCentre;

}

~Rectangle(){

}


double getArea(){

  return (width_ * height_);
}


bool pointIsInShape(x, y){

  // point is (x, y), is it in the rectangle shape?
 
  if (  (x < (xCentre + (width_/2))) && (x > (xCentre - (width_/2)))
	&& (y < (yCenter + (height_/2))) && (y > (yCentre - (height_/2)))  ){
    return true;
  }
  else{
    return false;
  }

}
 
