const express = require("express");
const cors = require("cors");
const http = require("http");
const { Server } = require("socket.io");

//Importa módulo MQTT
const mqttClient = require("./mqtt");

//Estado local das vagas
let vagas = [
  { id_vaga: 1, ocupada: false },
  { id_vaga: 2, ocupada: false },
  { id_vaga: 3, ocupada: false }
];

const app = express();
app.use(cors());

const server = http.createServer(app);

const io = new Server(server, {
  cors: {
    origin: "*",
  }
});

io.on("connection", (socket) => {
  console.log("Cliente conectado ao dashboard:", socket.id);

  //Envia as vagas iniciais
  socket.emit("update_vagas", vagas);
});

//Recebe atualização do mqtt.js
mqttClient.on("vaga_update", (data) => {
  console.log("Dados MQTT recebidos:", data);

  //Atualiza a vaga no array
  const index = vagas.findIndex(v => v.id_vaga === data.id_vaga);
  if (index !== -1) {
    vagas[index].ocupada = data.ocupada;
  }

  //Envia para o dashboard
  io.emit("update_vagas", vagas);
});

server.listen(3001, "0.0.0.0", () => {
  console.log("Backend rodando na rede em http://0.0.0.0:3001");
});