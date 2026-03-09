# Estacionamento Automatizado
Este é o código que usei em meu meu protótipo de estacionamento automatizado que desenvolvi durante o TCC do meu curso técnico em Eletrônica no liceu de Artes e Ofícios de São Paulo.

## Objetivos
Desenvolver um sistema que: 
- indica o status de cada uma das vagas de um estacionamento por meio de sensores de luz;
- mostrar, por meio de um display, os tipos de vagas (cadeirante, idoso, não preferencial) e seus respectivos números de vagas disponíveis;
- caso o estacionamento esteja lotado, o display mostra a frase: “ESTACIONAMENTO LOTADO”;
- garante o direito de idosos e/ou cadeirantes a uma vaga preferencial, de modo que, se algum veículo não pertencente a um idoso e/ou cadeirante estacionar em uma vaga preferencial, o segurança do estacionamento será informado desta infração por meio de um aplicativo de celular;
- evita a superlotação do estacionamento ao programar o servo que funcionará como a cancela da entrada do estacionamento para não permitir a entrada de veículos quando o estacionamento está lotado.

## Componentes do sistema
- Sensores de luz LDR, para detectar a presença de veículos;
- Dois servo motores que atuam como as catracas de entrada e saída;
- 1 LED RGB para cada vaga que indicará pelas suas cores se sua respectiva vaga está livre, ocupada ou livre apenas para deficientes;
- 1 leitor RFID RC522 para uma das vagas especiais, para identificar se o carro estacionado naquela vaga pertence a um idoso e/ou deficiente por meio de uma tag;
- 1 display LCD, para mostrar quantas vagas do estacionamento estão disponíveis;
- 1 Módulo Bluetooth HC-05 responsável por enviar uma mensagem para o celular do segurança do estacionamento caso um veículo estacione na vaga preferencial sem a tag;
- 1 placa Arduino Mega programada para realizar as ações dos LEDs, do display e outros componentes.

## Funcionamento
O estacionamento possui 10 vagas, em que cada uma:
- possui 1 LED RGB;
- possui 1 sensor de luz LDR para detecção de presença de veículos;
- Pode ser preferencial (para cadeirante ou idoso) ou não.
As vagas são nomeadas como nome das portas analógicas do Arduino Mega indo de A1 a A10 (a porta A0 é reservada para o LDRP, sensor utilizado como parâmetro). Quando uma vaga preferencial está desocupada, a cor de seu respectivo LED se torna azul, mas se esta vaga for não preferencial, a cor do LED se torna verde. Caso a vaga esteja ocupada a cor fica vermelha, independentemente do tipo da vaga.
O programa também é responsável por realizar a contagem de vagas preferenciais desocupadas, não preferenciais desocupadas e vagas ocupadas para exibir essas informações no display LCD na entrada do estacionamento. Sendo assim, as mensagem exibidas pelo display são:

### Mensagem exibida pelo display LCD com estacionamento não lotado
```
Vagas disponíveis:  
cadeirantes: (nº de vagas preferenciais disponíveis para cadeirantes)  
idosos: (nº de vagas preferenciais disponíveis para idosos)  
não preferenciais: (nº de vagas não preferenciais)
```
### Mensagem exibida pelo display LCD com estacionamento lotado
```
ESTACIONAMENTO  
LOTADO
```
> [!NOTE]
> **OBS:** A vaga A1 é a única vaga preferencial que possui um leitor RFID que detecta a presença de uma tag inválida ou aceita. Se um veículo estacionar na vaga A1 com uma tag não válida, o sensor RFID a detectará e o programa enviará a mensagem "Veículo não autorizado estacionado na vaga A1" para o celular do segurança do estacionamento por meio do módulo Bluetooth. Caso contrário, a mensagem recebida por ele será "OK".

Há também sensores LDR na entrada e saída o estacionamento para detectar a presença de veículos para que seja possível coordenar o movimento dos servos que atuam como cancelas.

## Monografia
Para informações mais detalhadas sobre o projeto, [clique aqui](https://drive.google.com/file/d/1pWfbIhtcsnyArzGGGSPpblbZZmGsbQoN/view) para ver a monografia do trabalho.
