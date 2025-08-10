unsigned long onTime = 0;
unsigned long offTime = 0;
bool sensorState = false;
const int flowPin = 2;

//unsigned long pulsecount=0;
//const float pulsesperlitre=450.0;
const float minflowrate=1.0;
const float maxflowrate=30.0;

unsigned long dailyStartTime = 0; 
float dailyTotalLiters = 0.0;
void setup() {
  Serial.begin(9600);
  pinMode(flowPin, INPUT);
}
void printDate()
{
  Serial.println();
  String currentdate=__DATE__;
  Serial.print(currentdate);
  Serial.print(";");
}
void printTime(unsigned long timeValue) {
 int seconds = timeValue / 1000;
  int hours = seconds / 3600;
  seconds %= 3600;
  int minutes = seconds / 60;
  seconds %= 60;

  if (hours < 10) Serial.print("0");
  Serial.print(hours);
  Serial.print(":");
  if (minutes < 10) Serial.print("0");
  Serial.print(minutes);
  Serial.print(":");
  if (seconds < 10) Serial.print("0");
  Serial.print(seconds);
  
}

void loop() {
  unsigned long pulseDuration = pulseIn(flowPin, HIGH);
  
  if (pulseDuration > 0) {
    if (!sensorState) {
      sensorState = true;
      printDate();
      Serial.print("ON ;");
      onTime = millis();
      printTime(onTime);
      offTime = 0;  
    } 
  }
  else {
    if (sensorState && offTime == 0) {
      sensorState = false;
      printDate();
      Serial.print("OFF ;");
      offTime = millis();
    }
    if(!sensorState && offTime > 0 )
    {
      printTime(offTime);
      float totalontime = (offTime - onTime)/1000.0;
      Serial.print("  ;  on dration: ");
      printTime(totalontime * 1000);
      onTime=0;
      offTime=0;

      float amtofwater = (totalontime/60.0) * max(minflowrate , min(maxflowrate, (maxflowrate * pulseDuration / 1000.0)));
      Serial.print("  ;  amount of water (L): ");
      Serial.print(amtofwater , 3);
      unsigned long currentMillis = millis();

      if (currentMillis - dailyStartTime >= 24 * 60 * 60 * 1000) {
        dailyTotalLiters = 0.0;
        dailyStartTime = currentMillis;
      }

      dailyTotalLiters += amtofwater; 
    }
  }
 
  delay(5000); 
    if (millis() - dailyStartTime >= 24 * 60 * 60 * 1000)
     {
    Serial.print("\nDaily Total (24 Hours): ");
    Serial.print(dailyTotalLiters, 3);
    Serial.println(" L");
     }
     delay(5000);
} 



