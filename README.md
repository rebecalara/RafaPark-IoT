# RafaPark IoT 🚗

Protótipo de **estacionamento inteligente** desenvolvido para a disciplina de **Engenharia de Software – IoT**.  
O sistema utiliza um **ESP32** conectado a **sensores ultrassônicos** para detectar a presença de veículos em mini-vagas, com **LEDs** indicando o status (livre/ocupada) e envio dos dados para um **dashboard online** em tempo real.

# Tecnologias e Componentes
- ESP32 Wi-Fi + Bluetooth  
- Sensores Ultrassônicos HC-SR04  
- LEDs (verde e vermelho)  
- Resistores de 1KΩ  
- Jumpers e protoboard  
- Dashboard conectado via Wi-Fi  

# Funcionalidades
- Detecção automática de veículos (vagas ocupadas/livres)  
- Sinalização visual com LEDs   
- Interface web/mobile para monitoramento  

# Arquitetura
O projeto segue uma **arquitetura em três camadas**:
1. **Camada Física:** sensores e LEDs  
2. **Camada de Controle:** ESP32  
3. **Camada de Aplicação:** Dashboard web

## Desenvolvido por
**Rebeca Lara de Souza**  
Centro Universitário Católica de Santa Catarina — Curso de Engenharia de Software  
Versão 1.0 — 2025
