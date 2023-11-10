#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Inicialização do LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define TOPICO_DISTANCIA "/TEF/sensor111/distance" // Tópico MQTT para enviar informações de distância

const int trigPin = 13; // Pino do trigger do sensor ultrassônico
const int echoPin = 12; // Pino do echo do sensor ultrassônico
Ultrasonic ultrasonicSensor(trigPin, echoPin);

const char* SSID = "Wokwi-GUEST";
const char* PASSWORD = "";
const char* BROKER_MQTT = "46.17.108.113";
const int BROKER_PORT = 1883;
const char* ID_MQTT = "fiware_111";

WiFiClient espClient;
PubSubClient MQTT(espClient);

void setup() {
    Serial.begin(115200);

    lcd.init();
    lcd.backlight();

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    MQTT.setServer(BROKER_MQTT, BROKER_PORT);
}

void loop() {
    float distance, percentage;

    // Leitura da distância do sensor ultrassônico
    distance = ultrasonicSensor.read(CM);

    Serial.print("Porcentagem do lixo: ");

    // Converter a distância em porcentagem
    percentage = map(distance, 0, 30, 100, 0);
    // Garantir que a porcentagem está no intervalo correto
    percentage = constrain(percentage, 0, 100);

    Serial.print(percentage);
    Serial.println("%");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nivel do Lixo:");
    lcd.setCursor(0, 1);
    lcd.print("Porcentagem: " + String(percentage) + "%");

    if (!MQTT.connected()) {
        reconnectMQTT();
    }

    char msgBuffer[20];
    snprintf(msgBuffer, sizeof(msgBuffer), "Porcentagem: %.1f", percentage);

    // Envia a mensagem no formato desejado para o tópico MQTT
    MQTT.publish(TOPICO_DISTANCIA, msgBuffer);

    MQTT.loop();

    delay(1000);
}

void reconnectMQTT() {
    while (!MQTT.connected()) {
        if (MQTT.connect(ID_MQTT)) {
            Serial.println("Connected to MQTT broker");
        } else {
            Serial.print("Failed, rc=");
            Serial.print(MQTT.state());
            Serial.println(" Trying again in 5 seconds");
            delay(5000);
        }
    }
}
