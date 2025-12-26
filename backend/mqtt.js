const mqtt = require("mqtt");
const { EventEmitter } = require("events");

const emitter = new EventEmitter();

//CONECTA AO BROKER
const client = mqtt.connect("mqtt://test.mosquitto.org");

//Quando conectar:
client.on("connect", () => {
  console.log("📡 Conectado ao MQTT");

  //Assina tópico onde ESP32 publica
  client.subscribe("rafapark/vaga1");
  client.subscribe("rafapark/vaga2");
  client.subscribe("rafapark/vaga3");
});

//Quando recebe dados:
client.on("message", (topic, message) => {
  const valor = message.toString();

  const id_vaga = parseInt(topic.replace("rafapark/vaga", ""));
  const ocupada = valor === "1"; //ESP32 manda "1" ou "0"?

  emitter.emit("vaga_update", {
    id_vaga,
    ocupada
  });
});

module.exports = emitter;