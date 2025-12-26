# RafaPark IoT 🚗

Protótipo de **estacionamento inteligente** desenvolvido para a disciplina de **Engenharia de Software – IoT**.  
O sistema utiliza um **ESP32** conectado a **sensores ultrassônicos** para detectar a presença de veículos em mini-vagas, com **LEDs indicadores** e envio das informações para um **dashboard web em tempo real**, acessível via navegador (desktop ou celular).

O projeto simula o funcionamento de um estacionamento inteligente, integrando **hardware, software e comunicação em rede**, com foco em aprendizado prático e arquitetura IoT.

---

## Objetivo do Projeto

- Monitorar vagas de estacionamento automaticamente  
- Indicar visualmente o estado das vagas (livre/ocupada)  
- Disponibilizar as informações em tempo real através de um dashboard  
- Aplicar conceitos de **IoT**, **redes**, **backend**, **frontend** e **integração de sistemas**

---

## Arquitetura do Sistema

O projeto segue uma **arquitetura em camadas**, típica de soluções IoT:

1. **Camada Física (Hardware)**  
   - ESP32  
   - Sensores ultrassônicos  
   - LEDs e resistores  

2. **Camada de Comunicação e Controle**  
   - ESP32 conectado via Wi-Fi  
   - Comunicação MQTT para envio dos dados  

3. **Camada de Aplicação**  
   - Backend Node.js  
   - Dashboard Web (React)  
   - Atualizações em tempo real via Socket.IO  

Fluxo simplificado de dados:

ESP32 → MQTT → Backend → Socket → Dashboard Web

---

## Tecnologias Utilizadas

### Hardware
- ESP32 Wi-Fi + Bluetooth  
- Sensores Ultrassônicos HC-SR04  
- LEDs (verde, vermelho e azul)  
- Resistores  
- Protoboard e jumpers  

### Software
- Arduino IDE  
- Node.js  
- Express  
- MQTT  
- Socket.IO  
- React  
- Vite  
- JavaScript  
- HTML e CSS  

---

## Componentes Utilizados

- **1x ESP32 Wi-Fi + Bluetooth**  
- **3x Sensores Ultrassônicos HC-SR04**  
- **2x LEDs Verdes 5mm**  
- **1x LED Azul 5mm**  
- **3x LEDs Vermelhos 5mm**  
- **6x Resistores 1KΩ (1/4W)**  
- **Jumpers macho–macho, fêmea–fêmea e macho–fêmea**  
- **1x Cabo Micro USB**  
- **1x Protoboard**  
- **1x Módulo Fonte 5V / 3.3V para Protoboard (MB102)**  

---

## Funcionalidades

- Detecção automática da presença de veículos  
- Identificação de vagas livres e ocupadas  
- Sinalização visual por LEDs  
- Envio de dados via Wi-Fi  
- Atualização em tempo real no dashboard  
- Acesso ao dashboard por computador ou celular (rede local)

---

## Estrutura do Repositório

- `/arduino` → Códigos da ESP32 e sensores  
- `/backend` → Servidor Node.js, MQTT e Socket  
- `/dashboard-rafapark` → Frontend React (Dashboard)  

Cada diretório possui seu próprio **README** com instruções específicas.

---

## Finalidade do Projeto

Este projeto foi desenvolvido com fins **educacionais e experimentais**, priorizando:

- Aprendizado progressivo  
- Compreensão da integração entre hardware e software  
- Boas práticas de organização e documentação  
- Aplicação prática dos conceitos estudados em IoT e Engenharia de Software  

---

## Motivação e Origem do Projeto

O projeto **RafaPark IoT** foi inspirado por um incentivo pessoal, a partir da paixão do sobrinho da autora por carros.  
A ideia surgiu do desejo de unir esse interesse com tecnologia e educação, resultando em um protótipo de estacionamento inteligente aplicado aos conceitos de IoT.

Desde o início, a proposta incluiu a intenção de, ao final do desenvolvimento e da apresentação acadêmica, presentear o sobrinho com a maquete do estacionamento inteligente, reforçando o caráter educativo, prático e inspirador do projeto.

---

## Desenvolvido por

**Rebeca Lara de Souza**  
Curso de **Engenharia de Software**  
Centro Universitário Católica de Santa Catarina