17july2018


Need to add code of if() expression:

ie //if ((image.at<uchar>(y, x)!=FS) && (image.at<uchar>(y, x)!=O)){

should really be:
if ((image.at<uchar>(y, x)!=FS) && (image.at<uchar>(y, x)!=O)
    && (!FTadjCell))

To determine if this adjacent cell is a FT node:

// cell above robot cell
int x=px;  int y=py-1;
pxFTadj = x;
pyFTadj = y;

std:d:map<std::pair<int,int>,double>::iterator itFT;
for (itFT=frontier.begin(); itFT!=frontier.end(); itFT++){
  int pyFT = itFT->first.first; // get Key pair
  int pxFT = itFT->first.second;
  if ((pyFTadj == pyFT) && (pxFTadj == pxFT)){
    FTadjCell = true;
    break; // exit the for loop
  }
 }



actual segment:
--------------

    if (image.at<uchar>(py, px) == FS){
      
      // // In addition,  if this cell is  already a FT cell  it is known
      // // and we don't need to test for it again???
      // std::map<std::pair<int,int>,double>::iterator itFT;
      // for (itFT=frontier.begin(); itFT!=frontier.end(); itFT++){
      // 	// key=pair(py,px), value=angle
      // 	int pyFT = itFT->first.first; // get Key pair
      // 	int pxFT = itFT->first.second;
      // 	if ((pyFT == py) && (pxFT == px)){
      // 	  return;
      // 	}
      // }    

      std::cerr << "dbg: detectFT: FS found" << std::endl;
      
      // cell above robot cell
      int x=px;  int y=py-1;
      if ( (x>=0 && x<image.cols) && (y>=0 && y<=image.rows) ){
	
	//if ((image.at<uchar>(y, x)!=FS) && (image.at<uchar>(y, x)!=O)){
	// LATER: should this also inclued && !FT node??? **************
	if ( ((pi=image.at<uchar>(y, x)) != FS)
	     &&  ((pi=image.at<uchar>(y, x)) != O) ) {
	  
	  // UK cell found above FS
	  std::cerr << "dbg: detectFT: UK cell above FT found" << std::endl;
	  
	  // insert elements in random order
	  unvisitedFT.insert(std::make_pair(py,px));
	  frontier.insert( std::make_pair(std::make_pair(py,px), 90.0) );
	}
      }
      
