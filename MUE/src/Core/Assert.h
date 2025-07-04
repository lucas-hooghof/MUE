#pragma once

#include <Core/Log.h>

#define MUE_ASSERT(check) {if(!(check)){MFATAL_CORE("Assert failed:\n\tCheck: {0} at \n\tLine: {1}\n\tFunction: {2} \n\tFile: {3}",#check,__LINE__,__FUNCTION__,__FILE__); MUE_BREAK();}}