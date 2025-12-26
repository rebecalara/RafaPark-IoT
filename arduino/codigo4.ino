//---Codigo 4: 3 sensores com 2 leds cada---//



//------------ SENSOR 1 ------------------
const int TRIG1 = 4;
const int ECHO1 = 2;
const int LED_VERMELHO1 = 5;
const int LED_AZUL   = 18;

//------------ SENSOR 2 ------------------
const int TRIG2 = 21;
const int ECHO2 = 19;
const int LED_VERMELHO2 = 22;
const int LED_VERDE1   = 23;

//------------ SENSOR 3 ------------------
const int TRIG3 = 25;
const int ECHO3 = 26;
const int LED_VERMELHO3 = 27;
const int LED_VERDE2   = 14;

void setup() {
  Serial.begin(9600);

  //Sensor 1
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(LED_VERMELHO1, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);

  //Sensor 2
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(LED_VERMELHO2, OUTPUT);
  pinMode(LED_VERDE1, OUTPUT);

  //Sensor 3
  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);
  pinMode(LED_VERMELHO3, OUTPUT);
  pinMode(LED_VERDE2, OUTPUT);
}

float medirDistancia(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duracao = pulseIn(echo, HIGH);
  float distancia = (duracao * 0.0343) / 2;
  return distancia;
}

void loop() {
  //---- Sensor 1 ----
  float dist1 = medirDistancia(TRIG1, ECHO1);

  Serial.print("Sensor 1: ");
  Serial.print(dist1);
  Serial.println(" cm");

  if (dist1 <= 10 && dist1 > 0) {
    digitalWrite(LED_VERMELHO1, HIGH);
    digitalWrite(LED_AZUL, LOW);
  } else {
    digitalWrite(LED_VERMELHO1, LOW);
    digitalWrite(LED_AZUL, HIGH);
  }

  //---- Sensor 2 ----
  float dist2 = medirDistancia(TRIG2, ECHO2);

  Serial.print("Sensor 2: ");
  Serial.print(dist2);
  Serial.println(" cm");

  if (dist2 <= 10 && dist2 > 0) {
    digitalWrite(LED_VERMELHO2, HIGH);
    digitalWrite(LED_VERDE1, LOW);
  } else {
    digitalWrite(LED_VERMELHO2, LOW);
    digitalWrite(LED_VERDE1, HIGH);
  }

  //---- Sensor 3 ----
  float dist3 = medirDistancia(TRIG3, ECHO3);

  Serial.print("Sensor 3: ");
  Serial.print(dist3);
  Serial.println(" cm");

  if (dist3 <= 10 && dist3 > 0) {
    digitalWrite(LED_VERMELHO3, HIGH);
    digitalWrite(LED_VERDE2, LOW);
  } else {
    digitalWrite(LED_VERMELHO3, LOW);
    digitalWrite(LED_VERDE2, HIGH);
  }

  Serial.println("---------------------");
  delay(500);
}