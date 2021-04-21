  #include <MQ2.h>
  #include <Wire.h> 
  #include <LiquidCrystal_I2C.h>
  //I2C pins declaration
  LiquidCrystal_I2C lcd(0x27, 16, 2);
int Analog_Input = A0;
int lpg, co, smoke;

MQ2 mq2(Analog_Input);

void setup(){
  Serial.begin(9600);
  lcd.begin();//Defining 16 columns and 2 rows of lcd display
  lcd.backlight();
  mq2.begin();
}
void loop(){
  float* values= mq2.read(true); //set it false if you don't want to print the values in the Serial
  //lpg = values[0];
  lpg = mq2.readLPG();
  //co = values[1];
  co = mq2.readCO();
  //smoke = values[2];
  smoke = mq2.readSmoke();
  lcd.setCursor(0,0);
  lcd.print("LPG:");
  lcd.print(lpg);
  lcd.print(" CO:");
  lcd.print(co);
  lcd.setCursor(0,1);
  lcd.print("SMOKE:");
  lcd.print((smoke*100)/1000000);
  lcd.print(" %");
  delay(1000);
}
