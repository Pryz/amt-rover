int ledPin = 13;
#define CUSTOM_SETTINGS
/* Use the game pad */
#define INCLUDE_GAMEPAD_SHIELD
#define INCLUDE_TERMINAL_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>
#include <AFMotor.h>

// Motor objects, motor number on the motor shield board
AF_DCMotor motorBackRight(1);
AF_DCMotor motorFrontRight(2);
AF_DCMotor motorFrontLeft(3);
AF_DCMotor motorBackLeft(4);

int speed = 0;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();

  // The LED just works as an indicator that the 1Sheeld is working fine
  //pinMode(ledPin, OUTPUT);

  speed = 125;
  motorBackRight.setSpeed(speed);
  motorFrontRight.setSpeed(speed);
  motorBackLeft.setSpeed(speed);
  motorFrontLeft.setSpeed(speed);
}

void loop()
{
  /* Always check the status of gamepad buttons. */
  if (GamePad.isDownPressed())
  {
    motorBackRight.run(BACKWARD);
    motorFrontRight.run(BACKWARD);
    motorBackLeft.run(BACKWARD);
    motorFrontLeft.run(BACKWARD);

    //digitalWrite(ledPin, HIGH);
  }
  else if (GamePad.isUpPressed())
  {
    motorBackRight.run(FORWARD);
    motorFrontRight.run(FORWARD);
    motorBackLeft.run(FORWARD);
    motorFrontLeft.run(FORWARD);

    //digitalWrite(ledPin, HIGH);
  }
  else if (GamePad.isLeftPressed())
  {
    motorFrontLeft.run(BACKWARD);
    motorBackLeft.run(BACKWARD);
    motorFrontRight.run(FORWARD);
    motorBackRight.run(FORWARD);

    //digitalWrite(ledPin, HIGH);
  }
  else if (GamePad.isRightPressed())
  {
    motorFrontLeft.run(FORWARD);
    motorBackLeft.run(FORWARD);
    motorFrontRight.run(BACKWARD);
    motorBackRight.run(BACKWARD);
    //digitalWrite(ledPin, HIGH);
  }
  else
  {
    motorBackRight.run(RELEASE);
    motorFrontRight.run(RELEASE);
    motorBackLeft.run(RELEASE);
    motorFrontLeft.run(RELEASE);
    //digitalWrite(ledPin, LOW);
  }
  /* Boot mode */
  if (GamePad.isRedPressed())
  {
    speed = 255;
    motorBackRight.setSpeed(speed);
    motorFrontRight.setSpeed(speed);
    motorBackLeft.setSpeed(speed);
    motorFrontLeft.setSpeed(speed);
  } else if (GamePad.isBluePressed()) 
  {
    speed = 125;
    motorBackRight.setSpeed(speed);
    motorFrontRight.setSpeed(speed);
    motorBackLeft.setSpeed(speed);
    motorFrontLeft.setSpeed(speed);
  }
  if (Terminal.available())
  {
    Terminal.println("Current speed");
    Terminal.println(speed);
  }
}
