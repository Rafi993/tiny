#include <napi.h>
#include "tiny.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
  return Tiny::Init(env, exports);
}

NODE_API_MODULE(addon, InitAll)