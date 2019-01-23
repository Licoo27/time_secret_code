unsigned long compteur = 0;
unsigned long timer;
bool code[4];
int index=0;
void setup()
{
  // put your setup code here, to run once:
  pinMode(9, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  timer = millis();
  code[0] = false;
  code[1] = true;
  code[2] = false;
  code[3] = true;
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (digitalRead(9) == HIGH)
  {
    if(compteur == 0)
    {
      timer = millis();
    }
    unsigned long dt = millis() - timer + 1;
    timer = millis();
    compteur += dt;
  }
  
  if (digitalRead(9) == LOW)
  { 
     if(compteur != 0)
     {
      //Serial.println(compteur);
      if(compteur < 50000)
      {
        Serial.println("tic");

        if(code[index]==false)
        {
          index ++;
        }
        else
        {
          index = 0;
        }
      }
      else
      {
        Serial.println("TIC");
        if(code[index]==true)
        {
          index ++;
        }
        else
        {
          index = 0;
        }
      }
      compteur = 0;
      Serial.println(index);
     }
      
  }
  
  if (index ==4) 
  {
    digitalWrite(3, HIGH);
    delay(1000);
    index=0;
    digitalWrite(3, LOW);
    delay(15);  
  }
}
