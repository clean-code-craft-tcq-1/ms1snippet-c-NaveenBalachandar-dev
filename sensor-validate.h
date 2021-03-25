/*****************************************************************************/
/***    \file        sensor-validate.h
***     \author      Naveen Balachandar (RBEI/ECK3) 
***
***     \brief       header file for sensor validation project file  
/*****************************************************************************/

/*Common Functions */
/*Func to monitor sensor values range */
int checkAbnormality_i(double value, double nextValue, double maxDelta);
/*Func to read the sensor parametres like SOC ,current*/
int validateSensorParmtReadings_i(double* values, int numOfValues,double maxThreshold);


