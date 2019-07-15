#include "ProgrammingSteps.h"

unsigned char currentStep;

void setup() {
  // put your setup code here, to run once:
  unsigned char programResult;
  unsigned char errorStatus;
  unsigned char sromErrorStatus;

  Serial.begin(115200);
  Serial.println("");
  Serial.println("Programming PSoC 4");

  programResult = ProgramDevice();
  if (programResult == SUCCESS) {
    Serial.println("HSSP Success");
  }
  else {
    Serial.println("HSSP Fail Step");
    Serial.println(currentStep, DEC);
    errorStatus = ReadHsspErrorStatus();
    Serial.println("Err");
    Serial.println(errorStatus, HEX);
    if ((errorStatus & SROM_TIMEOUT_ERROR) == 0x01) {
      sromErrorStatus = ReadSromStatus();
      Serial.println("SROM");
      Serial.println(sromErrorStatus, HEX);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

/******************************************************************************
* Function Name: ProgramDevice
*******************************************************************************
* Summary:
*  This function sequentially calls all the functions required to program a
*  PSoC 4/PSoC Analog Coprocessor. These functions are defined in ProgrammingSteps.h.
*
* Parameters:
*  None.
*
* Return:
*  SUCCESS - All the programming steps executed successfully
*  FAILURE - HSSP programming fails in any one of the programming step
*
******************************************************************************/
unsigned char ProgramDevice(void)
{
  currentStep = 1;

  Serial.println(currentStep);
  if (DeviceAcquire() == FAILURE)
    return (FAILURE);

  currentStep++;
  Serial.println(currentStep);
  if (VerifySiliconId() == FAILURE)
    return (FAILURE);

  currentStep++;
  Serial.println(currentStep);
  if (EraseAllFlash() == FAILURE)
    return (FAILURE);

  currentStep++;
  Serial.println(currentStep);
  if (ChecksumPrivileged() == FAILURE)
    return (FAILURE);

  currentStep++;
  Serial.println(currentStep);
  if (ProgramFlash() == FAILURE)
    return (FAILURE);

  currentStep++;
  Serial.println(currentStep);
  if (VerifyFlash() == FAILURE)
    return (FAILURE);

  currentStep++;
  Serial.println(currentStep);
  if (ProgramProtectionSettings() == FAILURE)
    return (FAILURE);

  currentStep++;
  Serial.println(currentStep);
  if (VerifyProtectionSettings() == FAILURE)
    return (FAILURE);

  currentStep++;
  Serial.println(currentStep);
  if (VerifyChecksum() == FAILURE)
    return (FAILURE);

  ExitProgrammingMode();

  /* All the steps were completed successfully */
  return (SUCCESS);
}
