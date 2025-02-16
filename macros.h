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
    0x0039, 0x003c, 0x003f, 0x0042, 0x0045, 0x0048, 0x004b, 0x004f, 0x0052,
    0x0055, 0x0058, 0x005b, 0x005e, 0x0061, 0x0064, 0x0068, 0x006b, 0x006e,
    0x0071, 0x0074, 0x0077, 0x007a, 0x007e, 0x0081, 0x0084, 0x0087, 0x008a,
    0x008d, 0x0090, 0x0094, 0x0097, 0x009a, 0x009d, 0x00a0, 0x00a3, 0x00a6,
    0x00a9, 0x00ad, 0x00b0, 0x00b3, 0x00b6, 0x00b9, 0x00bc, 0x00bf, 0x00c2,
    0x00c6, 0x00c9, 0x00cc, 0x00cf, 0x00d2, 0x00d5, 0x00d8, 0x00db, 0x00df,
    0x00e2, 0x00e5, 0x00e8, 0x00eb, 0x00ee, 0x00f1, 0x00f4, 0x00f8, 0x00fb,
    0x00fe, 0x0101, 0x0104, 0x0107, 0x010a, 0x010d, 0x0111, 0x0114, 0x0117,
    0x011a, 0x011d, 0x0120, 0x0123, 0x0126, 0x0129, 0x012d, 0x0130, 0x0133,
    0x0136, 0x0139, 0x013c, 0x013f, 0x0142, 0x0145, 0x0148, 0x014c, 0x014f,
    0x0152, 0x0155, 0x0158, 0x015b, 0x015e, 0x0161, 0x0164, 0x0167, 0x016b,
    0x016e, 0x0171, 0x0174, 0x0177, 0x017a, 0x017d, 0x0180, 0x0183, 0x0186,
    0x0189, 0x018c, 0x0190, 0x0193, 0x0196, 0x0199, 0x019c, 0x019f, 0x01a2,
    0x01a5, 0x01a8, 0x01ab, 0x01ae, 0x01b1, 0x01b4, 0x01b8, 0x01bb, 0x01be,
    0x01c1, 0x01c4, 0x01c7, 0x01ca, 0x01cd, 0x01d0, 0x01d3, 0x01d6, 0x01d9,
    0x01dc, 0x01df, 0x01e2, 0x01e5, 0x01e8, 0x01ec, 0x01ef, 0x01f2, 0x01f5,
    0x01f8, 0x01fb, 0x01fe, 0x0201, 0x0204, 0x0207, 0x020a, 0x020d, 0x0210,
    0x0213, 0x0216, 0x0219, 0x021c, 0x021f, 0x0222, 0x0225, 0x0228, 0x022b,
    0x022e, 0x0231, 0x0234, 0x0237, 0x023a, 0x023d, 0x0240, 0x0243, 0x0246,
    0x0249, 0x024c, 0x024f, 0x0253, 0x0256, 0x0259, 0x025c, 0x025f, 0x0262,
    0x0265, 0x0268, 0x026b, 0x026e, 0x0270, 0x0273, 0x0276, 0x0279, 0x027c,
    0x027f, 0x0282, 0x0285, 0x0288, 0x028b, 0x028e, 0x0291, 0x0294, 0x0297,
    0x029a, 0x029d, 0x02a0, 0x02a3, 0x02a6, 0x02a9, 0x02ac, 0x02af, 0x02b2,
    0x02b5, 0x02b8, 0x02bb, 0x02be, 0x02c1, 0x02c4, 0x02c7, 0x02ca, 0x02cd,
    0x02cf, 0x02d2, 0x02d5, 0x02d8, 0x02db, 0x02de, 0x02e1, 0x02e4, 0x02e7,
    0x02ea, 0x02ed, 0x02f0, 0x02f3, 0x02f6, 0x02f8, 0x02fb, 0x02fe, 0x0301,
    0x0304, 0x0307, 0x030a, 0x030d, 0x0310, 0x0313, 0x0316, 0x0318, 0x031b,
    0x031e, 0x0321, 0x0324, 0x0327, 0x032a, 0x032d, 0x0330, 0x0332, 0x0335,
    0x0338, 0x033b, 0x033e, 0x0341, 0x0344, 0x0347, 0x0349, 0x034c, 0x034f,
    0x0352, 0x0355, 0x0358, 0x035b, 0x035d, 0x0360, 0x0363, 0x0366, 0x0369,
    0x036c, 0x036e, 0x0371, 0x0374, 0x0377, 0x037a, 0x037d, 0x037f, 0x0382,
    0x0385, 0x0388, 0x038b, 0x038e, 0x0390, 0x0393, 0x0396, 0x0399, 0x039c,
    0x039e, 0x03a1, 0x03a4, 0x03a7, 0x03aa, 0x03ac, 0x03af, 0x03b2, 0x03b5,
    0x03b8, 0x03ba, 0x03bd, 0x03c0, 0x03c3, 0x03c5, 0x03c8, 0x03cb, 0x03ce,
    0x03d0, 0x03d3, 0x03d6, 0x03d9, 0x03dc, 0x03de, 0x03e1, 0x03e4, 0x03e7,
    0x03e9, 0x03ec, 0x03ef, 0x03f1, 0x03f4, 0x03f7, 0x03fa, 0x03fc, 0x03ff,
    0x0402, 0x0405, 0x0407, 0x040a, 0x040d, 0x040f, 0x0412, 0x0415, 0x0417,
    0x041a, 0x041d, 0x0420, 0x0422, 0x0425, 0x0428, 0x042a, 0x042d, 0x0430,
    0x0432, 0x0435, 0x0438, 0x043a, 0x043d, 0x0440, 0x0442, 0x0445, 0x0448,
    0x044a, 0x044d, 0x0450, 0x0452, 0x0455, 0x0458, 0x045a, 0x045d, 0x045f,
    0x0462, 0x0465, 0x0467, 0x046a, 0x046d, 0x046f, 0x0472, 0x0474, 0x0477,
    0x047a, 0x047c, 0x047f, 0x0481, 0x0484, 0x0487, 0x0489, 0x048c, 0x048e,
    0x0491, 0x0494, 0x0496, 0x0499, 0x049b, 0x049e, 0x04a0, 0x04a3, 0x04a6,
    0x04a8, 0x04ab, 0x04ad, 0x04b0, 0x04b2, 0x04b5, 0x04b7, 0x04ba, 0x04bc,
    0x04bf, 0x04c1, 0x04c4, 0x04c7, 0x04c9, 0x04cc, 0x04ce, 0x04d1, 0x04d3,
    0x04d6, 0x04d8, 0x04db, 0x04dd, 0x04e0, 0x04e2, 0x04e5, 0x04e7, 0x04ea,
    0x04ec, 0x04ee, 0x04f1, 0x04f3, 0x04f6, 0x04f8, 0x04fb, 0x04fd, 0x0500,
    0x0502, 0x0505, 0x0507, 0x0509, 0x050c, 0x050e, 0x0511, 0x0513, 0x0516,
    0x0518, 0x051b, 0x051d, 0x051f, 0x0522, 0x0524, 0x0527, 0x0529, 0x052b,
    0x052e, 0x0530, 0x0533, 0x0535, 0x0537, 0x053a, 0x053c, 0x053e, 0x0541,
    0x0543, 0x0546, 0x0548, 0x054a, 0x054d, 0x054f, 0x0551, 0x0554, 0x0556,
    0x0558, 0x055b, 0x055d, 0x055f, 0x0562, 0x0564, 0x0566, 0x0569, 0x056b,
    0x056d, 0x0570, 0x0572, 0x0574, 0x0576, 0x0579, 0x057b, 0x057d, 0x0580,
    0x0582, 0x0584, 0x0586, 0x0589, 0x058b, 0x058d, 0x0590, 0x0592, 0x0594,
    0x0596, 0x0599, 0x059b, 0x059d, 0x059f, 0x05a1, 0x05a4, 0x05a6, 0x05a8,
    0x05aa, 0x05ad, 0x05af, 0x05b1, 0x05b3, 0x05b5, 0x05b8, 0x05ba, 0x05bc,
    0x05be, 0x05c0, 0x05c3, 0x05c5, 0x05c7, 0x05c9, 0x05cb, 0x05cd, 0x05d0,
    0x05d2, 0x05d4, 0x05d6, 0x05d8, 0x05da, 0x05dc, 0x05df, 0x05e1, 0x05e3,
    0x05e5, 0x05e7, 0x05e9, 0x05eb, 0x05ed, 0x05f0, 0x05f2, 0x05f4, 0x05f6,
    0x05f8, 0x05fa, 0x05fc, 0x05fe, 0x0600, 0x0602, 0x0604, 0x0607, 0x0609,
    0x060b, 0x060d, 0x060f, 0x0611, 0x0613, 0x0615, 0x0617, 0x0619, 0x061b,
    0x061d, 0x061f, 0x0621, 0x0623, 0x0625, 0x0627, 0x0629, 0x062b, 0x062d,
    0x062f, 0x0631, 0x0633, 0x0635, 0x0637, 0x0639, 0x063b, 0x063d, 0x063f,
    0x0641, 0x0643, 0x0645, 0x0647, 0x0649, 0x064b, 0x064d, 0x064f, 0x0650,
    0x0652, 0x0654, 0x0656, 0x0658, 0x065a, 0x065c, 0x065e, 0x0660, 0x0662,
    0x0664, 0x0665, 0x0667, 0x0669, 0x066b, 0x066d, 0x066f, 0x0671, 0x0673,
    0x0674, 0x0676, 0x0678, 0x067a, 0x067c, 0x067e, 0x067f, 0x0681, 0x0683,
    0x0685, 0x0687, 0x0689, 0x068a, 0x068c, 0x068e, 0x0690, 0x0692, 0x0693,
    0x0695, 0x0697, 0x0699, 0x069b, 0x069c, 0x069e, 0x06a0, 0x06a2, 0x06a3,
    0x06a5, 0x06a7, 0x06a9, 0x06aa, 0x06ac, 0x06ae, 0x06b0, 0x06b1, 0x06b3,
    0x06b5, 0x06b6, 0x06b8, 0x06ba, 0x06bc, 0x06bd, 0x06bf, 0x06c1, 0x06c2,
    0x06c4, 0x06c6, 0x06c7, 0x06c9, 0x06cb, 0x06cc, 0x06ce, 0x06d0, 0x06d1,
    0x06d3, 0x06d5, 0x06d6, 0x06d8, 0x06d9, 0x06db, 0x06dd, 0x06de, 0x06e0,
    0x06e1, 0x06e3, 0x06e5, 0x06e6, 0x06e8, 0x06e9, 0x06eb, 0x06ed, 0x06ee,
    0x06f0, 0x06f1, 0x06f3, 0x06f4, 0x06f6, 0x06f7, 0x06f9, 0x06fb, 0x06fc,
    0x06fe, 0x06ff, 0x0701, 0x0702, 0x0704, 0x0705, 0x0707, 0x0708, 0x070a,
    0x070b, 0x070d, 0x070e, 0x0710, 0x0711, 0x0713, 0x0714, 0x0716, 0x0717,
    0x0718, 0x071a, 0x071b, 0x071d, 0x071e, 0x0720, 0x0721, 0x0722, 0x0724,
    0x0725, 0x0727, 0x0728, 0x072a, 0x072b, 0x072c, 0x072e, 0x072f, 0x0730,
    0x0732, 0x0733, 0x0735, 0x0736, 0x0737, 0x0739, 0x073a, 0x073b, 0x073d,
    0x073e, 0x073f, 0x0741, 0x0742, 0x0743, 0x0745, 0x0746, 0x0747, 0x0749,
    0x074a, 0x074b, 0x074c, 0x074e, 0x074f, 0x0750, 0x0752, 0x0753, 0x0754,
    0x0755, 0x0757, 0x0758, 0x0759, 0x075a, 0x075c, 0x075d, 0x075e, 0x075f,
    0x0760, 0x0762, 0x0763, 0x0764, 0x0765, 0x0767, 0x0768, 0x0769, 0x076a,
    0x076b, 0x076c, 0x076e, 0x076f, 0x0770, 0x0771, 0x0772, 0x0773, 0x0774,
    0x0776, 0x0777, 0x0778, 0x0779, 0x077a, 0x077b, 0x077c, 0x077d, 0x077f,
    0x0780, 0x0781, 0x0782, 0x0783, 0x0784, 0x0785, 0x0786, 0x0787, 0x0788,
    0x0789, 0x078a, 0x078b, 0x078c, 0x078e, 0x078f, 0x0790, 0x0791, 0x0792,
    0x0793, 0x0794, 0x0795, 0x0796, 0x0797, 0x0798, 0x0799, 0x079a, 0x079b,
    0x079c, 0x079d, 0x079e, 0x079e, 0x079f, 0x07a0, 0x07a1, 0x07a2, 0x07a3,
    0x07a4, 0x07a5, 0x07a6, 0x07a7, 0x07a8, 0x07a9, 0x07aa, 0x07ab, 0x07ab,
    0x07ac, 0x07ad, 0x07ae, 0x07af, 0x07b0, 0x07b1, 0x07b2, 0x07b2, 0x07b3,
    0x07b4, 0x07b5, 0x07b6, 0x07b7, 0x07b7, 0x07b8, 0x07b9, 0x07ba, 0x07bb,
    0x07bc, 0x07bc, 0x07bd, 0x07be, 0x07bf, 0x07c0, 0x07c0, 0x07c1, 0x07c2,
    0x07c3, 0x07c3, 0x07c4, 0x07c5, 0x07c6, 0x07c6, 0x07c7, 0x07c8, 0x07c9,
    0x07c9, 0x07ca, 0x07cb, 0x07cb, 0x07cc, 0x07cd, 0x07ce, 0x07ce, 0x07cf,
    0x07d0, 0x07d0, 0x07d1, 0x07d2, 0x07d2, 0x07d3, 0x07d4, 0x07d4, 0x07d5,
    0x07d6, 0x07d6, 0x07d7, 0x07d7, 0x07d8, 0x07d9, 0x07d9, 0x07da, 0x07da,
    0x07db, 0x07dc, 0x07dc, 0x07dd, 0x07dd, 0x07de, 0x07df, 0x07df, 0x07e0,
    0x07e0, 0x07e1, 0x07e1, 0x07e2, 0x07e2, 0x07e3, 0x07e3, 0x07e4, 0x07e4,
    0x07e5, 0x07e5, 0x07e6, 0x07e6, 0x07e7, 0x07e7, 0x07e8, 0x07e8, 0x07e9,
    0x07e9, 0x07ea, 0x07ea, 0x07eb, 0x07eb, 0x07ec, 0x07ec, 0x07ed, 0x07ed,
    0x07ed, 0x07ee, 0x07ee, 0x07ef, 0x07ef, 0x07ef, 0x07f0, 0x07f0, 0x07f1,
    0x07f1, 0x07f1, 0x07f2, 0x07f2, 0x07f2, 0x07f3, 0x07f3, 0x07f4, 0x07f4,
    0x07f4, 0x07f5, 0x07f5, 0x07f5, 0x07f6, 0x07f6, 0x07f6, 0x07f6, 0x07f7,
    0x07f7, 0x07f7, 0x07f8, 0x07f8, 0x07f8, 0x07f8, 0x07f9, 0x07f9, 0x07f9,
    0x07f9, 0x07fa, 0x07fa, 0x07fa, 0x07fa, 0x07fb, 0x07fb, 0x07fb, 0x07fb,
    0x07fc, 0x07fc, 0x07fc, 0x07fc, 0x07fc, 0x07fd, 0x07fd, 0x07fd, 0x07fd,
    0x07fd, 0x07fd, 0x07fe, 0x07fe, 0x07fe, 0x07fe, 0x07fe, 0x07fe, 0x07fe,
    0x07fe, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff,
    0x07ff, 0x07ff, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800,
    0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800};

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
