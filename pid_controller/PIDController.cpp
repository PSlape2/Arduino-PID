#include "PIDController.h"

PIDController::PIDController(double p, double i, double d) {
  kP = p;
  kI = i;
  kD = d;

  setpoint = 0;
  lastMeasurementTime = millis();
  lastMeasurement = 0;
}

double PIDController::getProp(double measurement) {
  return kP * getError();
}

double PIDController::getIntegral(double measurement) {
  return kI * ((getError() - getError(measurement)) / 2) * (millis() - lastMeasurementTime);
}

double PIDController::getDerivative(double measurement) {
  return kD * (getError(measurement) - getError()) / (millis() - lastMeasurementTime);
}

double PIDController::getError(double measurement) {
  return abs(setpoint - measurement);
}

double PIDController::getError() {
  return abs(setpoint - lastMeasurement);
}

double PIDController::calculate(double nextSetpoint, double measurement) {
  setpoint = nextSetpoint;
  double prop = getProp(measurement);
  double integ = getIntegral(measurement);
  double der = getDerivative(measurement);
  lastMeasurement = measurement;

  return prop + integ + der;
}

double PIDController::calculate(double measurement) {
  return calculate(setpoint, measurement);
}

void PIDController::setTarget(double target) {
  setpoint = target;
}