#ifndef ARDUPY_SI114X_H
#define ARDUPY_SI114X_H
#ifdef __cplusplus
extern "C"
{
#endif
#include "py/objtype.h"
#include "shared-bindings/util.h"
    void common_hal_si114x_construct(abstract_module_t * self);
    void common_hal_si114x_deinit(abstract_module_t * self);
    uint16_t common_hal_si114x_ReadVisible(abstract_module_t * self);
    uint16_t common_hal_si114x_ReadIR(abstract_module_t * self);
    uint16_t common_hal_si114x_ReadUV(abstract_module_t * self);
#ifdef __cplusplus
}
#endif
#endif 