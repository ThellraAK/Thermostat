

void setColor(int red, int green, int blue)
{
//The -255 is because the LED is common ANODE
//AKA they all share the +5V side
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  analogWrite(9, red);
  analogWrite(6, green);
  analogWrite(5, blue);  
}

void Indigo()
{
   setColor(0x4B, 0x0, 0x82);  // indigo
}

void Black(){
  setColor(0, 0, 0); // #000000
}
void White(){
  setColor(255, 255, 255);// #FFFFFF
}
void Red(){
  setColor(255, 0, 0);// #FF0000
}
void Green(){
  setColor(0, 255, 0);// #00FF00
}
void Blue(){
  setColor(0, 0, 255); //#0000FF
}
void Yellow(){
  setColor(255, 255, 0);// #FFFF00
}
void Cyan(){
  setColor(0, 255, 255); //#00FFFF
}
void Magenta(){
  setColor(255, 0, 255);  //#FF00FF
}
void Pink(){
  setColor(0xff,0x69, 0xb4);
}



