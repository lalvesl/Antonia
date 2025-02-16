/* ===========================================================================

        Software para teste de DAC de 10 Bits
        WR Kits vídeo aula de Engenharia Eletrônica 428
        Clássica de Sexta

    ARQUIVO main.c

    MCU:   Atmega328p
    Clock: 16MHz Cristal Externo

    Compilador: Microchip Studio 7.0.2542
    Autor: Dr. Eng. Wagner Rambo
    Data de criação: Abril de 2022
    Última atualização: 19/04/2022

============================================================================ */

// ============================================================================
// --- Bibliotecas ---
#include "macros.h"

// ============================================================================
// --- Mapemento de Hardware ---
#define FUNC PORTC0  // entrada para selecionar função
#define DAC7_0 PORTD // 8 bits menos significativos do DAC (todo o PORTD)
#define DAC8 PORTB0  // bit 8 do DAC (PB0)
#define DAC9 PORTB1  // bit 9 do DAC (PB1)

// ============================================================================
// --- Protótipo das Funções ---
void DAC10(uint16_t dac_val); // função para enviar os dados para o DAC
void sinewave();              // função para construir a senoide de 10 bits
void rampwave();              // função para gerar o sinal em rampa

// ============================================================================
// --- Variáveis Globais ---
extern uint16_t sine12bits[1024];

// ============================================================================
// --- Função Principal ---
int main() {
  PORTC |= (1 << FUNC); // habilita pull-up interno
  DDRB |=
      (1 << DAC8) |
      (1 << DAC9); // configura saída para os 2 bits mais significativos do DAC
  DDRD = 0xFF;   // configura saída para os 8 bits menos significativos do DAC
  DAC7_0 = 0x00; // inicializa 8 bits menos significativos do DAC em LOW
  PORTB &= ~(1 << DAC8) &
           ~(1 << DAC9); // inicializa 2 bits mais significativos do DAC em LOW

  while (1) {
    if (PINC & (1 << FUNC)) // se entrada de função em HIGH
      sinewave();           // gera sinal senoidal
    else                    // senão
      rampwave();           // gera rampa crescente

    _delay_us(1); // influencia na frequência dos sinais gerados.

  } // end while

  return 0;
} // end main

// ============================================================================
// --- Desenvolvimento das Funções ---

// ============================================================================
// --- DAC10 ---
// Envia o valor binário de 10 bits para o DAC
void DAC10(uint16_t dac_val) {

  dac_val &= 0x03FF; // limite de 10 bits

  DAC7_0 = dac_val; // atualiza os 8 bits menos significativos

  if (dac_val >> 8 & 0x0001) // atualiza o bit 8
    PORTB |= (1 << DAC8);
  else
    PORTB &= ~(1 << DAC8);

  if (dac_val >> 9 & 0x0001) // atualiza o bit 9
    PORTB |= (1 << DAC9);
  else
    PORTB &= ~(1 << DAC9);

} // end DAC10

// ============================================================================
// --- sinewave ---
// Gera a senoide de 10 bits
void sinewave() {
  static uint8_t values = 0x00, // índice do vetor
      cycle = 1,                // 1 indica ciclo positivo, 0 negativo
      dir = 1;                  // 1 indica sentido crescente, 0 decrescente

  if (cycle) // processa semiciclo positivo
  {
    DAC10(sine10bits[values]); // valores originais do vetor

    if (dir) // sentido crescente
    {
      values++;          // varre vetor no sentido crescente
      if (values == 255) // ao atingir o máximo...
        dir = 0;         //...comuta para sentido decrescente

    } // end if dir

    else // sentido decrescente
    {
      values--; // varre vetor no sentido decrescente

      if (!values) // ao chegar em zero...
      {
        dir = 1;   //...comuta para sentido crescente e
        cycle = 0; // semiciclo negativo
      }

    } // end else

  } // end if cycle

  else // processa semiciclo negativo
  {
    DAC10(1023 - sine10bits[values]); // valores do vetor, subtraídos de 1023

    if (dir) // sentido crescente
    {
      values++;          // varre vetor no sentido crescente
      if (values == 255) // ao atingir o máximo...
        dir = 0;         //...comuta para sentido decrescente

    } // end if dir

    else // sentido decrescente
    {
      values--; // varre vetor no sentido decrescente

      if (!values) // ao chegar em zero...
      {
        dir = 1;   //...comuta para sentido crescente e
        cycle = 1; // semiciclo positivo
      }

    } // end else dir

  } // end else cycle

} // end sinewave

// ============================================================================
// --- rampwave ---
// Gera rampa crescente de 10 bits
void rampwave() {
  static uint16_t level = 0x0000; // armazena o nível de tensão

  DAC10(level++); // incrementa level e escreve no DAC
}

/* ============================================================================

                                       _
                                      / \
                                     |oo >      <-- (DAC 10 Bits!)
                                     _\=/_
                    ___         #   /  _  \   #
                   /<> \         \\//|/.\|\\//
                 _|_____|_        \/  \_/  \/
                | | === | |          |\ /|
                |_|  0  |_|          \_ _/
                 ||  0  ||           | | |
                 ||__*__||           | | |
                |* \___/ *|          []|[]
                /=\ /=\ /=\          | | |
________________[_]_[_]_[_]_________/_]_[_\_______________________________


============================================================================ */
/* --- Final do Arquivo main.c --- */
