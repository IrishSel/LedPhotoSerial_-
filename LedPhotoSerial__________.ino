#define led_pin 3
#define sensor_pin A0
int convertValue;
int photocellReading; 

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);

}

void loop() {
  
  if (Serial.available() > 0){
    char message = Serial.read();
    if (message == 'u'){
      digitalWrite(led_pin, HIGH); // включает светодиод
    } 
    else if (message == 'd'){
      digitalWrite(led_pin, LOW); //выключает светодиод
    }
    else if (message == 'f'){
      photocellReading = analogRead(sensor_pin);
      Serial.print("Analog reading = ");
      Serial.println(photocellReading); // показывает данные освещенности
    }
    else if (message == 'c'){
      while (true){
        convertValue = analogRead(sensor_pin);
        analogWrite(led_pin, map(convertValue, 0, 255, 100, 1023)); // меняет яркость в зависимости от освещения
      }
    }
    else if (message == 'e'){
      if (analogRead(sensor_pin) < 1000) digitalWrite(led_pin, HIGH);
      else digitalWrite(led_pin, LOW); // должен вкл диод при темноте и выкл при свете
    }
    else{
      Serial.println("Unknow message");
    }
  }

}
