/*********************************************************
 * Driving a small stepper with a Tiny85
 */

/* We're only going to drive the step pin and the dir pin.  
 *  MS1 and MS2 will be hardwired, as well as the enable pin.
 */
#define STEP_PIN  0
#define DIR_PIN   1

#define STEPS_PER_ROTATION 540
int step_count = 0;
int dir=LOW;

void setup() 
{

  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  digitalWrite(DIR_PIN, dir);

}

void loop() 
{

  // According to the data sheet, we've got 516.096 steps per revolution.
  // We're gonna start by trying one full rotation fwd, then one back (then repeat)

  // Start by taking a step.
  digitalWrite(STEP_PIN, HIGH);
  delay(1);
  digitalWrite(STEP_PIN,LOW);
  delay(2);
  step_count++;

  if (step_count >= STEPS_PER_ROTATION)
  {
    // set the new direction
    if (dir == HIGH)
    {
      dir = LOW;
    }
    else
    {
      dir = HIGH;
    }
    digitalWrite(DIR_PIN, dir);

    // reset our count
    step_count = 0;
  }

}
