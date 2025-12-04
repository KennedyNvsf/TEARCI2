#include <Stepper.h>

const int stepsPerRevolution = 2048;  // Número de passos por revolução

// Pinos do ULN2003 no FireBeetle 2 ESP32-E
#define IN1 17
#define IN2 16
#define IN3 4
#define IN4 12

// Pinos dos botões
#define BTN_CW  2   // Botão para girar no sentido horário 
#define BTN_CCW 13  // Botão para mudar para sentido anti-horário
#define BTN_CNT 14  // Botão para contar um item e voltar ao sentido horário

int itemCount = 0; // Contador de itens
bool rotatingClockwise = true; // Começa girando no sentido horário

// Inicializa a biblioteca Stepper
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  myStepper.setSpeed(9); // Define a velocidade do motor
  Serial.begin(115200);

  // Configura os botões como entrada com pull-up interno
  pinMode(BTN_CCW, INPUT_PULLUP);
  pinMode(BTN_CNT, INPUT_PULLUP);

  Serial.println("Sistema pronto. Motor iniciando no sentido horário.");
}

void loop() {
  if (rotatingClockwise) {
    myStepper.step(1);  // Motor gira no sentido horário indefinidamente
  } else {
    myStepper.step(-1); // Motor gira no sentido anti-horário indefinidamente
  }

  // Se o botão de reversão for pressionado, inverter a direção
  if (digitalRead(BTN_CCW) == LOW) {
    Serial.println("Mudando para sentido anti-horário...");
    rotatingClockwise = false; // Altera para anti-horário
    delay(500); // Evita leituras repetidas
  }

  // Se o botão de contagem for pressionado
  if (digitalRead(BTN_CNT) == LOW) {
    itemCount++;
    Serial.print("Item contado: ");
    Serial.println(itemCount);

    rotatingClockwise = true; // Volta para sentido horário
    Serial.println("Voltando ao sentido horário...");

    delay(500); // Evita leituras repetidas

    // Se atingir 10 itens, reinicia a contagem
    if (itemCount >= 10) {
      Serial.println("Reiniciando contagem...");
      itemCount = 0;
    }
  }
}
