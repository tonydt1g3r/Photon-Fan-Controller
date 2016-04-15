// A Spark function to parse the commands
int fan1(String command);
int fan2(String command);
int fan3(String command);

// We name pins 
int pin1 = D0; 
int pin2 = D1;
int light = D2;
int foff = D3;
int flow = D4;
int fmed = D5;
int fhigh = D6;


// This routine runs only once upon reset
void setup() 
{
  //Register Spark functions
  Spark.function("stfan1", fan1);  
  Spark.function("stfan2", fan2);
  Spark.function("stfan3", fan3);
  
  // Initialize output pins
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(foff, OUTPUT);
  pinMode(flow, OUTPUT);
  pinMode(fmed, OUTPUT);
  pinMode(fhigh, OUTPUT);

  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(light, LOW);
  digitalWrite(foff, LOW);
  digitalWrite(flow, LOW);
  digitalWrite(fmed, LOW);
  digitalWrite(fhigh, LOW);

  // take control of the LED
  RGB.control(true);
  
  // the following sets the RGB LED to light green:
  RGB.color(0, 0, 5);
}



// This routine loops forever 
void loop()
{
  // nothing here
}



//acts based on messages from spark cloud
int fan1(String command)
{
  if (command == "0") 
    {   
    digitalWrite(foff, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(foff, LOW);
    Particle.publish("Command 0");
    } 
  else if (command == "1")
    {               
    digitalWrite(flow, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(flow, LOW);    // Turn OFF the relay
    Particle.publish("Command 1");
    }
  else if (command == "2")
    {               
    digitalWrite(fmed, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(fmed, LOW);    // Turn OFF the relay
    Particle.publish("Command 2");
    }
  else if (command == "3")
    {               
    digitalWrite(fhigh, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(fhigh, LOW);    // Turn OFF the relay
    Particle.publish("Command 3");
    }
  else if (command == "4")
    {               
    digitalWrite(light, LOW);   // Turn ON the relay
    delay(500);
    digitalWrite(light, LOW);
    Particle.publish("Command 4");
    }
}

int fan2(String command)
{
  digitalWrite(pin1, HIGH); 
  delay(500);
  if (command == "0") 
    {   
    digitalWrite(foff, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(foff, LOW);
    digitalWrite(pin1, LOW);
    } 
  else if (command == "1")
    {               
    digitalWrite(flow, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(flow, LOW);    // Turn OFF the relay
    digitalWrite(pin1, LOW);
    }
  else if (command == "2")
    {               
    digitalWrite(fmed, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(fmed, LOW);    // Turn OFF the relay
    digitalWrite(pin1, LOW);
    }
  else if (command == "3")
    {               
    digitalWrite(fhigh, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(fhigh, LOW);    // Turn OFF the relay
    digitalWrite(pin1, LOW);
    }
  else if (command == "4")
    {               
    digitalWrite(light, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(light, LOW);
    Particle.publish("Command 4");
    }
}

int fan3(String command)
{
  digitalWrite(pin2, HIGH); 
  delay(500);
  if (command == "0") 
    {   
    digitalWrite(foff, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(foff, LOW);
    digitalWrite(pin2, LOW);
    } 
  else if (command == "1")
    {               
    digitalWrite(flow, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(flow, LOW);    // Turn OFF the relay
    digitalWrite(pin2, LOW);
    }
  else if (command == "2")
    {               
    digitalWrite(fmed, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(fmed, LOW);    // Turn OFF the relay
    digitalWrite(pin2, LOW);
    }
  else if (command == "3")
    {               
    digitalWrite(fhigh, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(fhigh, LOW);    // Turn OFF the relay
    digitalWrite(pin2, LOW);
    }
  else if (command == "4")
    {               
    digitalWrite(light, HIGH);   // Turn ON the relay
    delay(500);
    digitalWrite(light, LOW);
    Particle.publish("Command 4");
    }
}
