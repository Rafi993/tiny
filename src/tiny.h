#ifndef TINY_H
#define TINY_H

#include "webview.h"
#include <napi.h>

class Tiny : public Napi::ObjectWrap<Tiny>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Tiny(const Napi::CallbackInfo &info);

private:
  void SetTitle(const Napi::CallbackInfo &info);
  void SetSize(const Napi::CallbackInfo &info);
  void Navigate(const Napi::CallbackInfo &info);
  void Run(const Napi::CallbackInfo &info);
  void Destroy(const Napi::CallbackInfo &info);

  webview::webview window_;
};

#endif