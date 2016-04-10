#include <dht11.h>

dht11 DHT11;
int tc = 0;

#define DHT11PIN_1 2  //DHT11 sensor 1

#define FANPIN_1 8  //Fan 1 relay pin
#define FANPIN_2 9  //Fan 2 relay pin

boolean fan1 = LOW;
boolean fan2 = HIGH;

void setup()
{
  Serial.begin(9600);
  Serial.println("ROBOFRESH V0.1");
  
  pinMode(FANPIN_1, OUTPUT);
  pinMode(FANPIN_2, OUTPUT);
}

void loop()
{
  //Show sensors status every 2 seconds
  if(!(tc % 5)) {
    showDhtSensor(DHT11PIN_1, 1);
  }
  
  //Every 
  if(!(tc % 30)) {
    fan1 = !fan1;
    setFan(1, FANPIN_1, fan1);
    fan2 = !fan2;
    setFan(2, FANPIN_2, fan2);
  }
  tc++;
  delay(1000);

}

void setFan(int id, int pin, int value) {
  digitalWrite(pin, value);
  Serial.print("#FAN:");
  Serial.print(id);
  Serial.print(":");
  Serial.print(value);
  Serial.println("~");
}

void showDhtSensor(int dhtPin, int id) {
  int chk = DHT11.read(dhtPin);
  
  if(chk != DHTLIB_OK) {
    Serial.print("DHT11 reading: ");
    switch (chk)
    {
      case DHTLIB_ERROR_CHECKSUM: 
  		Serial.println("Checksum error"); 
  		break;
      case DHTLIB_ERROR_TIMEOUT: 
  		Serial.println("Time out error"); 
  		break;
      default: 
  		Serial.println("Unknown error"); 
  		break;
    }
  } else {
    Serial.print("#HUM:");
    Serial.print(id);
    Serial.print(":");
    Serial.print((float)DHT11.humidity, 2);
    Serial.println("~");
  
    Serial.print("#TEMP:");
    Serial.print(id);
    Serial.print(":");
    Serial.print((float)DHT11.temperature, 2);
    Serial.println("~");
  }
}
