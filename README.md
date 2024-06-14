
# Somador Binário com Arduino

Este projeto consiste em um somador binário de 4 bits implementado com um Arduino. Ele lê dois números binários de 4 bits (nibbles) a partir de pinos de entrada digitais, realiza a soma com suporte a bit de transporte (carry bit) e exibe o resultado nos pinos de saída digitais.

## Estrutura do Código

O código está dividido nas seguintes partes principais:
1. Declaração de Variáveis
2. Função `setup()`
3. Funções auxiliares (`somaBit` e `somaCarryBit`)
4. Função `loop()`

### Declaração de Variáveis

```cpp
int soma = 13;
int carryBit = 0;
int nib1a, nib1b, nib1c, nib1d = 0;
int nib2a, nib2b, nib2c, nib2d = 0;
int res1a, res1b, res1c, res1d = 0;
```

As variáveis são usadas para armazenar os bits dos nibbles de entrada, o resultado da soma e o bit de transporte.

### Função `setup()`

```cpp
void setup() {
    pinMode(0, INPUT);
    pinMode(1, INPUT);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, INPUT);
}
```

A função `setup()` configura os pinos do Arduino como entradas ou saídas. Os pinos de 0 a 7 são configurados como entradas para ler os bits dos nibbles, enquanto os pinos de 8 a 12 são configurados como saídas para exibir o resultado da soma e o bit de transporte. O pino 13 é usado para ativar a operação de soma.

### Funções Auxiliares

#### `somaBit`

```cpp
int somaBit(int b1a, int b2a, int cBit) {
    int bitResult = 0;
    if ((b1a ^ b2a) ^ cBit) {
        bitResult = 1;
    } else {
        bitResult = 0;
    }
    return bitResult;
}
```

Esta função realiza a soma de dois bits individuais, levando em conta o bit de transporte (carry bit) anterior. Ela retorna o bit de resultado dessa soma.

#### `somaCarryBit`

```cpp
int somaCarryBit(int b1a, int b2a, int cBit) {
    if ((b1a && b2a) || (b1a && cBit) || (b2a && cBit)) {
        cBit = 1;
    } else {
        cBit = 0;
    }
    return cBit;
}
```

Esta função calcula o bit de transporte resultante da soma de dois bits e um carry bit.

### Função `loop()`

```cpp
void loop() {
    soma = digitalRead(13);
    nib1a = digitalRead(0);
    nib1b = digitalRead(1);
    nib1c = digitalRead(2);
    nib1d = digitalRead(3);
    nib2a = digitalRead(4);
    nib2b = digitalRead(5);
    nib2c = digitalRead(6);
    nib2d = digitalRead(7);
    
    if (soma == 1) {
        carryBit = 0;
        res1a = somaBit(nib1a, nib2a, carryBit);
        carryBit = somaCarryBit(nib1a, nib2a, carryBit);
        res1b = somaBit(nib1b, nib2b, carryBit);
        carryBit = somaCarryBit(nib1b, nib2b, carryBit);
        res1c = somaBit(nib1c, nib2c, carryBit);
        carryBit = somaCarryBit(nib1c, nib2c, carryBit);
        res1d = somaBit(nib1d, nib2d, carryBit);
        carryBit = somaCarryBit(nib1d, nib2d, carryBit);
    }
    
    digitalWrite(8, res1a);
    digitalWrite(9, res1b);
    digitalWrite(10, res1c);
    digitalWrite(11, res1d);
    digitalWrite(12, carryBit);
}
```

A função `loop()` é a principal do programa e é executada continuamente. Ela faz o seguinte:
1. Lê o estado do pino 13 para verificar se a operação de soma deve ser realizada.
2. Lê os bits dos dois nibbles a partir dos pinos 0 a 7.
3. Se a soma for ativada (soma == 1), realiza a soma bit a bit dos dois nibbles utilizando as funções auxiliares `somaBit` e `somaCarryBit`.
4. Escreve o resultado da soma nos pinos de saída 8 a 12.

## Como Usar

1. **Configuração do Hardware**: Conecte os pinos do Arduino conforme especificado no código (`setup()`).
2. **Carregar o Código**: Carregue este código no seu Arduino usando o Arduino IDE.
3. **Operação**: Coloque os nibbles de entrada nos pinos 0-3 (primeiro nibble) e 4-7 (segundo nibble). Ative a soma configurando o pino 13 para HIGH. O resultado aparecerá nos pinos 8-12.

## Autor
- **Nome do Estudante**: [Seu Nome]
- **Professor**: Glauber Kiss de Souza
- **Disciplina**: Análise e Orientação Técnica
- **Instituição**: SENAC NH

## Licença

Este projeto está licenciado sob a licença MIT - veja o arquivo LICENSE.md para detalhes.