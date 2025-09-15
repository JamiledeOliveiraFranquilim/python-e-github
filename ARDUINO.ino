#include <Servo.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT22
#define SERVO_PIN 5
#define BUZZER_PIN 6
#define BUTTON_PIN 8

#define TEMP_VENTILACAO_BAIXA 25.0
#define TEMP_VENTILACAO_ALTA 28.0
#define TEMP_ALERTA_CRITICO 35.0
#define TEMP_ALERTA_MINIMO 10.0

DHT dht(DHTPIN, DHTTYPE);
Servo servoVentilacao;

bool modoManual = false;
bool estadoBotaoAnterior = HIGH;

void setup() {
  Serial.begin(9600);
  dht.begin();
  servoVentilacao.attach(SERVO_PIN);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  servoVentilacao.write(0);
  Serial.println("Teste do sistema iniciado.");
}

void loop() {
  // --- Leitura do DHT22 ---
  float temperatura = dht.readTemperature();
  if (isnan(temperatura)) {
    Serial.println("Erro: DHT22 nao leu temperatura!");
  } else {
    Serial.print("Temperatura: ");
    Serial.println(temperatura);
  }

  // --- Leitura do botão ---
  bool estadoBotaoAtual = digitalRead(BUTTON_PIN);
  if (estadoBotaoAtual == LOW && estadoBotaoAnterior == HIGH) {
    modoManual = !modoManual;
    delay(200); // debounce
    if (modoManual) {
      Serial.println("Modo Manual ATIVADO!");
      servoVentilacao.write(90);
      noTone(BUZZER_PIN);
    } else {
      Serial.println("Modo Manual DESATIVADO!");
    }
  }
  estadoBotaoAnterior = estadoBotaoAtual;

  // --- Controle automático ---
  if (!modoManual && !isnan(temperatura)) {
    // Alertas críticos
    if (temperatura > TEMP_ALERTA_CRITICO) {
      tone(BUZZER_PIN, 1000);
      Serial.println("ALERTA: Temperatura muito alta!");
    } else if (temperatura < TEMP_ALERTA_MINIMO) {
      tone(BUZZER_PIN, 500);
      Serial.println("ALERTA: Temperatura muito baixa!");
    } else {
      noTone(BUZZER_PIN);
    }

    // Controle proporcional do servo
    float abertura = 0.0;
    if (temperatura >= TEMP_VENTILACAO_ALTA) {
      abertura = 90.0;
    } else if (temperatura > TEMP_VENTILACAO_BAIXA) {
      abertura = ((temperatura - TEMP_VENTILACAO_BAIXA) /
                 (TEMP_VENTILACAO_ALTA - TEMP_VENTILACAO_BAIXA)) * 90.0;
    } else {
      abertura = 0.0;
    }

    servoVentilacao.write(abertura);
    Serial.print("Servo abertura proporcional: ");
    Serial.println(abertura);
  }

  delay(2000); // Aguarda 2 segundos
}