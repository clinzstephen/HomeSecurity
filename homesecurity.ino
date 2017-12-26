#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,9);
char phone_no[]="+919497612985";


void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
   mySerial.begin(9600);
   delay(1000);
   pinMode(7,INPUT);
   digitalWrite(7,LOW);
   if(digitalRead(7)==HIGH)
   {
      Serial.println("intruders");
      mySerial.println("AT");     
      delay(1000);
      serialdata();
      mySerial.print("ATD");
      mySerial.print(phone_no);
      mySerial.println(";");
      delay(200000);
      mySerial.println("ATH"); 
   }
}
void serialdata()
{
   while(mySerial.available()!=0)
   {  Serial.write(mySerial.read());
   //Serial.println("hello world");
}
}
void loop() {
  // put your main code here, to run repeatedly:

}
