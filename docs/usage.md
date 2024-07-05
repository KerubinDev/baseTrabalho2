# Uso

Para utilizar o somador binário de 4 bits com Arduino, siga os passos abaixo:

1. **Configuração dos pinos de entrada:**
   - Coloque os nibbles de entrada nos pinos digitais 0-3 (primeiro nibble) e 4-7 (segundo nibble) do Arduino.

2. **Ativação da soma:**
   - Configure o pino digital 13 para HIGH para ativar a operação de soma.

3. **Leitura do resultado:**
   - O resultado da soma aparecerá nos pinos digitais 8-12. Esses pinos representarão o resultado binário da operação de soma, incluindo o bit de transporte (se houver).

## Função `loop()`

A função `loop()` é a principal do programa e é executada continuamente enquanto o Arduino estiver ligado. Ela realiza as seguintes operações:

- **Verificação da ativação da soma:**
  - Lê o estado do pino digital 13 para verificar se a operação de soma deve ser realizada. Se o pino estiver HIGH, a soma será ativada.

- **Leitura dos bits de entrada:**
  - Lê os bits dos dois nibbles a partir dos pinos digitais 0 a 7. Esses bits representam os dois números binários de 4 bits que serão somados.

- **Execução da soma:**
  - Se a soma estiver ativada (pino 13 == HIGH), a função realiza a soma bit a bit dos dois nibbles utilizando as funções auxiliares `somaBit` e `somaCarryBit`.

- **Escrita do resultado:**
  - O resultado da soma é escrito nos pinos digitais de saída 8 a 12, exibindo o resultado binário da operação de soma, incluindo o bit de transporte, se presente.

Exemplo de código na função `loop()`:

```cpp
void loop() {
  // Verifica se a soma está ativada
  if (digitalRead(13) == HIGH) {
    // Leitura dos bits de entrada
    int inputA = 0;
    int inputB = 0;
    for (int i = 0; i < 4; i++) {
      inputA |= (digitalRead(i) << i);
      inputB |= (digitalRead(i + 4) << i);
    }

    // Realiza a soma dos nibbles
    int resultado = 0;
    int carry = 0;
    for (int i = 0; i < 4; i++) {
      int bitA = (inputA >> i) & 0x1;
      int bitB = (inputB >> i) & 0x1;
      int soma = somaBit(bitA, bitB, carry);
      resultado |= (soma & 0x1) << i;
      carry = (soma >> 1) & 0x1;
    }

    // Escreve o resultado nos pinos de saída
    for (int i = 0; i < 5; i++) {
      digitalWrite(8 + i, (resultado >> i) & 0x1);
    }
  }
}
```
