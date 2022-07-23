# Fonte de tensão ajustável

# OBS: Até segunda está pronto, temos prova de GA

## Especificação

A fonte é capaz de transformar uma corrente alternada de 127V em corrente contínua de 3V a 12V, com o usuário podendo escolher qualquer tensão de saída nesse intervalo.

## Vídeo

_TODO: video (fazer upload e por link)_

## Componentes

_TODO_

## Circuito

_TODO: fotinha_
Link: _TODO: falstad_

## Esquemático PCB

_TODO: fotinha_

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
