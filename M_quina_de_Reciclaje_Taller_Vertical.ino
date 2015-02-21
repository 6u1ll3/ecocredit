#define Pecho 6
#define Ptrig 7
long duracion, distancia;   
int pulsos_metal, pulsos_PET, s = 0;
boolean sensor_metal, sensor_PET;
 
void setup() {                
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(13, 1);            // Define el pin 13 como salida
  }
  
void loop() {
  
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros

   if (distancia <= 5 && distancia >= 1){
    s++; 
    digitalWrite(3,1);       // en alto el pin 13 si la distancia es menor a 10cm
    delay(3000);
  }
  
  sensor_metal = digitalRead(2);
  
  if (sensor_metal == true)
  {
   s++;
   digitalWrite(3,1);
   delay(1000);
  }
  
  if (s == 5)
  {
   digitalWrite(13,1);
   delay(3000);
   s = 0; 
  }
}
