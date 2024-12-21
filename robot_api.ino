// Definisikan pin untuk motor
 int enablePinA = 3;  
 int motorPin1 = 5;  
 int motorPin2 = 6;   
 int motorPin3 = 9;  
 int motorPin4 = 10;  
 int enablePinB = 11;  
 int trigPinDepan = 12;  
 int echoPinDepan = 13;  
 int trigPinKiri = 7;  
 int echoPinKiri = 8;   

const int buttonPinKiri = A5;     // the number of the pushbutton pin
const int buttonPinSerongKiri = A4;
const int buttonPinDepan = A3;
const int buttonPinSerongKanan = A2;
const int buttonPinKanan = A1;

// variables will change:
int buttonStateKiri= 0;
int buttonStateSerongKiri= 0;
int buttonStateDepan= 0;
int buttonStateSerongKanan= 0;
int buttonStateKanan= 0; 


long duration;
int distance;


void setup() {
  // Inisialisasi pin
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(enablePinA, OUTPUT);
  pinMode(enablePinB, OUTPUT);
  pinMode(trigPinDepan, OUTPUT);
  pinMode(echoPinDepan, INPUT);
  pinMode(trigPinKiri, OUTPUT);
  pinMode(echoPinKiri, INPUT);

  pinMode(buttonPinKiri, INPUT_PULLUP);
  pinMode(buttonPinSerongKiri, INPUT_PULLUP);
  pinMode(buttonPinDepan, INPUT_PULLUP);
  pinMode(buttonPinSerongKanan, INPUT_PULLUP);
  pinMode(buttonPinKanan, INPUT_PULLUP);
  
  Serial.begin(9600); // Untuk debugging
}

void loop() {

  buttonStateKiri = digitalRead(buttonPinKiri);
  buttonStateSerongKiri = digitalRead(buttonPinSerongKiri);
  buttonStateDepan = digitalRead(buttonPinDepan);
  buttonStateSerongKanan = digitalRead(buttonPinSerongKanan);
  buttonStateKanan = digitalRead(buttonPinKanan);

  // Menghitung jarak dengan sensor kiri
  long durationKiri, distanceKiri;

  // Mengatur trigPin kiri
  digitalWrite(trigPinKiri, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinKiri, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinKiri, LOW);
  
  // Membaca echoPin kiri
  durationKiri = pulseIn(echoPinKiri, HIGH);
  distanceKiri = (durationKiri * 0.034) / 2; // Menghitung jarak dalam cm


     // Menghitung jarak dengan sensor Depan
  long durationDepan, distanceDepan;

  // Mengatur trigPin Depan
  digitalWrite(trigPinDepan, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinDepan, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinDepan, LOW);
  
  // Membaca echoPin Depan
  durationDepan = pulseIn(echoPinDepan, HIGH);
  distanceDepan = (durationDepan * 0.034) / 2; // Menghitung jarak dalam cm


  // Mencetak jarak ke serial monitor
  Serial.println("*k" + String(distanceKiri) + "*");

  // Mencetak jarak ke serial monitor
  Serial.println("*d" + String(distanceDepan) + "*");




  // // Logika pengendalian motor 
  if(distanceDepan<10 && buttonStateDepan == HIGH)

  {
   berhenti();
  

  } 
  
  // else if (distanceKiri <10 && distanceDepan <= 10) 
  // {
   
  //   geserkanan();
    
  // }
  // else if (distanceKiri >10 && distanceKiri <= 20) 
  // {
   
  //   maju();
    
  // }
   else if (distanceKiri > 50)
    {

    
  
  }
  delay(50);



//sensor flame

  if (buttonStateKiri == HIGH)
  {
   Serial.println("*fKiri Ada Api*");
   geserkiri();
   delay(10);

  } 


  else if (buttonStateSerongKiri == HIGH)
  {
    Serial.println("*fSerong Kiri Ada Api*");
    geserkiri();

    delay(10);
  }

  else if (buttonStateDepan == HIGH && buttonStateSerongKiri == HIGH) 
  {
    Serial.println("*fDepan Ada Api*");
    maju();
    delay(10);
    

  }


  else if (buttonStateDepan == HIGH) 
  {
    Serial.println("*fDepan Ada Api*");
    maju();
    delay(10);
    

    
  }

  else if (buttonStateDepan == HIGH && buttonStateSerongKiri == HIGH && buttonStateSerongKanan) 
  {
    Serial.println("*fDepan Ada Api*");
    maju();
    delay(10);
    

    
  }



  else if (buttonStateSerongKanan == HIGH) 
  {
    Serial.println("*fSerong Kanan Ada Api*");
    geserkanan();
    delay(10);
  }

  else if (buttonStateDepan == HIGH && buttonStateSerongKanan) 
  {
    Serial.println("*fDepan Ada Api*");
    maju();
    delay(10);
    

    
  }



  else if (buttonStateKanan == HIGH) 
  {
    Serial.println("*fKanan Ada Api*");
    geserkanan();
    delay(10);
  }

  else
  {
    Serial.println("*fTidak Ada Api*");
    belokkiri();
    delay(10);
  }



  // Debugging
  Serial.print("Jarak Sensor Kiri: ");
  Serial.println(distanceKiri);
  
    // Debugging
  Serial.print("Jarak Sensor Depan: ");
  Serial.println(distanceDepan);

}


// Fungsi untuk menggerakkan motor maju
void maju() {
  Serial.println("*imaju*");
  digitalWrite(motorPin1, HIGH); //lurus
  digitalWrite(motorPin2, LOW); //lurus
  digitalWrite(motorPin3, HIGH); //lurus
  digitalWrite(motorPin4, LOW);  //lurus
  analogWrite(enablePinA, 100); //lurus
  analogWrite(enablePinB, 100); //lurus

}

void majupelan() {
  Serial.println("*imajupelan*");
  digitalWrite(motorPin1, HIGH); //lurus
  digitalWrite(motorPin2, LOW); //lurus
  digitalWrite(motorPin3, HIGH); //lurus
  digitalWrite(motorPin4, LOW);  //lurus
  analogWrite(enablePinA, 150); //lurus
  analogWrite(enablePinB, 150); //lurus

}

void majutambahpelan() {
  Serial.println("*imajutambahpelan*");
  digitalWrite(motorPin1, HIGH); //lurus
  digitalWrite(motorPin2, LOW); //lurus
  digitalWrite(motorPin3, HIGH); //lurus
  digitalWrite(motorPin4, LOW);  //lurus
  analogWrite(enablePinA, 90); //lurus
  analogWrite(enablePinB, 90); //lurus

}




// Fungsi untuk bergeser ke kanan (maju)
void geserkanan() {
  Serial.println("*igeserkanan*");
  digitalWrite(motorPin1, HIGH);  
  digitalWrite(motorPin2, LOW);   
  digitalWrite(motorPin3, LOW);  
  digitalWrite(motorPin4, LOW);   
  analogWrite(enablePinA, 80);
  analogWrite(enablePinB, 90);
}


// Fungsi untuk bergeser ke kiri (maju)
void geserkiri() {
  Serial.println("*igeserkiri*");
  digitalWrite(motorPin1, LOW);  
  digitalWrite(motorPin2, LOW);   
  digitalWrite(motorPin3, HIGH);  
  digitalWrite(motorPin4, LOW);  
  analogWrite(enablePinA, 80);
  analogWrite(enablePinB, 90);
}

//Fungsi untuk belok ke kiri (maju)
void belokkiri() {
  Serial.println("*ibelokkiri*");
  digitalWrite(motorPin1, LOW);  
  digitalWrite(motorPin2, HIGH);   
  digitalWrite(motorPin3, HIGH);  
  digitalWrite(motorPin4, LOW);  
  analogWrite(enablePinA, 90);
  analogWrite(enablePinB, 90);
}

//Fungsi untuk belok ke kanan (maju)
void belokkanan() {
  Serial.println("*ibelokkanan*");
  digitalWrite(motorPin1, HIGH);  
  digitalWrite(motorPin2, LOW);   
  digitalWrite(motorPin3, LOW);  
  digitalWrite(motorPin4, HIGH);  
  analogWrite(enablePinA, 105);
  analogWrite(enablePinB, 220);
}

// Fungsi untuk berhenti
void berhenti() {
  Serial.println("*iberhenti*");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  analogWrite(enablePinA, 0);
  analogWrite(enablePinB, 0);

}

// Fungsi untuk mundur
void mundur() {
  Serial.println("*imundur*");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  analogWrite(enablePinA, 80);
  analogWrite(enablePinB, 120);

}

void kirimajupelan() {
  Serial.println("*ikirimajupelan*");
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  analogWrite(enablePinA, 80);
  analogWrite(enablePinB, 120);

}
