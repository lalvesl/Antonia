/* ===========================================================================

        Software para teste de DAC de 10 Bits
        WR Kits vídeo aula
de
Engenharia Eletrônica 428
        Clássica de Sexta

    ARQUIVO macros.h

    MCU:   Atmega328p
    Clock: 16MHz Cristal Externo

    Compilador: Microchip Studio 7.0.2542
    Autor: Dr. Eng. Wagner Rambo
    Data de criação: Abril de 2022
    Última atualização: 19/04/2022

============================================================================ */

// ============================================================================
// --- Clock do MCU ---
#define F_CPU 16000000UL

// ============================================================================
// --- Bibliotecas ---
#include <avr/io.h>
#include <util/delay.h>

// ============================================================================
// --- Variáveis Globais ---
uint16_t sine12bits[1024] = {
    0x0000, 0x0003, 0x0006, 0x0009, 0x000d, 0x0010, 0x0013, 0x0016, 0x0019,
    0x001c, 0x001f, 0x0023, 0x0026, 0x0029, 0x002c, 0x002f, 0x0032, 0x0035,
    0x0039, 0x003c, 0x003f, 0x0042, 0x0045, 0x0048, 0x004b, 0x004e, 0x0052,
    0x0055, 0x0058, 0x005b, 0x005e, 0x0061, 0x0064, 0x0068, 0x006b, 0x006e,
    0x0071, 0x0074, 0x0077, 0x007a, 0x007e, 0x0081, 0x0084, 0x0087, 0x008a,
    0x008d, 0x0090, 0x0093, 0x0097, 0x009a, 0x009d, 0x00a0, 0x00a3, 0x00a6,
    0x00a9, 0x00ac, 0x00b0, 0x00b3, 0x00b6, 0x00b9, 0x00bc, 0x00bf, 0x00c2,
    0x00c6, 0x00c9, 0x00cc, 0x00cf, 0x00d2, 0x00d5, 0x00d8, 0x00db, 0x00df,
    0x00e2, 0x00e5, 0x00e8, 0x00eb, 0x00ee, 0x00f1, 0x00f4, 0x00f7, 0x00fb,
    0x00fe, 0x0101, 0x0104, 0x0107, 0x010a, 0x010d, 0x0110, 0x0113, 0x0117,
    0x011a, 0x011d, 0x0120, 0x0123, 0x0126, 0x0129, 0x012c, 0x012f, 0x0133,
    0x0136, 0x0139, 0x013c, 0x013f, 0x0142, 0x0145, 0x0148, 0x014b, 0x014e,
    0x0152, 0x0155, 0x0158, 0x015b, 0x015e, 0x0161, 0x0164, 0x0167, 0x016a,
    0x016d, 0x0171, 0x0174, 0x0177, 0x017a, 0x017d, 0x0180, 0x0183, 0x0186,
    0x0189, 0x018c, 0x018f, 0x0192, 0x0196, 0x0199, 0x019c, 0x019f, 0x01a2,
    0x01a5, 0x01a8, 0x01ab, 0x01ae, 0x01b1, 0x01b4, 0x01b7, 0x01ba, 0x01bd,
    0x01c1, 0x01c4, 0x01c7, 0x01ca, 0x01cd, 0x01d0, 0x01d3, 0x01d6, 0x01d9,
    0x01dc, 0x01df, 0x01e2, 0x01e5, 0x01e8, 0x01eb, 0x01ee, 0x01f1, 0x01f4,
    0x01f7, 0x01fb, 0x01fe, 0x0201, 0x0204, 0x0207, 0x020a, 0x020d, 0x0210,
    0x0213, 0x0216, 0x0219, 0x021c, 0x021f, 0x0222, 0x0225, 0x0228, 0x022b,
    0x022e, 0x0231, 0x0234, 0x0237, 0x023a, 0x023d, 0x0240, 0x0243, 0x0246,
    0x0249, 0x024c, 0x024f, 0x0252, 0x0255, 0x0258, 0x025b, 0x025e, 0x0261,
    0x0264, 0x0267, 0x026a, 0x026d, 0x0270, 0x0273, 0x0276, 0x0279, 0x027c,
    0x027f, 0x0282, 0x0285, 0x0288, 0x028b, 0x028e, 0x0291, 0x0294, 0x0297,
    0x029a, 0x029d, 0x02a0, 0x02a3, 0x02a6, 0x02a9, 0x02ac, 0x02af, 0x02b2,
    0x02b5, 0x02b8, 0x02ba, 0x02bd, 0x02c0, 0x02c3, 0x02c6, 0x02c9, 0x02cc,
    0x02cf, 0x02d2, 0x02d5, 0x02d8, 0x02db, 0x02de, 0x02e1, 0x02e4, 0x02e7,
    0x02e9, 0x02ec, 0x02ef, 0x02f2, 0x02f5, 0x02f8, 0x02fb, 0x02fe, 0x0301,
    0x0304, 0x0307, 0x030a, 0x030c, 0x030f, 0x0312, 0x0315, 0x0318, 0x031b,
    0x031e, 0x0321, 0x0324, 0x0327, 0x0329, 0x032c, 0x032f, 0x0332, 0x0335,
    0x0338, 0x033b, 0x033e, 0x0340, 0x0343, 0x0346, 0x0349, 0x034c, 0x034f,
    0x0352, 0x0354, 0x0357, 0x035a, 0x035d, 0x0360, 0x0363, 0x0366, 0x0368,
    0x036b, 0x036e, 0x0371, 0x0374, 0x0377, 0x0379, 0x037c, 0x037f, 0x0382,
    0x0385, 0x0387, 0x038a, 0x038d, 0x0390, 0x0393, 0x0396, 0x0398, 0x039b,
    0x039e, 0x03a1, 0x03a4, 0x03a6, 0x03a9, 0x03ac, 0x03af, 0x03b2, 0x03b4,
    0x03b7, 0x03ba, 0x03bd, 0x03bf, 0x03c2, 0x03c5, 0x03c8, 0x03ca, 0x03cd,
    0x03d0, 0x03d3, 0x03d6, 0x03d8, 0x03db, 0x03de, 0x03e1, 0x03e3, 0x03e6,
    0x03e9, 0x03eb, 0x03ee, 0x03f1, 0x03f4, 0x03f6, 0x03f9, 0x03fc, 0x03ff,
    0x0401, 0x0404, 0x0407, 0x0409, 0x040c, 0x040f, 0x0412, 0x0414, 0x0417,
    0x041a, 0x041c, 0x041f, 0x0422, 0x0424, 0x0427, 0x042a, 0x042c, 0x042f,
    0x0432, 0x0435, 0x0437, 0x043a, 0x043d, 0x043f, 0x0442, 0x0444, 0x0447,
    0x044a, 0x044c, 0x044f, 0x0452, 0x0454, 0x0457, 0x045a, 0x045c, 0x045f,
    0x0462, 0x0464, 0x0467, 0x0469, 0x046c, 0x046f, 0x0471, 0x0474, 0x0476,
    0x0479, 0x047c, 0x047e, 0x0481, 0x0483, 0x0486, 0x0489, 0x048b, 0x048e,
    0x0490, 0x0493, 0x0496, 0x0498, 0x049b, 0x049d, 0x04a0, 0x04a2, 0x04a5,
    0x04a7, 0x04aa, 0x04ad, 0x04af, 0x04b2, 0x04b4, 0x04b7, 0x04b9, 0x04bc,
    0x04be, 0x04c1, 0x04c3, 0x04c6, 0x04c8, 0x04cb, 0x04cd, 0x04d0, 0x04d2,
    0x04d5, 0x04d7, 0x04da, 0x04dc, 0x04df, 0x04e1, 0x04e4, 0x04e6, 0x04e9,
    0x04eb, 0x04ee, 0x04f0, 0x04f3, 0x04f5, 0x04f8, 0x04fa, 0x04fd, 0x04ff,
    0x0502, 0x0504, 0x0506, 0x0509, 0x050b, 0x050e, 0x0510, 0x0513, 0x0515,
    0x0517, 0x051a, 0x051c, 0x051f, 0x0521, 0x0524, 0x0526, 0x0528, 0x052b,
    0x052d, 0x0530, 0x0532, 0x0534, 0x0537, 0x0539, 0x053b, 0x053e, 0x0540,
    0x0543, 0x0545, 0x0547, 0x054a, 0x054c, 0x054e, 0x0551, 0x0553, 0x0555,
    0x0558, 0x055a, 0x055c, 0x055f, 0x0561, 0x0563, 0x0566, 0x0568, 0x056a,
    0x056d, 0x056f, 0x0571, 0x0573, 0x0576, 0x0578, 0x057a, 0x057d, 0x057f,
    0x0581, 0x0583, 0x0586, 0x0588, 0x058a, 0x058d, 0x058f, 0x0591, 0x0593,
    0x0596, 0x0598, 0x059a, 0x059c, 0x059f, 0x05a1, 0x05a3, 0x05a5, 0x05a7,
    0x05aa, 0x05ac, 0x05ae, 0x05b0, 0x05b3, 0x05b5, 0x05b7, 0x05b9, 0x05bb,
    0x05bd, 0x05c0, 0x05c2, 0x05c4, 0x05c6, 0x05c8, 0x05cb, 0x05cd, 0x05cf,
    0x05d1, 0x05d3, 0x05d5, 0x05d7, 0x05da, 0x05dc, 0x05de, 0x05e0, 0x05e2,
    0x05e4, 0x05e6, 0x05e9, 0x05eb, 0x05ed, 0x05ef, 0x05f1, 0x05f3, 0x05f5,
    0x05f7, 0x05f9, 0x05fb, 0x05fd, 0x0600, 0x0602, 0x0604, 0x0606, 0x0608,
    0x060a, 0x060c, 0x060e, 0x0610, 0x0612, 0x0614, 0x0616, 0x0618, 0x061a,
    0x061c, 0x061e, 0x0620, 0x0622, 0x0624, 0x0626, 0x0628, 0x062a, 0x062c,
    0x062e, 0x0630, 0x0632, 0x0634, 0x0636, 0x0638, 0x063a, 0x063c, 0x063e,
    0x0640, 0x0642, 0x0644, 0x0646, 0x0648, 0x064a, 0x064c, 0x064e, 0x0650,
    0x0652, 0x0654, 0x0655, 0x0657, 0x0659, 0x065b, 0x065d, 0x065f, 0x0661,
    0x0663, 0x0665, 0x0667, 0x0668, 0x066a, 0x066c, 0x066e, 0x0670, 0x0672,
    0x0674, 0x0675, 0x0677, 0x0679, 0x067b, 0x067d, 0x067f, 0x0681, 0x0682,
    0x0684, 0x0686, 0x0688, 0x068a, 0x068b, 0x068d, 0x068f, 0x0691, 0x0693,
    0x0694, 0x0696, 0x0698, 0x069a, 0x069b, 0x069d, 0x069f, 0x06a1, 0x06a3,
    0x06a4, 0x06a6, 0x06a8, 0x06a9, 0x06ab, 0x06ad, 0x06af, 0x06b0, 0x06b2,
    0x06b4, 0x06b6, 0x06b7, 0x06b9, 0x06bb, 0x06bc, 0x06be, 0x06c0, 0x06c1,
    0x06c3, 0x06c5, 0x06c6, 0x06c8, 0x06ca, 0x06cb, 0x06cd, 0x06cf, 0x06d0,
    0x06d2, 0x06d4, 0x06d5, 0x06d7, 0x06d9, 0x06da, 0x06dc, 0x06dd, 0x06df,
    0x06e1, 0x06e2, 0x06e4, 0x06e5, 0x06e7, 0x06e9, 0x06ea, 0x06ec, 0x06ed,
    0x06ef, 0x06f0, 0x06f2, 0x06f4, 0x06f5, 0x06f7, 0x06f8, 0x06fa, 0x06fb,
    0x06fd, 0x06fe, 0x0700, 0x0701, 0x0703, 0x0704, 0x0706, 0x0707, 0x0709,
    0x070a, 0x070c, 0x070d, 0x070f, 0x0710, 0x0712, 0x0713, 0x0715, 0x0716,
    0x0718, 0x0719, 0x071a, 0x071c, 0x071d, 0x071f, 0x0720, 0x0722, 0x0723,
    0x0724, 0x0726, 0x0727, 0x0729, 0x072a, 0x072b, 0x072d, 0x072e, 0x0730,
    0x0731, 0x0732, 0x0734, 0x0735, 0x0736, 0x0738, 0x0739, 0x073a, 0x073c,
    0x073d, 0x073e, 0x0740, 0x0741, 0x0742, 0x0744, 0x0745, 0x0746, 0x0748,
    0x0749, 0x074a, 0x074c, 0x074d, 0x074e, 0x074f, 0x0751, 0x0752, 0x0753,
    0x0754, 0x0756, 0x0757, 0x0758, 0x0759, 0x075b, 0x075c, 0x075d, 0x075e,
    0x0760, 0x0761, 0x0762, 0x0763, 0x0764, 0x0766, 0x0767, 0x0768, 0x0769,
    0x076a, 0x076b, 0x076d, 0x076e, 0x076f, 0x0770, 0x0771, 0x0772, 0x0774,
    0x0775, 0x0776, 0x0777, 0x0778, 0x0779, 0x077a, 0x077b, 0x077d, 0x077e,
    0x077f, 0x0780, 0x0781, 0x0782, 0x0783, 0x0784, 0x0785, 0x0786, 0x0787,
    0x0788, 0x0789, 0x078a, 0x078c, 0x078d, 0x078e, 0x078f, 0x0790, 0x0791,
    0x0792, 0x0793, 0x0794, 0x0795, 0x0796, 0x0797, 0x0798, 0x0799, 0x079a,
    0x079b, 0x079c, 0x079d, 0x079e, 0x079e, 0x079f, 0x07a0, 0x07a1, 0x07a2,
    0x07a3, 0x07a4, 0x07a5, 0x07a6, 0x07a7, 0x07a8, 0x07a9, 0x07aa, 0x07aa,
    0x07ab, 0x07ac, 0x07ad, 0x07ae, 0x07af, 0x07b0, 0x07b1, 0x07b1, 0x07b2,
    0x07b3, 0x07b4, 0x07b5, 0x07b6, 0x07b7, 0x07b7, 0x07b8, 0x07b9, 0x07ba,
    0x07bb, 0x07bb, 0x07bc, 0x07bd, 0x07be, 0x07bf, 0x07bf, 0x07c0, 0x07c1,
    0x07c2, 0x07c2, 0x07c3, 0x07c4, 0x07c5, 0x07c5, 0x07c6, 0x07c7, 0x07c8,
    0x07c8, 0x07c9, 0x07ca, 0x07ca, 0x07cb, 0x07cc, 0x07cd, 0x07cd, 0x07ce,
    0x07cf, 0x07cf, 0x07d0, 0x07d1, 0x07d1, 0x07d2, 0x07d3, 0x07d3, 0x07d4,
    0x07d5, 0x07d5, 0x07d6, 0x07d6, 0x07d7, 0x07d8, 0x07d8, 0x07d9, 0x07d9,
    0x07da, 0x07db, 0x07db, 0x07dc, 0x07dc, 0x07dd, 0x07de, 0x07de, 0x07df,
    0x07df, 0x07e0, 0x07e0, 0x07e1, 0x07e1, 0x07e2, 0x07e2, 0x07e3, 0x07e3,
    0x07e4, 0x07e5, 0x07e5, 0x07e6, 0x07e6, 0x07e6, 0x07e7, 0x07e7, 0x07e8,
    0x07e8, 0x07e9, 0x07e9, 0x07ea, 0x07ea, 0x07eb, 0x07eb, 0x07ec, 0x07ec,
    0x07ec, 0x07ed, 0x07ed, 0x07ee, 0x07ee, 0x07ee, 0x07ef, 0x07ef, 0x07f0,
    0x07f0, 0x07f0, 0x07f1, 0x07f1, 0x07f1, 0x07f2, 0x07f2, 0x07f3, 0x07f3,
    0x07f3, 0x07f4, 0x07f4, 0x07f4, 0x07f5, 0x07f5, 0x07f5, 0x07f5, 0x07f6,
    0x07f6, 0x07f6, 0x07f7, 0x07f7, 0x07f7, 0x07f7, 0x07f8, 0x07f8, 0x07f8,
    0x07f8, 0x07f9, 0x07f9, 0x07f9, 0x07f9, 0x07fa, 0x07fa, 0x07fa, 0x07fa,
    0x07fb, 0x07fb, 0x07fb, 0x07fb, 0x07fb, 0x07fc, 0x07fc, 0x07fc, 0x07fc,
    0x07fc, 0x07fc, 0x07fd, 0x07fd, 0x07fd, 0x07fd, 0x07fd, 0x07fd, 0x07fd,
    0x07fd, 0x07fe, 0x07fe, 0x07fe, 0x07fe, 0x07fe, 0x07fe, 0x07fe, 0x07fe,
    0x07fe, 0x07fe, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff,
    0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff};

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
/* --- Final do Arquivo macros.h --- */
