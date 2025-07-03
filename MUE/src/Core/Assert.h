#pragma once

#include <Core/Log.h>

#define MUE_ASSERT(check,msg,...) {if(!check){MFATAL_CORE(msg,__VA_ARGS__); MUE_BREAK();}}

#define MUE_ASSERT_NO_MSG(check) {if(!check){MFATAL_CORE("Assert failed at: {0} {1} in {2}",__LINE__,__FUNCTION__,__FILE__); MUE_BREAK();}}