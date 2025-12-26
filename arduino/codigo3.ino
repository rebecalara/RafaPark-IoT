//---Codigo 3: sensor com 2 leds---//

//Um sensor
const int PINO_TRIG = 4;  //Pino D4 → TRIG
const int PINO_ECHO = 2;  //Pino D2 → ECHO

//Dois LEDs
const int LED_VERMELHO = 5; //LED vermelho no D5
const int LED_VERDE = 18;   //LED verde no D18 (ou outro pino disponível)

void setup() {
  Serial.begin(9600);

  pinMode(PINO_TRIG, OUTPUT);
  pinMode(PINO_ECHO, INPUT);

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}

void loop() {

  //Pulso do sensor
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);

  long duracao = pulseIn(PINO_ECHO, HIGH);
  float distancia = (duracao * 0.0343) / 2;

  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  //Lógica dos LEDs
  if (distancia <= 10 && distancia > 0) {
    // Perto → vermelho aceso
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_VERDE, LOW);
  } else {
    // Longe → verde aceso
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, HIGH);
  }

  delay(500);
}