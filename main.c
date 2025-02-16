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

#define DAC7_0 PORTL // 8 bits menos significativos do DAC (PORTD)
#define DAC8 PORTC0  // bit 8 do DAC (PB0)
#define DAC9 PORTC1  // bit 9 do DAC (PB1)
#define DAC12 PORTC2 // bit 10 do DAC (PB2)
#define DAC11 PORTC3 // bit 11 do DAC (PB3)

// ============================================================================
// --- Protótipo das Funções ---
void DAC12(uint16_t dac_val); // função para enviar os dados para o DAC
void sinewave();              // função para construir a senoide de 10 bits
void rampwave();              // função para gerar o sinal em rampa

// ============================================================================
// --- Variáveis Globais ---
extern uint16_t sine12bits[1024];

// ============================================================================
// --- Função Principal ---
int main() {
  PORTB |= (1 << FUNC); // habilita pull-up interno
  DDRC |=
      (1 << DAC8) | (1 << DAC9) | (1 << DAC12) |
      (1 << DAC11); // configura saída para os 2 bits mais significativos do DAC
  DDRL = 0xFF;   // configura saída para os 8 bits menos significativos do DAC
  DAC7_0 = 0x00; // inicializa 8 bits menos significativos do DAC em LOW
  PORTC &= ~(1 << DAC8) & ~(1 << DAC9) & ~(1 << DAC12) &
           ~(1 << DAC11); // inicializa 2 bits mais significativos do DAC em LOW

  while (1) {
    if (PINB & (1 << FUNC)) // se entrada de função em HIGH
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
// --- DAC12 ---
// Envia o valor binário de 10 bits para o DAC
void DAC12(uint16_t dac_val) {

  dac_val &= 0x03FF; // limite de 10 bits

  DAC7_0 = dac_val; // atualiza os 8 bits menos significativos

  if (dac_val >> 8 & 0x0001) // atualiza o bit 8
    PORTC |= (1 << DAC8);
  else
    PORTC &= ~(1 << DAC8);

  if (dac_val >> 9 & 0x0001) // atualiza o bit 9
    PORTC |= (1 << DAC9);
  else
    PORTC &= ~(1 << DAC9);

  if (dac_val >> 10 & 0x0001) // atualiza o bit 8
    PORTC |= (1 << DAC12);
  else
    PORTC &= ~(1 << DAC12);

  if (dac_val >> 11 & 0x0001) // atualiza o bit 8
    PORTC |= (1 << DAC11);
  else
    PORTC &= ~(1 << DAC11);
} // end DAC12

// ============================================================================
// --- sinewave ---
// Gera a senoide de 10 bits
void sinewave() {
  static uint16_t values = 0x0000, // índice do vetor
      cycle = 1,                   // 1 indica ciclo positivo, 0 negativo
      dir = 1;                     // 1 indica sentido crescente, 0 decrescente

  if (cycle) // processa semiciclo positivo
  {
    DAC12(2048 + sine12bits[values]); // valores originais do vetor

    if (dir) // sentido crescente
    {
      values++;           // varre vetor no sentido crescente
      if (values == 1023) // ao atingir o máximo...
        dir = 0;          //...comuta para sentido decrescente

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
    DAC12(2048 - sine12bits[values]); // valores do vetor, subtraídos de 2048

    if (dir) // sentido crescente
    {
      values++;           // varre vetor no sentido crescente
      if (values == 1023) // ao atingir o máximo...
        dir = 0;          //...comuta para sentido decrescente

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

  DAC12(level++); // incrementa level e escreve no DAC
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
