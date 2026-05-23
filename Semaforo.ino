const int pinoVerde = 11;
const int pinoAmarelo = 12;
const int pinoVermelho = 13;
const int pinoBotao = 10;

int estadoSemaforo = 0; 
int estadoBotaoAnterior = 0;

void atualizarLeds(void);

void setup() {
    pinMode(pinoVerde, 1);   
    pinMode(pinoAmarelo, 1);
    pinMode(pinoVermelho, 1);   
    pinMode(pinoBotao, 0);
    atualizarLeds();
}

void loop() {
    int leituraAtual = digitalRead(pinoBotao);

    if (leituraAtual != estadoBotaoAnterior) {
      
        if (leituraAtual == 0) {
            estadoSemaforo++;
            
            if (estadoSemaforo > 2) {
                estadoSemaforo = 0;
            }
            atualizarLeds();
        }
        
        estadoBotaoAnterior = leituraAtual;
    }
}

void atualizarLeds(void) {
    if (estadoSemaforo == 0) { //led vermelho
        digitalWrite(pinoVermelho, 1);
        digitalWrite(pinoAmarelo, 0);
        digitalWrite(pinoVerde, 0);
    } 
    else if (estadoSemaforo == 1) { //led amarelo
        digitalWrite(pinoVermelho, 0);
        digitalWrite(pinoAmarelo, 1); 
        digitalWrite(pinoVerde, 0);
    } 
    else if (estadoSemaforo == 2) { //led verede
        digitalWrite(pinoVermelho, 0);
        digitalWrite(pinoAmarelo, 0);
        digitalWrite(pinoVerde, 1);
    }
}