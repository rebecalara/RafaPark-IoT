//---Codigo 7: atualização do codigo 6 com 3 sensores---//
#include <WiFi.h>
#include <PubSubClient.h>
#include <WebServer.h>*/

//----------- WIFI ------------
const char* ssid = "UAI-FAI";
const char* password = "posi0586";

//----------- MQTT ------------
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);

//----------- WEB SERVER -----------
WebServer server(80);

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


//------ funções ----------
void setup_wifi() {
  Serial.println();
  Serial.print("Conectando ao WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println(" ");
  Serial.println("WiFi conectado!");
  Serial.print("IP da ESP32: ");
  Serial.println(WiFi.localIP());
}

//---------- Página Web ----------
void handleRoot() {
  String html = "<html><body>";
  html += "<h1>RafaPark Dashboard</h1>";
  html += "<p>MQTT Status: " + String(client.connected() ? "CONECTADO" : "DESCONECTADO") + "</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT... ");
    if (client.connect("RafaParkESP32")) {
      Serial.println("Conectado!");
    } else {
      Serial.print("Falhou (");
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

  server.on("/", handleRoot);
  server.begin();

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

//---------- LOOP ----------
void loop() {
  server.handleClient();

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  //---- Sensor 1 ----
  float dist1 = medirDistancia(TRIG1, ECHO1);
  bool vaga1 = (dist1 <= 10 && dist1 > 0);

  Serial.print("Sensor 1: ");
  Serial.print(dist1);
  Serial.println(" cm");

  digitalWrite(LED_VERMELHO1, vaga1 ? HIGH : LOW);
  digitalWrite(LED_AZUL, vaga1 ? LOW : HIGH);

  client.publish("rafapark/vaga1", vaga1 ? "1" : "0");

  //---- Sensor 2 ----
  float dist2 = medirDistancia(TRIG2, ECHO2);
  bool vaga2 = (dist2 <= 10 && dist2 > 0);

  Serial.print("Sensor 2: ");
  Serial.print(dist2);
  Serial.println(" cm");

  digitalWrite(LED_VERMELHO2, vaga2 ? HIGH : LOW);
  digitalWrite(LED_VERDE1, vaga2 ? LOW : HIGH);

  client.publish("rafapark/vaga2", vaga2 ? "1" : "0");

  //---- Sensor 3 ----
  float dist3 = medirDistancia(TRIG3, ECHO3);
  bool vaga3 = (dist3 <= 10 && dist3 > 0);

  Serial.print("Sensor 3: ");
  Serial.print(dist3);
  Serial.println(" cm");

  digitalWrite(LED_VERMELHO3, vaga3 ? HIGH : LOW);
  digitalWrite(LED_VERDE2, vaga3 ? LOW : HIGH);

  client.publish("rafapark/vaga3", vaga3 ? "1" : "0");

  Serial.println("---------------------");
  delay(300);
}