#include<LiquidCrystal.h>
LiquidCrystal lcd(9,8,7,6,5,4);

String carddata[2]={"070010F86D82","070010CE61B8"};
String user_name[2]={"Mahidhar B","Nagaraju B"};
String user_number[2]={"9966985773","8885212218"};

String last_user_data=" ";

void setup() 
{
Serial.begin(9600);
lcd.begin(16,2);
lcd.print("Welcome");
lcd.print("our project");
}

void loop() {
if(Serial.available()>0)
{
  String str=Serial.readString();
  if(last_user_data!=str)
    {
      for(int a=0;a<2;a++)
        {
        if(carddata[a]==str)
          {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print(user_name[a]);
            lcd.setCursor(0,1);
            lcd.print(user_number[a]);
            last_user_data=str;
            break;
            delay(10000);
            lcd.clear();
          }
        }
    lcd.setCursor(0,0);
    lcd.print("waiting for card");
   }
  }
}
