#ifndef PIDController_h
#define PIDController_h

#include <Arduino.h>

class PIDController {
  private:
    double kP;
    double kI;
    double kD;
    double setpoint;
    double lastMeasurementTime;
    double lastMeasurement;
    double getProp(double measurement);
    double getIntegral(double measurement);
    double getDerivative(double measurement);

  public:
    PIDController(double p, double i, double d);
    double calculate(double nextSetpoint, double measurement); 
    double calculate(double measurement);
    void setTarget(double target);
    double getError(double measurement);
    double getError();
};

#endif