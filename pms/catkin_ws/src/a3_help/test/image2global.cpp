void image2global(int image.cols, image.rows double resolution, 
		  int py, int px, double y, double x){

  // Robot is  always at the centre  of the ogMap, so  find the centre
  // first then the offset from it.
  //
  x = ( ((image.cols / 2) * resolution) + (px * resolution) );
  y = ( ((image.rows / 2) * resolution) * (py * resolution) );
    

}
