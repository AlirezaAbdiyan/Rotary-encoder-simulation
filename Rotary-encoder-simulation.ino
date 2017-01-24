#define pulseWidth  1 // millis

#define APin    3
#define BPin    4

boolean A_Array[4]={1,1,0,0};
boolean B_Array[4]={0,1,1,0};

void send_DataEncoder(unsigned long pulseCount,boolean Direction);

void setup() 
{
  pinMode(APin, OUTPUT);
  pinMode(BPin, OUTPUT);
  digitalWrite(APin, A_Array[0]); 
  digitalWrite(BPin, B_Array[0]);
}

void loop() 
{
  send_DataEncoder(500,1); 
  delay(1000); 
  send_DataEncoder(1500,0);  
  delay(1000);
}

void send_DataEncoder(unsigned long pulseCount,boolean Direction)
{
  unsigned long i;
  int static ArrayIndex=0;
  for(i=0;i<pulseCount;i++)
  {
    if(Direction)
    {
      ArrayIndex++;
      if(ArrayIndex>=4) ArrayIndex=0;
      digitalWrite(APin, A_Array[ArrayIndex]); 
      digitalWrite(BPin, B_Array[ArrayIndex]);     
    }
    else
    {
      ArrayIndex--;
      if(ArrayIndex<0) ArrayIndex=3;
      digitalWrite(APin, A_Array[ArrayIndex]); 
      digitalWrite(BPin, B_Array[ArrayIndex]);   
    }
    delay(pulseWidth/2);
  }
}
