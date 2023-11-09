# Lixeira Inteligente

Este projeto consiste em uma lixeira inteligente que utiliza um ESP32, um sensor ultrassônico, um servo motor e um display LCD 16x2 para monitorar o nível de lixo na lixeira.

## Descrição

O projeto foi desenvolvido para monitorar a quantidade de lixo na lixeira e automatizar o processo de abertura da tampa quando alguém se aproxima. Ele utiliza um sensor ultrassônico para medir a distância até o lixo na lixeira e exibe a porcentagem do nível de lixo em um display LCD. Além disso, um servo motor é acionado para abrir a tampa quando detecta a presença de alguém próximo.

## Componentes Utilizados

- ESP32
- Sensor Ultrassônico HC-SR04
- Display LCD 16x2 (com módulo I2C)
- Cabos

## Instruções de Uso

1. Conecte o ESP32 aos componentes conforme descrito no código fornecido.
2. Carregue o código no ESP32 utilizando a IDE do Arduino.
3. Certifique-se de ter as bibliotecas necessárias instaladas (LiquidCrystal_I2C, Ultrasonic).
4. Alimente o sistema e aguarde a inicialização.
5. O display LCD exibirá a porcentagem de lixo na lixeira.


## Estrutura do Código

- `smart_trash.ino`: Este arquivo contém o código principal para o ESP32, que lê o sensor ultrassônico, calcula a porcentagem de lixo na lixeira.

## Diagrama de Conexão

![Diagrama de Conexão](![image](https://github.com/guidxs/Smart-Trash/assets/126616600/c4c219fe-f339-422f-9399-65ec92d34797)
)

## Notas

- Certifique-se de ajustar os pinos de acordo com a sua configuração de hardware.
- Este é um exemplo básico e pode ser expandido para incluir mais funcionalidades, como conectividade com a internet para monitoramento remoto.

## Autores

- [Guilherme Doretto Sobreiro](github.com/guidxs) - Desenvolvedor

---
