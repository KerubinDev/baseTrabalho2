# Somador Binário com Arduino

Este projeto consiste em um somador binário de 4 bits implementado com um Arduino. Ele lê dois números binários de 4 bits (nibbles) a partir de pinos de entrada digitais, realiza a soma com suporte a bit de transporte (carry bit) e exibe o resultado nos pinos de saída digitais.

## Conteúdo
- [Visão Geral](overview.md)
- [Instalação](installation.md)
- [Uso](usage.md)
- [Exemplos](examples/)

## Visão Geral

Este projeto demonstra como utilizar um Arduino para criar um somador binário de 4 bits. Ele é capaz de ler dois números binários de 4 bits a partir de pinos de entrada digitais, realizar a soma binária com suporte para bit de transporte (carry bit), e exibir o resultado nos pinos de saída digitais. Este projeto é uma excelente introdução à lógica digital e ao uso de microcontroladores para operações aritméticas básicas.

## Instalação

Para instalar e configurar o projeto, siga os passos abaixo:

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/seu-usuario/somador-binario-arduino.git
   ```
   Navegue até o diretório do projeto:
   ```bash
   cd somador-binario-arduino
   ```

2. **Configure o Arduino IDE:**
   - Certifique-se de ter o Arduino IDE instalado. Você pode baixá-lo [aqui](https://www.arduino.cc/en/software).
   - Abra o Arduino IDE e carregue o arquivo `somador_binario.ino` localizado na pasta do projeto.

3. **Conecte o Arduino:**
   - Conecte o seu Arduino ao computador através de um cabo USB.
   - No Arduino IDE, selecione a placa correta em **Ferramentas > Placa** e a porta serial em **Ferramentas > Porta**.

4. **Carregue o código:**
   - No Arduino IDE, clique no botão de upload (seta para a direita) para compilar e carregar o código para o Arduino.

## Uso

Após a instalação, você pode usar o somador binário seguindo os passos abaixo:

1. **Conecte os pinos de entrada:**
   - Conecte dois conjuntos de 4 pinos de entrada aos pinos digitais especificados no código (`inputA` e `inputB`).

2. **Conecte os pinos de saída:**
   - Conecte os pinos de saída aos pinos digitais especificados no código (`output` e `carryOut`).

3. **Realize a soma:**
   - Ajuste os pinos de entrada para os valores binários desejados.
   - O resultado da soma será exibido nos pinos de saída.