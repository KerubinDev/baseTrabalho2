# Visão Geral

Este projeto consiste em um somador binário de 4 bits implementado com um Arduino. Ele lê dois números binários de 4 bits a partir dos pinos de entrada digitais, realiza a soma com suporte a bit de transporte (carry bit) e exibe o resultado nos pinos de saída digitais.

## Estrutura do Código

O código está organizado nas seguintes partes principais:

1. **Declaração de Variáveis:**
   - Nesta seção, são declaradas as variáveis que armazenarão os valores dos pinos de entrada e saída, assim como as variáveis auxiliares necessárias para a operação do somador.

2. **Função `setup()`:**
   - A função `setup()` é executada uma vez quando o Arduino é ligado ou reiniciado. Aqui, são configurados os modos dos pinos (entrada ou saída) e inicializadas quaisquer variáveis ou estados necessários.

3. **Funções Auxiliares:**
   - `somaBit`: Realiza a soma de dois bits individuais e retorna o resultado e o bit de transporte gerado.
   - `somaCarryBit`: Realiza a soma de dois bits individuais junto com um bit de transporte, retornando o resultado e o novo bit de transporte gerado.

4. **Função `loop()`:**
   - A função `loop()` é executada repetidamente enquanto o Arduino estiver ligado. Nesta seção, os valores dos pinos de entrada são lidos, as operações de soma são realizadas utilizando as funções auxiliares, e os resultados são escritos nos pinos de saída.