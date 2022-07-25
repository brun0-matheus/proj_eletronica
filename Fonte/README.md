# Fonte de tensão ajustável

## Especificação

A fonte é capaz de transformar uma corrente alternada de 127V em corrente contínua de 3V a 12V, com o usuário podendo escolher qualquer tensão de saída nesse intervalo.

## Vídeo

<a href="http://www.youtube.com/watch?feature=player_embedded&v=84dRtorudmM
" target="_blank"><img src="http://img.youtube.com/vi/84dRtorudmM/0.jpg" 
alt="Thumbnail do video" width="240" height="180" border="10" /></a>

## Componentes

|  Quantidade  |  Componente  |  Preço  |
|---|---|---|
| 1x | Capacitor 608uF 25V | R$ 1,45 |
| 1x | LED 5mm | R$ 0,50 |
| 2x | Resistor 1kΩ | R$ 0,14 |
| 1x | Resistor 2kΩ | R$ 0,07 |
| 4x | Diodo 1N4007 | R$ 0,80 |
| 1x | Diodo Zenner 13V 1N4743 | R$ 0,48 |
| 1x | Potenciômetro | R$ 7,00 |
| 1x | Transistor | R$ 0,50 |
| 1x | Transformador | (Pego emprestado) |
| Total | - | R$ 10,94 |

## Circuito

![alt text](https://raw.githubusercontent.com/brun0-matheus/proj_eletronica/main/Fonte/simulador.jpg "Simulador")

Link: <https://tinyurl.com/2484r982>

## Esquemático e PCB

![alt text](https://raw.githubusercontent.com/brun0-matheus/proj_eletronica/main/Fonte/esquematico.jpg "Esquemático")

![alt text](https://raw.githubusercontent.com/brun0-matheus/proj_eletronica/main/Fonte/pcb.jpg "PCB")

## Contas

### Tensão

Tensão da entrada da fonte: 127V

Tensão de pico da entrada da fonte: 127 * √2 = 180V


Razão transformador: 1/7,5

Tensão pico após transformador: 24V

Tensão pico após diodos: 24 - 1,4 = 22,6V


Ripple de 10%: 22,6 / 10 = 2,2V (ou seja, perda de 2,2V)

Tensão mínima no circuito: 22,6 - 2,2 = 20,4V


Tensão média: (20,4 + 22,6) / 2 = 21,5V

### Corrente

Corrente carga: (13 / 120) = 108mA

Corrente LED: (21,5 - 2) / 1000 = 19,5mA

Corrente Zener: (21,5 - 13) / 1000 = 8,5mA

Corrente potenciometro: 21,5 / 8200 = 2,6mA


Corrente total: 138,6mA

### Capacitor 

C = (0,1386) / (2 * 60 * 2,2) = 525uF

Têm capacitores de 560uF e 680uF, colocamos o de 680uF por garantia.
