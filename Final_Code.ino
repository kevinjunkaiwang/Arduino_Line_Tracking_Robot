const int Sensor_right = A0;     // Set Right Line Walking Infrared sensor port
const int Sensor_middle = A1;     // Set Middle Line Walking Infrared sensor port
const int Sensor_left = A2;      // Set Left Line Walking Infrared sensor port

int SR;    // State of Right Line Walking Infrared sensor
int SM;    // State of Right Line Walking Infrared sensor
int SL;    // State of Left Line Walking Infrared sensor

int ir_correction_left = 0;
int ir_correction_middle = 0;
int ir_correction_right = 0;

int block_L = 0;
int block_R = 0;
int block_M = 0;

void setup() {
  pinMode(Sensor_right, INPUT);
  pinMode(Sensor_middle, INPUT);
  pinMode(Sensor_left, INPUT);
  Serial.begin(9600);

}

void loop() {
  SR = analogRead(Sensor_right);
  SM = analogRead(Sensor_middle);
  SL = analogRead(Sensor_left);

  if (SR > 500){block_R = 1;}else{block_R = 0;}
  if (SL > 500){block_L = 1;}else{block_L = 0;}
  if (SM > 500){block_M = 1;}else{block_M = 0;}
  //Serial.println(SR);
  
    
  if (block_L == 1 && block_R == 0 && block_M == 1)// Left sensor against white undersurface and right against black undersurface , the car left off track and need to adjust to the right.
  {
    Serial.println("turn left");
  }
    
  else if (block_L == 0 && block_R ==  1 && block_M == 1) // Rihgt sensor against white undersurface and left against black undersurface , the car right off track and need to adjust to the left.
  {
    Serial.println("turn right");
  }
  else if (block_L == 0 && block_R == 1 && block_M == 0)// Left sensor against white undersurface and right against black undersurface , the car left off track and need to adjust to the right.
  {
    Serial.println("turn oneside right");
  }
    
  else if (block_L == 1 && block_R ==  0 && block_M == 0) // Rihgt sensor against white undersurface and left against black undersurface , the car right off track and need to adjust to the left.
  {
    Serial.println("turn oneside left");
  }
  else if (block_L == 0 && block_R ==  0 && block_M == 1)
  {
    Serial.println("straight");
  }
  else
  {
    if (block_R == 1 && block_L == 1)
    {
      Serial.println("stop");
    }
  }
  delay(50);
}
