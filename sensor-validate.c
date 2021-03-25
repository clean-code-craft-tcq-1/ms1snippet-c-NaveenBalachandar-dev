/*****************************************************************************/
/***    \file        sensor-validate.c
***     \author      Naveen Balachandar (RBEI/ECK3) 
***
***     \brief       File to validate the sensors 
/*****************************************************************************/

/*standard headers*/
#include <stddef.h>

/*Project headers*/
#include "sensor-validate.h"

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    checkAbnormality_i
 */
/*!    \brief       predecting the valid sensor range
 * 
 *     \param       current value ,next value and max value
 *     \returns     validity status
 *
*//*------------------------------------------------------------------------*/
int checkAbnormality_i(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    validateSensorParmtReadings_i
 */
/*!    \brief       validating the sensor parametres like SOC ,current
 * 
 *     \param       current value ,next value and max value
 *     \returns     validity status
 *
*//*------------------------------------------------------------------------*/
int validateSensorParmtReadings_i(double* values, int numOfValues) {
  int lastButOneIndex = numOfValues - 1;
  //if (NULL != values)
  {  
   for(int i = 0; i < lastButOneIndex; i++) 
   {
    if(!checkAbnormality_i(values[i], values[i + 1], 0.05)) /*sensor readings validation with Max range*/
    {
      /*Retruns 0 if there is any abnormalities in sensor readings */
      return 0;
    }
   }
  }
  /*Retruns TRUE if there is no abnormalities in sensor readings */
  return 1;
}


