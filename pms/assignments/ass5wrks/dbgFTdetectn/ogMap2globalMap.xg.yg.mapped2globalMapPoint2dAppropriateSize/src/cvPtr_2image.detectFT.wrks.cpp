// cell above robot cell
int x=px;  int y=py-1;
if ( (x>=0 && x<cvPtr_->image.cols) && (y>=0 && y<=cvPtr_->image.rows) ){

  if (cvPtr_->image.at<uchar>(y, x) == UK){
    cvPtr_->image.at<uchar>(py, px) = FT;

    std::cerr << "dbg: detectFT: cell above FT found" << std::endl;

    angleDeg=90;

    // The map container  here will replace the old  y key value
    // with the new x value.
    unvisitedFT[py]=px;
  }
  std::cerr << "dbg: detectFT: in cell above" << std::endl;
 }

// cell below robot cell
x=py;  y=py+1;
if ( (x>=0 && x<cvPtr_->image.cols) && (y>=0 && y<cvPtr_->image.rows) ){

  if (cvPtr_->image.at<uchar>(y, x) == UK){
    cvPtr_->image.at<uchar>(py, px) = FT;

    std::cerr << "dbg: detectFT: cell below FT found" << std::endl;

    angleDeg=270;
    unvisitedFT[py]=px;
  }
  std::cerr << "dbg: detectFT: in cell below" << std::endl;
 }
// cell left of robot cell
x=px-1;  y=py;
if ( (x>=0 && x<cvPtr_->image.cols) && (y>=0 && y<cvPtr_->image.rows) ){

  if (cvPtr_->image.at<uchar>(y, x) == UK){
    cvPtr_->image.at<uchar>(py, px) = FT;

    std::cerr << "dbg: detectFT: cell left FT found" << std::endl;

    angleDeg=180;
    unvisitedFT[py]=px;
  }
  std::cerr << "dbg: detectFT: in cell left" << std::endl;
 }

// cell right of robot cell
x=px+1;  y=py;
if ( (x>=0 && x<cvPtr_->image.cols) && (y>=0 && y<cvPtr_->image.rows) ){
  if (cvPtr_->image.at<uchar>(y, x) == UK){
    cvPtr_->image.at<uchar>(py, px) = FT;

    std::cerr << "dbg: detectFT: cell right FT found" << std::endl;

    angleDeg=0;
    unvisitedFT[py]=px;
  }
  std::cerr << "dbg: detectFT: in cell right" << std::endl;
 }


} // end: if (cvPtr_->image.at<uchar>(px, py) == FS){
std::cerr << "dbg: detectFT: end:" << std::endl;


} // end: void detectFrontiers(int py int px, &angleDeg, &unvisitedFT){
