# RafaPark IoT – Códigos Arduino

Este diretório contém os **códigos desenvolvidos no Arduino IDE** para o projeto **RafaPark IoT**, que tem como objetivo simular e monitorar vagas de estacionamento utilizando **ESP32**, **sensores ultrassônicos HC-SR04**, **LEDs indicadores**, **Wi-Fi**, **MQTT** e **acesso via navegador**.

Os códigos foram desenvolvidos **de forma incremental**, começando do básico até chegar a uma solução mais completa, permitindo melhor entendimento do funcionamento de cada componente.

---

## Requisitos

- Arduino IDE
- Placa **ESP32** configurada na IDE
- Cabos jumper
- Sensores ultrassônicos **HC-SR04**
- LEDs + resistores
- Rede Wi-Fi **2.4 GHz**

---

## Como usar os códigos

1. Abra a **Arduino IDE**
2. Copie o código desejado deste repositório
3. Cole em um novo **Sketch**
4. Configure na IDE:
   - **Placa:** ESP32 correta
   - **Porta COM**
5. Faça o **upload** para a placa

> ⚠️ **Importante**  
> Estes códigos **devem ser compilados exclusivamente na Arduino IDE**.  
> O VS Code é utilizado apenas para **organização e versionamento no GitHub**.

---

## Evolução dos códigos

### Código 1 – Pisca LED
**Objetivo:**  
Aprender o funcionamento básico de GPIO.

**Descrição:**  
Liga e desliga um LED conectado ao GPIO 15 a cada 400 ms.

**Conceitos abordados:**
- `pinMode`
- `digitalWrite`
- `delay`

---

### Código 2 – Sensor de distância com 1 LED
**Objetivo:**  
Introdução ao sensor ultrassônico HC-SR04.

**Descrição:**  
- Mede a distância
- Acende um LED quando a distância é menor ou igual a 10 cm

**Conceitos abordados:**
- TRIG / ECHO
- `pulseIn`
- Comunicação Serial

---

### Código 3 – Sensor com 2 LEDs
**Objetivo:**  
Criar indicação visual de estado da vaga.

**Descrição:**  
- LED vermelho → vaga ocupada  
- LED verde → vaga livre

**Conceitos abordados:**
- Estruturas condicionais
- Uso de múltiplos LEDs

---

### Código 4 – 3 sensores com 2 LEDs cada
**Objetivo:**  
Escalar o sistema para múltiplas vagas.

**Descrição:**  
- 3 sensores funcionando de forma independente  
- Cada sensor com LEDs de status

**Conceitos abordados:**
- Funções reutilizáveis
- Organização do código
- Escalabilidade

---

### Código 5 – Conexão Wi-Fi + MQTT
**Objetivo:**  
Enviar os dados das vagas para a internet.

**Descrição:**  
- Conecta a ESP32 ao Wi-Fi
- Publica o estado das vagas via **MQTT**

**Conceitos abordados:**
- Wi-Fi na ESP32
- Broker MQTT
- Comunicação IoT

---

### Código 6 – Wi-Fi + MQTT + acesso web
**Objetivo:**  
Disponibilizar as informações via navegador.

**Descrição:**  
- Cria um **servidor web** na ESP32
- Exibe informações básicas em uma página HTML
- Mantém o envio dos dados via MQTT

**Conceitos abordados:**
- WebServer na ESP32
- HTML embarcado
- Execução de múltiplos serviços

---

### Código 7 – Versão final com 3 sensores
**Objetivo:**  
Unificar todas as funcionalidades em um único sistema.

**Descrição:**  
- 3 sensores de vaga
- LEDs indicadores
- Conexão Wi-Fi
- Comunicação MQTT
- Dashboard Web acessível via IP

**Conceitos consolidados:**
- Arquitetura IoT
- Modularização
- Integração entre hardware e software

---

## Considerações finais

Este conjunto de códigos representa um **processo de aprendizado gradual**, onde cada etapa foi construída sobre a anterior.

O foco foi:
- Entender o funcionamento dos componentes
- Evitar pular etapas
- Construir uma base sólida antes de avançar

Essa abordagem resultou em um sistema mais organizado, compreensível e fácil de evoluir.