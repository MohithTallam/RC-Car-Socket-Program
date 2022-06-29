#include <string.h>
#include"WiFi.h"
#define motor1Pin1 12
#define motor1Pin2 13
#define motor2Pin1 33
#define motor2Pin2 32
#define enable2 25


WiFiServer server(8888);

String indata, outdata ,h, t, f;
int red, green, blue;
void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2, OUTPUT);

  // put your setup code here, to run once:
  // put your main code here, to run repeatedly:
  Serial.begin(115200); 
  WiFi.mode(WIFI_STA);
  WiFi.begin("Mohith","0908070605");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }
  Serial.print("Connected. IP address: ");
  Serial.println(WiFi.localIP());
  String IP = String(WiFi.localIP());
  Serial.println(IP);
  server.begin();

  delay(100);

}

void loop() {
  
  WiFiClient client = server.available();

  if (client) {
    if(client.connected()) {
      Serial.println("Client Connected");
    }
    
    while(client.connected()) {  
      delay(50);    
      while(client.available()>0) { 
        indata = char(client.read());
      }
      
      red = indata.toInt();
      
      Serial.println(indata);
      if(indata=="B")
        {digitalWrite(motor1Pin1, LOW);
         digitalWrite(motor1Pin2, HIGH); 
         digitalWrite(motor2Pin1, HIGH);
         digitalWrite(motor2Pin2, LOW); 

         
         delay(2000);
         Serial.println("Back");
         }
        
      
      if(indata=="F")
        {digitalWrite(motor1Pin1, HIGH);
         digitalWrite(motor1Pin2, LOW); 
         digitalWrite(motor2Pin1, LOW);
         digitalWrite(motor2Pin2, HIGH); 
         delay(2000);
         Serial.println("Forward");
         }
      if(indata=="R")
        {digitalWrite(motor1Pin1, LOW);
         digitalWrite(motor1Pin2, HIGH); 
         digitalWrite(motor2Pin1, LOW);
         digitalWrite(motor2Pin2, HIGH); 
         delay(2000);
         Serial.println("RIGHT");
         }
         
      delay(100);
}
}
}
