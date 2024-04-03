#include <bios\ADuC7126Bits.h>

volatile __gpiocon_bits GP0CON_bit __attribute__((at(0xfffff400), zero_init));
volatile __gpiocon_bits GP1CON_bit __attribute__((at(0xfffff404), zero_init));
volatile __gpiocon_bits GP2CON_bit __attribute__((at(0xfffff408), zero_init));
volatile __gpiocon_bits GP3CON_bit __attribute__((at(0xfffff40c), zero_init));
volatile __gpiocon_bits GP4CON_bit __attribute__((at(0xfffff410), zero_init));

volatile __gpiopar_bits GP0PAR_bit __attribute__((at(0xfffff42c), zero_init));
volatile __gpiopar_bits GP1PAR_bit __attribute__((at(0xfffff43c), zero_init));
volatile __gpiopar_bits GP2PAR_bit __attribute__((at(0xfffff44c), zero_init));
volatile __gpiopar_bits GP3PAR_bit __attribute__((at(0xfffff45c), zero_init));
volatile __gpiopar_bits GP4PAR_bit __attribute__((at(0xfffff46c), zero_init));

volatile __gpiodat_bits GP0DAT_bit __attribute__((at(0xfffff420), zero_init));
volatile __gpiodat_bits GP1DAT_bit __attribute__((at(0xfffff430), zero_init));
volatile __gpiodat_bits GP2DAT_bit __attribute__((at(0xfffff440), zero_init));
volatile __gpiodat_bits GP3DAT_bit __attribute__((at(0xfffff450), zero_init));
volatile __gpiodat_bits GP4DAT_bit __attribute__((at(0xfffff460), zero_init));

volatile __gpiosetclr_bits GP0SET_bit __attribute__((at(0xfffff424), zero_init));
volatile __gpiosetclr_bits GP1SET_bit __attribute__((at(0xfffff434), zero_init));
volatile __gpiosetclr_bits GP2SET_bit __attribute__((at(0xfffff444), zero_init));
volatile __gpiosetclr_bits GP3SET_bit __attribute__((at(0xfffff454), zero_init));
volatile __gpiosetclr_bits GP4SET_bit __attribute__((at(0xfffff464), zero_init));

volatile __gpiosetclr_bits GP0CLR_bit __attribute__((at(0xfffff428), zero_init));
volatile __gpiosetclr_bits GP1CLR_bit __attribute__((at(0xfffff438), zero_init));
volatile __gpiosetclr_bits GP2CLR_bit __attribute__((at(0xfffff448), zero_init));
volatile __gpiosetclr_bits GP3CLR_bit __attribute__((at(0xfffff458), zero_init));
volatile __gpiosetclr_bits GP4CLR_bit __attribute__((at(0xfffff468), zero_init));

volatile __irqfiq_bits IRQSTA_bit __attribute__((at(0xffff0000), zero_init));
volatile __irqfiq_bits IRQSIG_bit __attribute__((at(0xffff0004), zero_init));
volatile __irqfiq_bits IRQEN_bit __attribute__((at(0xffff0008), zero_init));
volatile __irqfiq_bits IRQCLR_bit __attribute__((at(0xffff000C), zero_init));
volatile __irqfiq_bits FIQSTA_bit __attribute__((at(0xffff0100), zero_init));
volatile __irqfiq_bits FIQSIG_bit __attribute__((at(0xffff0104), zero_init));
volatile __irqfiq_bits FIQEN_bit __attribute__((at(0xffff0108), zero_init));
volatile __irqfiq_bits FIQCLR_bit __attribute__((at(0xffff010C), zero_init));

volatile __irqconn_bits IRQCONN_bit __attribute__((at(0xffff0030), zero_init));

volatile __irqcone_bits IRQCONE_bit __attribute__((at(0xffff0034), zero_init));

volatile __irqclre_bits IRQCLRE_bit __attribute__((at(0xffff0038), zero_init));

volatile __pwmcon0_bits PWMCON0_bit __attribute__((at(0xffff0f80), zero_init));

volatile __plaelm_bits PLAELM0_bit __attribute__((at(0xffff0b00), zero_init));
volatile __plaelm_bits PLAELM1_bit __attribute__((at(0xffff0b04), zero_init));
volatile __plaelm_bits PLAELM2_bit __attribute__((at(0xffff0b08), zero_init));
volatile __plaelm_bits PLAELM3_bit __attribute__((at(0xffff0b0c), zero_init));
volatile __plaelm_bits PLAELM4_bit __attribute__((at(0xffff0b10), zero_init));
volatile __plaelm_bits PLAELM5_bit __attribute__((at(0xffff0b14), zero_init));
volatile __plaelm_bits PLAELM6_bit __attribute__((at(0xffff0b18), zero_init));
volatile __plaelm_bits PLAELM7_bit __attribute__((at(0xffff0b1c), zero_init));
volatile __plaelm_bits PLAELM8_bit __attribute__((at(0xffff0b20), zero_init));
volatile __plaelm_bits PLAELM9_bit __attribute__((at(0xffff0b24), zero_init));
volatile __plaelm_bits PLAELM10_bit __attribute__((at(0xffff0b28), zero_init));
volatile __plaelm_bits PLAELM11_bit __attribute__((at(0xffff0b2c), zero_init));
volatile __plaelm_bits PLAELM12_bit __attribute__((at(0xffff0b30), zero_init));
volatile __plaelm_bits PLAELM13_bit __attribute__((at(0xffff0b34), zero_init));
volatile __plaelm_bits PLAELM14_bit __attribute__((at(0xffff0b38), zero_init));
volatile __plaelm_bits PLAELM15_bit __attribute__((at(0xffff0b3c), zero_init));

volatile __placlk_bits PLACLK_bit __attribute__((at(0xffff0b40), zero_init));

volatile __plairq_bits PLAIRQ_bit __attribute__((at(0xffff0b44), zero_init));

volatile __adccon_bits ADCCON_bit __attribute__((at(0xffff0500), zero_init));

volatile __adcdat_bits ADCDAT_bit __attribute__((at(0xffff0510), zero_init));

volatile __tempref_bits TEMPREF_bit __attribute__((at(0xffff0548), zero_init));

volatile __refcon_bits REFCON_bit __attribute__((at(0xffff048c), zero_init));

volatile __comien0_bits COM0IEN0_bit __attribute__((at(0xffff0704), zero_init));
volatile __comien0_bits COM1IEN0_bit __attribute__((at(0xffff0744), zero_init));

volatile __comiid0_bits COM0IID0_bit __attribute__((at(0xffff0708), zero_init));
volatile __comiid0_bits COM1IID0_bit __attribute__((at(0xffff0748), zero_init));

//because this is write only register
//volatile __comfcr_bits COM0FCR_bit __attribute__((at(0xffff0708), zero_init));
//volatile __comfcr_bits COM1FCR_bit __attribute__((at(0xffff0748), zero_init));

volatile __comcon0_bits COM0CON0_bit __attribute__((at(0xffff070c), zero_init));
volatile __comcon0_bits COM1CON0_bit __attribute__((at(0xffff074c), zero_init));

volatile __comcon1_bits COM0CON1_bit __attribute__((at(0xffff0710), zero_init));
volatile __comcon1_bits COM1CON1_bit __attribute__((at(0xffff0750), zero_init));

volatile __comsta0_bits COM0STA0_bit __attribute__((at(0xffff0714), zero_init));
volatile __comsta0_bits COM1STA0_bit __attribute__((at(0xffff0754), zero_init));

volatile __comsta1_bits COM0STA1_bit __attribute__((at(0xffff0718), zero_init));
volatile __comsta1_bits COM1STA1_bit __attribute__((at(0xffff0758), zero_init));

volatile __comdiv2_bits COM0DIV2_bit __attribute__((at(0xffff072c), zero_init));
volatile __comdiv2_bits COM1DIV2_bit __attribute__((at(0xffff076c), zero_init));

volatile __t0con_bits T0CON_bit __attribute__((at(0xffff0308), zero_init));

volatile __t1con_bits T1CON_bit __attribute__((at(0xffff0328), zero_init));

volatile __t2con_bits T2CON_bit __attribute__((at(0xffff0348), zero_init));

volatile __t3con_bits T3CON_bit __attribute__((at(0xffff0368), zero_init));

volatile __feeadr_bits FEE0ADR_bit __attribute__((at(0xfffff810), zero_init));
volatile __feeadr_bits FEE1ADR_bit __attribute__((at(0xfffff890), zero_init));

volatile __feemod_bits FEE0MOD_bit __attribute__((at(0xfffff804), zero_init));
volatile __feemod_bits FEE1MOD_bit __attribute__((at(0xfffff884), zero_init));

volatile __feesta_bits FEE0STA_bit __attribute__((at(0xfffff800), zero_init));
volatile __feesta_bits FEE1STA_bit __attribute__((at(0xfffff880), zero_init));





