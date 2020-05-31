/**
 * The MIT License (MIT)
 *
 * Author: Junjie Chen (595355940@qq.com)
 *
 * Copyright (C) 2020  Seeed Technology Co.,Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "shared-bindings/util.h"
#include "wrapper_ardupy_si114x_hal.h"

m_generic_make(si114x) {
    abstract_module_t * self = new_abstruct_module(type);
    mp_arg_check_num(n_args, n_kw, 0, 0, false);
    common_hal_si114x_construct(self);
    return self;
}

void si114x_obj_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest){
    abstract_module_t * self = (abstract_module_t *)self_in;
    uint32_t value;
    if (dest[0] == MP_OBJ_NULL){
        if (attr == MP_QSTR_Visible) {
            value = common_hal_si114x_ReadVisible(self);
            dest[0] = mp_obj_new_int(value);
            return;
        }
        else if (attr == MP_QSTR_IR){
            value = common_hal_si114x_ReadIR(self);
            dest[0] = mp_obj_new_int(value);
            return;
        }
        else if(attr == MP_QSTR_UV){
            value = common_hal_si114x_ReadUV(self);
            dest[0] = mp_obj_new_int(value);
            return;
        }
    }
    generic_method_lookup(self_in, attr, dest);    
}   

const mp_rom_map_elem_t si114x_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_deinit),    MP_ROM_PTR(&si114x_deinit_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__),  MP_ROM_PTR(&si114x_obj___exit___obj) },
};

MP_DEFINE_CONST_DICT(si114x_locals_dict, si114x_locals_dict_table);

const mp_obj_type_t grove_si114x_type = {
    {&mp_type_type},
    .name = MP_QSTR_grove_si114x,
    .make_new = si114x_make_new,
    .locals_dict = (mp_obj_t)&si114x_locals_dict,
    .attr = &si114x_obj_attr,
};
