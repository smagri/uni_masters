void (global2image, image.cols, image.rows double resolution, 
      int py, int px, double y, double x){


  // Robot is  always at the centre  of the ogMap, so  find the centre
  // first then the offset from it.
  //
  px = ( (image.cols / 2) + (x / resolution) );
  py = ( (image.rows / 2) + (y / resolution) );
  
}
  
