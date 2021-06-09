#include <DHT.h>
#include <DHT_U.h>

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino


//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value
int SoilMoisture = analogRead(0); //CONNECT TO PIN A0
int red_light_pin = 8; //CONNECT LED TO PIN 8
int blue_light_pin = 9; //CONNECT LED TO PIN 9
int green_light_pin = 10; //CONNECT LED TO PIN 10

void setup()
{
    Serial.begin(9600);
    dht.begin();
    pinMode(11, OUTPUT); //CONNECT BUZZER TO PIN 11
    pinMode(red_light_pin, OUTPUT); //CONNECT RED LED TO PIN 8
    pinMode(blue_light_pin, OUTPUT); //CONNECT GREEN LED TO PIN 9
    pinMode(green_light_pin, OUTPUT); // CONNECT BLUE LED TO PIN 10
    
}

/* Let's create a function to display and code for different combinations */

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

void loop()
{
                //Read data and store it to variables hum, temp & soil moisture
                
                int hum = dht.readHumidity();
                int temp= dht.readTemperature();
                int SoilMoisture;
                 
                //Print temp, humidity and soil moisture values to serial monitor
                Serial.print(" Temp: ");
                Serial.print(temp);
                Serial.print("\t");
                Serial.print(" Humidity: ");
                Serial.print(hum);
                Serial.print("\t");
                
                SoilMoisture = analogRead(0);//connect sensor to pin A0
                Serial.print(" Soil Moisture: ");
                Serial.print(SoilMoisture); //print the value to serial port
                Serial.print("\t");
            
            
                if (temp  > 25){
                  digitalWrite(11, HIGH);
                  delay(1000);
                  digitalWrite(11, LOW);
                  delay(500);
                  digitalWrite(11, HIGH);
                  delay(1000);
                  digitalWrite(11, LOW);
                  delay(500);
                  digitalWrite(11, HIGH);
                  delay(1000);
                  digitalWrite(11, LOW);
                  delay(500);
                  RGB_color(255, 0, 0); // Red LED turns on for 3 seconds
                  Serial.println("---It's too hot, turn off the heating & open the windows!---");
                  delay(3000);
            
                  
                    }
                    
                else if (temp < 17){
                  digitalWrite(11, HIGH);
                  delay(1000);
                  digitalWrite(11, LOW);
                  delay(500);
                  digitalWrite(11, HIGH);
                  delay(1000);
                  digitalWrite(11, LOW);
                  delay(500);
                  digitalWrite(11, HIGH);
                  delay(1000);
                  digitalWrite(11, LOW);
                  delay(500);
                  RGB_color(255, 255, 0); // Yellow LED turns on for 3 seconds
                  Serial.println("---It's too cold, turn on the heating & close the windows!---");
                  delay(3000);
                 
                  
                  }
            
                else {RGB_color(0, 255, 0); // Green LED turns on for 3 seconds
                     Serial.print("---The temperature is perfect!---");
                     delay(3000);
                     
                  }
             Serial.print("\t");
            
            if (SoilMoisture < 301){
                  digitalWrite(11, HIGH);
                  delay(2000);
                  digitalWrite(11, LOW);
                  delay(500);
                  digitalWrite(11, HIGH);
                  delay(1000);
                  digitalWrite(11, LOW);
                  delay(500);
                  digitalWrite(11, HIGH);
                  delay(2000);
                  digitalWrite(11, LOW);
                  delay(500);
                  RGB_color(255, 255, 255); // White LED turns on for 3 seconds
                  Serial.println("---The soil is dry! Time to water the crops---");
                  delay(3000);
                    }
                    
            
                else if (SoilMoisture > 701){
                  digitalWrite(11, HIGH);
                  delay(2000);
                  digitalWrite(11, LOW);
                  delay(500);
                  digitalWrite(11, HIGH);       
                  delay(1000);
                  digitalWrite(11, LOW);
                  delay(500);
                  digitalWrite(11, HIGH);
                  delay(2000);
                  digitalWrite(11, LOW);
                  delay(500);
                  RGB_color(0, 0, 255); // Blue LED turns on for 3 seconds
                  Serial.println("---The soil is way too wet! Time to close the taps---");
                  delay(3000);
                  
                  }

                  else {
                  RGB_color(0, 255, 255); // Cyan LED turns on for 3 seconds
                  Serial.println(" ---The soil is moist!---");
                  delay(3000);
                  
                  }
                  
      
 
    delay(3000); //Delay 10 sec.
}
