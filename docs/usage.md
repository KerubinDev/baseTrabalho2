# Uso

1. Coloque os nibbles de entrada nos pinos 0-3 (primeiro nibble) e 4-7 (segundo nibble).
2. Ative a soma configurando o pino 13 para HIGH.
3. O resultado aparecerá nos pinos 8-12.

## Função `loop()`
A função `loop()` é a principal do programa e é executada continuamente. Ela faz o seguinte:
- Lê o estado do pino 13 para verificar se a operação de soma deve ser realizada.
- Lê os bits dos dois nibbles a partir dos pinos 0 a 7.
- Se a soma for ativada (soma == 1), realiza a soma bit a bit dos dois nibbles utilizando as funções auxiliares `somaBit` e `somaCarryBit`.
- Escreve o resultado da soma nos pinos de saída 8 a 12.
