//---Codigo 5: conectando no wifi---//

#include <WiFi.h>
#include <PubSubClient.h>

//----------- WIFI ------------
const char* ssid = "TP-Link_A1AD";
const char* password = "85414471";

//----------- MQTT ------------
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);

//------------ SENSOR 1 ------------------
const int TRIG1 = 4;
const int ECHO1 = 2;
const int LED_VERMELHO1 = 5;
const int LED_VERDE1   = 18;

//------------ SENSOR 2 ------------------
const int TRIG2 = 21;
const int ECHO2 = 19;
const int LED_VERMELHO2 = 22;
const int LED_VERDE2   = 23;

//------ funções ----------
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando ao WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT... ");
    if (client.connect("RafaParkESP32")) {
      Serial.println("Conectado!");
    } else {
      Serial.print("falhou (");
      Serial.print(client.state());
      Serial.println("). Tentando de novo em 2s...");
      delay(2000);
    }
  }
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

//---------- SETUP ----------
void setup() {
  Serial.begin(9600);

  setup_wifi();
  client.setServer(mqtt_server, 1883);

  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(LED_VERMELHO1, OUTPUT);
  pinMode(LED_VERDE1, OUTPUT);

  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(LED_VERMELHO2, OUTPUT);
  pinMode(LED_VERDE2, OUTPUT);
}

//---------- LOOP ----------
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  //---- Sensor 1 ----
  float dist1 = medirDistancia(TRIG1, ECHO1);
  bool vaga1 = (dist1 <= 10 && dist1 > 0); // true = ocupada

  Serial.print("Sensor 1: ");
  Serial.print(dist1);
  Serial.println(" cm");

  digitalWrite(LED_VERMELHO1, vaga1 ? HIGH : LOW);
  digitalWrite(LED_VERDE1, vaga1 ? LOW : HIGH);

  // PUBLICA MQTT
  client.publish("rafapark/vaga1", vaga1 ? "1" : "0");

  //---- Sensor 2 ----
  float dist2 = medirDistancia(TRIG2, ECHO2);
  bool vaga2 = (dist2 <= 10 && dist2 > 0);

  Serial.print("Sensor 2: ");
  Serial.print(dist2);
  Serial.println(" cm");

  digitalWrite(LED_VERMELHO2, vaga2 ? HIGH : LOW);
  digitalWrite(LED_VERDE2, vaga2 ? LOW : HIGH);

  //PUBLICA MQTT
  client.publish("rafapark/vaga2", vaga2 ? "1" : "0");

  Serial.println("---------------------");
  delay(500);
}