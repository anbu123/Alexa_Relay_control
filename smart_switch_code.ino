#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <EEPROM.h>
const char *ssid = "XXXXXX";
const char *password = "XXXXXXX";
ESP8266WebServer server(80);
int ai;
char a,b,c,d;
String aa;
void handleRoot() 
{
}
void handleLedOn()
{
  response();
  ai=!digitalRead(16);
  aa=String(ai);
  a=aa[0];
  Serial.println(a);
  EEPROM.write(0,a);
  EEPROM.commit();
  if( a == '1')
  {
    digitalWrite(16,HIGH);
  }
  if( a == '0')
  {
    digitalWrite(16,LOW);
  }
}
void handleLedOn1()
{ 
    response();
  ai=!digitalRead(5);
  aa=String(ai);
  b=aa[0];
  Serial.println(b);
  EEPROM.write(1,b);
  EEPROM.commit();
  if( b == '1')
  {
    digitalWrite(5,HIGH);
  }
  if( b == '0')
  {
    digitalWrite(5,LOW);
  }
}
void handleLedOn2()
{
    response();
  ai=!digitalRead(4);
  aa=String(ai);
  c=aa[0];
  Serial.println(c);
  EEPROM.write(2,c);
  EEPROM.commit();
  if( c == '1')
  {
    digitalWrite(4,HIGH);
  }
  if( c == '0')
  {
    digitalWrite(4,LOW);
  }
}
void handleLedOn3()
{
  response();
  ai=!digitalRead(0);
  aa=String(ai);
  d=aa[0];
  Serial.println(d);
  EEPROM.write(3,d);
  EEPROM.commit();
  if( d == '1')
  {
    digitalWrite(0,HIGH);
  }
  if( d == '0')
  {
    digitalWrite(0,LOW);
  }
 }
void setup() 
{
    delay(500);
    Serial.begin(115200);
    EEPROM.begin(512);
    Serial.println();
    WiFi.softAP(ssid, password);
    IPAddress apip = WiFi.softAPIP();
    Serial.print("visit: \n");
    Serial.println(apip);
    server.on("/", handleRoot);
    server.on("/0", handleLedOn);
    server.on("/1", handleLedOn1);
    server.on("/2", handleLedOn2);
    server.on("/3", handleLedOn3);
    server.begin();
    Serial.println("HTTP server beginned");
    pinMode(16, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(0, OUTPUT);
    a=EEPROM.read(0);
    b=EEPROM.read(1);
    c=EEPROM.read(2);
    d=EEPROM.read(3);
    delay(100);
    Serial.println("1 value is");
    Serial.println(a);
    Serial.println("2 value is");
    Serial.println(b);
    Serial.println("3 value is");
    Serial.println(c);
    Serial.println("4 value is");
    Serial.println(d);
    if( a == '1')
    {
       digitalWrite(16,HIGH);
    }
    if( a == '0')
    {
      digitalWrite(16,LOW);
    }
    if( b == '1')
    {
      digitalWrite(5,HIGH);
    }
    if( b == '0')
    {
      digitalWrite(5,LOW);
    }
    if( c == '1')
    {
      digitalWrite(4,HIGH);
    }
    if( c == '0')
    {
      digitalWrite(4,LOW);
    }
    if( d == '1')
    {
      digitalWrite(0,HIGH);
    }
    if( d == '0')
    {
      digitalWrite(0,LOW);
    }
}
void loop() 
{
  server.handleClient();
}
void response()

{

  String a,b,c,d,e,f,g,h,i;

  String content;

  int statusCode;

  a=digitalRead(16);

  b=digitalRead(5);

  c=digitalRead(4);

  d=digitalRead(0);

  e=digitalRead(2);

  f=digitalRead(14);

  g=digitalRead(12);

  h=digitalRead(13);

  i=digitalRead(15);

  String total=a+b+c+d+e+f+g+h+i;

  Serial.println(total);

  content = "{\"value\": " + String(total) + "}";

  statusCode = 200;

  server.send(statusCode, "application/json", content);

}



