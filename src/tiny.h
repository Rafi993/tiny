#ifndef TINY_H
#define TINY_H

#include <napi.h>

class Tiny : public Napi::ObjectWrap<MyObject>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  MyObject(const Napi::CallbackInfo &info);

private:
}

#endif