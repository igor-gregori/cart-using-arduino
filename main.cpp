const int SDIR = 8;
const int SESQ = 9;

const int MD_POS = 2;
const int MD_NEG = 3;

const int ME_POS = 4;
const int ME_NEG = 5;

const int ECHO = 10;
const int TRIGGER = 11;

bool SDIR_ATIVO;
bool SESQ_ATIVO;

int DIST_CM;

void setup() {
  Serial.begin(9600);

  pinMode(SDIR, INPUT);
  pinMode(SESQ, INPUT);

  pinMode(MD_POS, OUTPUT);
  pinMode(MD_NEG, OUTPUT);
  pinMode(ME_POS, OUTPUT);
  pinMode(ME_NEG, OUTPUT);
}

void loop() {
  SDIR_ATIVO = digitalRead(SDIR);
  SESQ_ATIVO = digitalRead(SESQ);

  Serial.print("SENSOR DIREITO = ");
  Serial.println(SDIR_ATIVO);
  Serial.print("SENSOR ESQUERDO = ");
  Serial.println(SESQ_ATIVO);
  Serial.print("SENSOR FRENTE = ");
  DIST_CM = letDistanciaCm(TRIGGER, ECHO);
  Serial.println(DIST_CM);
  Serial.println("");

  if (DIST_CM < 6) {
    esquerda_para();
    direita_para();
  } else if (SDIR_ATIVO && SESQ_ATIVO) {
    esquerda_para();
    direita_para();
  } else if (!SDIR_ATIVO && !SESQ_ATIVO) {
    esquerda_move();
    direita_move();
  } else if (SDIR_ATIVO) {
    esquerda_para();
    direita_move();
  } else if (SESQ_ATIVO) {
    esquerda_move();
    direita_para();
  }
}

int letDistanciaCm(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return 0.01723 * pulseIn(echoPin, HIGH);
}

// void direita_move() {
//   digitalWrite(MD_NEG, HIGH);
//   digitalWrite(MD_POS, LOW);
// }

// void direita_para() {
//   digitalWrite(MD_NEG, HIGH);
//   digitalWrite(MD_POS, HIGH);
// }

// void esquerda_move() {
//   digitalWrite(ME_NEG, HIGH);
//   digitalWrite(ME_POS, LOW);
// }

// void esquerda_para() {
//   digitalWrite(ME_NEG, HIGH);
//   digitalWrite(ME_POS, HIGH);
// }

void direita_move() {
  analogWrite(MD_NEG, 140);
  analogWrite(MD_POS, 0);
}

void direita_para() {
  analogWrite(MD_NEG, 0);
  analogWrite(MD_POS, 0);
}

void esquerda_move() {
  analogWrite(ME_NEG, 140);
  analogWrite(ME_POS, 0);
}

void esquerda_para() {
  analogWrite(ME_NEG, 0);
  analogWrite(ME_POS, 0);
}