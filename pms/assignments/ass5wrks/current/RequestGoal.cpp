//
// a3_help::RequestGoal Class Implementation/definition.
//

#include "a3_help/RequestGoal.h"

// Constructor for a3_help::RequestGoal object.
//
bool a3_help::RequestGoal::a3_help::RequestGoal(a3_help::RequestGoal::Request &req, a3_help::RequestGoal::Response &res){

//bool a3_help::RequestGoal(Request &req, Response &res){

  double req.x = 0.0;
  double req.y = 0.0;
  double req.angle = 0.0;
  double req.scanTime = 10;
  
  bool res.ack = true;
  
  return res.ack;
  
}
