# RafaPark IoT — Backend

Este diretório contém o **backend** do projeto **RafaPark IoT**.

O backend é responsável por **receber os dados enviados pela ESP32**, processá-los e **disponibilizá-los em tempo real** para o dashboard web.

---

## Função do Backend

O backend atua como o **intermediário central do sistema**, conectando:

- **ESP32 (Arduino)** — envio de dados via MQTT
- **Frontend (Dashboard)** — recebimento de dados via Socket

Fluxo simplificado:

ESP32 → MQTT → Backend → Socket → Frontend

---

## Tecnologias Utilizadas

- Node.js  
- Express  
- MQTT  
- Socket (comunicação em tempo real)

---

## Como Executar o Backend

1. Acesse o diretório:
   cd backend

2. Instale as dependências:
   npm install

3. Execute o servidor:
   npm run dev  
   ou  
   node server.js

---

## Comunicação com a ESP32

- A ESP32 envia os dados dos sensores utilizando **MQTT**
- O arquivo `mqtt.js` é responsável por:
  - Conectar ao broker MQTT
  - Escutar mensagens
  - Repassar os dados recebidos ao servidor

---

## Comunicação com o Frontend

- O backend envia os dados processados via **Socket**
- O frontend recebe essas informações em tempo real
- O dashboard é atualizado automaticamente

---

## Acesso na Rede Local

O backend escuta conexões externas utilizando `0.0.0.0`, permitindo que o dashboard seja acessado por outros dispositivos na mesma rede.