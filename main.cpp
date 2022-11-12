const int IN_SDR = 2;  // sensor infra digital direito
const int IN_SDL = 3;  // sensor infra digital esquerdo

const int MD1 = 4;  // entrada motor direito 1
const int MD2 = 5;  // entrada motor direito 2

const int ME1 = 6;  // entrada motor esquerdo 1
const int ME2 = 7;  // entrada motor esquerdo 2

void setup() {
  Serial.begin(9600);
  pinMode(IN_SDR, INPUT);
  pinMode(IN_SDL, INPUT);

  pinMode(MD1, OUTPUT);
  pinMode(MD2, OUTPUT);
  pinMode(ME2, OUTPUT);
  pinMode(ME2, OUTPUT);
}

// variaveis de entrada
bool rIsBlack;
bool lIsBlack;

void loop() {
  rIsBlack = digitalRead(IN_SDR);
  lIsBlack = digitalRead(IN_SDL);

  if (rIsBlack) {
    Serial.println("Identificou preto no direito");
  }

  if (lIsBlack) {
    Serial.println("Identificou preto na esquerda");
  }

  delay(500);
}

// TESTART SE O MOTOR DA DIREITA RODA PRA FRENTE
void motor_direita_frente() {
  digitalWrite(MD1, LOW);
  digitalWrite(MD2, HIGH);
}

// TESTAR SE O MOTOR DA ESQUERDA RODA PRA FRENTE
void motor_esquerda_frente() {
  digitalWrite(ME1, LOW);
  digitalWrite(ME2, HIGH);
}