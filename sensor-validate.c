/*****************************************************************************/
/***    \file        sensor-validate.c
***     \author      Naveen Balachandar (RBEI/ECK3) 
***
***     \brief       File to validate the sensors 
/*****************************************************************************/

/*Project headers*/
#include "sensor-validate.h"

int rangeMonitor_i(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

int validateSOCreadings(double* values, int numOfValues) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!rangeMonitor_i(values[i], values[i + 1], 0.05)) {
      return 0;
    }
  }
  return 1;
}

int validateCurrentreadings(double* values, int numOfValues) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!rangeMonitor_i(values[i], values[i + 1], 0.1)) {
      return 0;
    }
  }
  return 1;
}
