# RafaPark IoT — Dashboard (Frontend)

Este diretório contém o **frontend** do projeto **RafaPark IoT**, responsável por exibir visualmente o estado do estacionamento em tempo real.

O dashboard consome os dados enviados pelo backend e apresenta as informações de forma clara e intuitiva.

---

## Função do Frontend

O frontend é a **interface do usuário**, onde é possível visualizar:

- Vagas livres e ocupadas  
- Status geral do estacionamento  
- Atualizações em tempo real  

O frontend **não se comunica diretamente com a ESP32**.

---

## Tecnologias Utilizadas

- React  
- Vite  
- JavaScript  
- CSS  
- Socket (comunicação em tempo real)

---

## Como Executar o Frontend

1. Acesse o diretório:
   cd dashboard-rafapark

2. Instale as dependências:
   npm install

3. Inicie o servidor de desenvolvimento:
   npm run dev

4. Acesse no navegador:
   http://localhost:5173

---

## Comunicação com o Backend

- A comunicação ocorre via **Socket**
- O arquivo `services/socket.js`:
  - Estabelece a conexão com o backend
  - Recebe dados em tempo real
  - Atualiza os componentes automaticamente

---

# Acesso ao Dashboard pelo Celular (sem usar localhost)

O endereço `localhost` funciona **apenas na máquina onde o frontend está rodando**.  
Para acessar o dashboard pelo **celular**, é necessário utilizar o **IP local da máquina** onde o projeto está sendo executado.

---

## Pré-requisitos

- A máquina e o celular **devem estar conectados na mesma rede Wi-Fi**
- O backend deve estar rodando (porta `3001`)
- O frontend deve estar rodando com Vite (porta `5173`)

---

## Como descobrir o IP da máquina

### Windows

1. Pressione `Windows + R`
2. Digite `cmd` e pressione Enter
3. No terminal, execute o comando:

```
ipconfig
```

4. Procure por **Endereço IPv4**, exemplo:

```
Endereço IPv4. . . . . . . . . . . : 192.168.0.105
```

Esse é o **IP local da máquina**.

---

## Como acessar o dashboard pelo celular

No navegador do celular (Chrome, Safari, etc.), digite:

```
http://MAQUINA_IP:5173
```

Exemplo:

```
http://192.168.0.105:5173
```

Após isso, o dashboard será carregado normalmente no celular.


## Comunicação em tempo real (Socket.IO)

O frontend se conecta ao backend utilizando **Socket.IO**, apontando diretamente para o IP local da máquina:

```js
import { io } from "socket.io-client";

const socket = io("http://MAQUINA_IP:3001", { //tera que alterar no código colocando o ip da máquina
  transports: ["websocket"],
  reconnection: true,
  reconnectionAttempts: 5,
  reconnectionDelay: 1000,
});

export default socket;
```

Essa configuração permite que o celular receba as atualizações das vagas em tempo real, sem utilizar `localhost`.

---

## Configuração necessária no Vite

Para permitir acesso externo ao frontend, é necessário liberar o host no Vite.

No arquivo `vite.config.js`, configure:

```js
export default {
  server: {
    host: true
  }
}
```