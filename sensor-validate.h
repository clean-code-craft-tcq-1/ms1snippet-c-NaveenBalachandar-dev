/*****************************************************************************/
/***    \file        sensor-validate.h
***     \author      Naveen Balachandar (RBEI/ECK3) 
***
***     \brief       header file for sensor validation project file  
/*****************************************************************************/

/*Common Functions */
int rangeMonitor_i(double value, double nextValue, double maxDelta);

int validateSOCreadings(double* values, int numOfValues);

int validateCurrentreadings(double* values, int numOfValues);
