#define REMOTEXY_MODE__ESP8266_HARDSERIAL_CLOUD
#include <RemoteXY.h>
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "mahidhar"
#define REMOTEXY_WIFI_PASSWORD "123456789"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "16774b7c8eea670926ca20529973fa2a"

#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,1,0,0,0,26,0,8,31,1,
  2,1,7,33,52,22,6,24,31,31,
  70,69,69,68,73,78,71,0,70,69,
  69,68,0 };
struct {
  uint8_t FEED;
  uint8_t connect_flag;
} RemoteXY;
#pragma pack(pop)
#include <Servo.h>
Servo servo; 
int pos = 0; 
int s=7;
void setup() 
{
  RemoteXY_Init ();
  pinMode(s,INPUT);  
}

void loop() 
{ 
  int pir=0;
  pir=digitalRead(s);
  RemoteXY_Handler (); 
  if(RemoteXY.FEED==1 ||pir==HIGH)
  {      servo.attach(9);
   if(pos<120){
       for (pos = 20; pos <120; pos += 1) { 
            servo.write(pos);
             delay(30);   
       }
       }
       else 
         servo.write(120);                              
  }
  else{
  for ( ; pos >= 20; pos -= 1) {
    servo.write(pos);
     delay(30); 
    }
   servo.detach();
}
}
