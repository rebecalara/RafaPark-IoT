import { io } from "socket.io-client";

const socket = io("http://172.20.10.10:3001", {
  transports: ["websocket"],  //força usar WebSocket (mais estável)
  reconnection: true,         //tenta reconectar caso caia
  reconnectionAttempts: 5,    //tenta 5 vezes
  reconnectionDelay: 1000,    //espera 1s entre as tentativas
});

//logs úteis
socket.on("connect", () => {
  console.log("Socket conectado:", socket.id);
});

socket.on("disconnect", () => {
  console.log("Socket desconectado.");
});

export default socket;