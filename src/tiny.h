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
  static Napi::FunctionReference constructor;

  void SetTitle(const Napi::CallbackInfo &info);
  void SetSize(const Napi::CallbackInfo &info);
  void Navigate(const Napi::CallbackInfo &info);
  void Run(const Napi::CallbackInfo &info);
  void Destroy(const Napi::CallbackInfo &info);

  webview::webview window_;
};


Napi::FunctionReference Tiny::constructor;

Napi::Object Tiny::Init(Napi::Env env, Napi::Object exports)
{
  Napi::HandleScope scope(env);

  Napi::Function func =
      DefineClass(env,
                  "Tiny",
                  {InstanceMethod("setTitle", &Tiny::SetTitle),
                   InstanceMethod("setSize", &Tiny::SetSize),
                   InstanceMethod("navigate", &Tiny::Navigate),
                   InstanceMethod("run", &Tiny::Run),
                   InstanceMethod("destroy", &Tiny::Destroy)});

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Tiny", func);
  return exports;
}

Tiny::Tiny(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Tiny>(info)
{
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() > 0)
  {
    Napi::TypeError::New(env, "It does not take any arguments")
        .ThrowAsJavaScriptException();
  }

  webview::webview window(true, nullptr);
  this->window_ = window;
}

void Tiny::SetTitle(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() < 1)
  {

    Napi::TypeError::New(env, "You have to supply title")
        .ThrowAsJavaScriptException();
  }

  if (!info[0].IsString())
  {
    Napi::TypeError::New(env, "title should be string").ThrowAsJavaScriptException();
  }

  std::string str = info[0].ToString().Utf8Value();
  const char *title = str.c_str();
  this->window_.set_title(title);
}

void Tiny::Navigate(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() < 1)
  {

    Napi::TypeError::New(env, "You have to supply URL")
        .ThrowAsJavaScriptException();
  }

  if (!info[0].IsString())
  {
    Napi::TypeError::New(env, "URL should be string").ThrowAsJavaScriptException();
  }

  std::string str = info[0].ToString().Utf8Value();
  const char *url = str.c_str();
  this->window_.navigate(url);
}

void Tiny::SetSize(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() < 2)
  {
    Napi::TypeError::New(env, "You need to give width and height")
        .ThrowAsJavaScriptException();
  }

  if (!info[0].IsNumber() || !info[1].IsNumber())
  {
    Napi::TypeError::New(env, "width and height should be numbers").ThrowAsJavaScriptException();
  }

  int width = (int)info[0].As<Napi::Number>().Int64Value();
  int height = info[1].As<Napi::Number>().Int64Value();
  this->window_.set_size(width, height, WEBVIEW_HINT_NONE);
}

void Tiny::Run(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() > 0)
  {
    Napi::TypeError::New(env, "It does not take any arguments")
        .ThrowAsJavaScriptException();
  }

  this->window_.run();
}

void Tiny::Destroy(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() > 0)
  {
    Napi::TypeError::New(env, "It does not take any arguments")
        .ThrowAsJavaScriptException();
  }

  // this->window_.destroy();
}


#endif