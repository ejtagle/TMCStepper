#include "TMCStepper.h"
#include "TMC_MACROS.h"

#define SET_REG(SETTING) SHORT_CONF_register.SETTING = B; WRITE_REG(SHORT_CONF);
#define GET_REG(SETTING) return SHORT_CONF_register.SETTING;

uint32_t TMC5160Stepper::SHORT_CONF() { return SHORT_CONF_register.sr; }
void TMC5160Stepper::SHORT_CONF(uint32_t input) {
	SHORT_CONF_register.sr = input;
	WRITE_REG(SHORT_CONF);
}

void TMC5160Stepper::s2vs_level(uint8_t B)	{ SET_REG(s2vs_level);	}
void TMC5160Stepper::s2g_level(uint8_t B)	{ SET_REG(s2g_level);	}
void TMC5160Stepper::shortfilter(uint8_t B)	{ SET_REG(shortfilter);	}
void TMC5160Stepper::shortdelay(bool B)		{ SET_REG(shortdelay);	}
uint8_t TMC5160Stepper::s2vs_level()		{ GET_REG(s2vs_level);	}
uint8_t TMC5160Stepper::s2g_level()			{ GET_REG(s2g_level);	}
uint8_t TMC5160Stepper::shortfilter()		{ GET_REG(shortfilter);	}
bool TMC5160Stepper::shortdelay()			{ GET_REG(shortdelay);	}