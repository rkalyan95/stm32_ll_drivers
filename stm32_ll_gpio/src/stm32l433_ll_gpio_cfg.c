#include "stm32l433_ll_gpio_cfg.h"

//Warning : DO not change the Pa13 and Pa14 configs please , because they are used for debugger.

volatile GPIOA_MODER_Reg_t GPIOA_MODER_Reg = {.U = 0xABFFFFFF
};

volatile GPIOB_MODER_Reg_t GPIOB_MODER_Reg = { .U = 0xFFFFFEBF
};

volatile GPIOC_MODER_Reg_t GPIOC_MODER_Reg = { .U = 0xFFFFFFFF
};

volatile GPIOD_MODER_Reg_t GPIOD_MODER_Reg = { .U = 0xFFFFFFFF
};

volatile GPIOE_MODER_Reg_t GPIOE_MODER_Reg = { .U = 0xFFFFFFFF
};

volatile GPIOH_MODER_Reg_t GPIOH_MODER_Reg = { .U =0x0000000F
};

