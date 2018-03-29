#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;
using namespace std;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse(4);
  rmse << 0,0,0,0;

  // checking inputs on validity
  // for Calculation estimation has to be != 0 and have the same size like ground_truth therefore:
  if (estimations.size() == 0 || estimations.size() != ground_truth.size()){
    cout<<"SizeError - Estimations = 0 or != ground_truth!";
  }
    // Accumulate squared residuals
  for(unsigned int i=0; i < estimations.size(); ++i){
    VectorXd residual = estimations[i] - ground_truth[i];
    // Coefficient-wise multiplication
    residual = residual.array()*residual.array();
    rmse += residual;
  }

  //calculate the mean
  rmse = rmse / estimations.size();
  //calculate the squared root
  rmse = rmse.array().sqrt();
  return rmse;
}