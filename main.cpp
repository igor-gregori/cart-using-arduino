const int SDIR = 8;
const int SESQ = 9;

const int MD_POS = 2;
const int MD_NEG = 3;

const int ME_POS = 4;
const int ME_NEG = 5;

const int velocidade = 120;

bool SDIR_ATIVO;
bool SESQ_ATIVO;

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
  // direita_frente();
  // esquerda_frente();

  SDIR_ATIVO = digitalRead(SDIR);
  SESQ_ATIVO = digitalRead(SESQ);

  Serial.print("SENSOR DIREITO = ");
  Serial.println(SDIR_ATIVO);
  Serial.print("SENSOR ESQUERDO = ");
  Serial.println(SESQ_ATIVO);

  // if (SDIR_ATIVO) {
  //   Serial.println("Identificou preto no direito");
  // }

  // if (SESQ_ATIVO) {
  //   Serial.println("Identificou preto na esquerda");
  // }

  Serial.println("");
  Serial.println("");
  
  delay(1000);
}

void direita_frente() {
  analogWrite(MD_NEG, velocidade);
  analogWrite(MD_POS, 0);
}

void esquerda_frente() {
  analogWrite(ME_NEG, velocidade);
  analogWrite(ME_POS, 0);
}