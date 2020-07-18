#include "tiny.h"
#include "webview.h"

Napi::Object Tiny::Init(Napi::Env env, Napi::Object exports)
{

  Napi::Function func =
      DefineClass(env,
                  "Tiny",
                  {InstanceMethod("setTitle", &Tiny::SetTitle),
                   InstanceMethod("setSize", &Tiny::SetSize),
                   InstanceMethod("navigate", &Tiny::Navigate),
                   InstanceMethod("run", &Tiny::Run),
                   InstanceMethod("destroy", &Tiny::Destroy)});

  Napi::FunctionReference *constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);

  exports.Set("Tiny", func);
  return exports;
}

Tiny::Tiny(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Tiny>(info)
{
  Napi::Env env = info.Env();

  if (info.Length() > 0)
  {
    Napi::TypeError::New(env, "It does not take any arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  webview::webview window(true, nullptr);
  this->window_ = window;
}

void Tiny::SetTitle(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 1)
  {

    Napi::TypeError::New(env, "You have to supply title")
        .ThrowAsJavaScriptException();
  }

  if (!info[0].IsString())
  {
    Napi::TypeError::New(env, "title should be string").ThrowAsJavaScriptException();
  }

  const char *title = (int)info[0].As<Napi::String>().Utf8Value();
  this->window_.set_title(title);
}

void Tiny::Navigate(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 1)
  {

    Napi::TypeError::New(env, "You have to supply URL")
        .ThrowAsJavaScriptException();
  }

  if (!info[0].IsString())
  {
    Napi::TypeError::New(env, "URL should be string").ThrowAsJavaScriptException();
  }

  const char *url = (int)info[0].As<Napi::String>().Utf8Value();
  this->window_.navigate(url);
}

void Tiny::SetSize(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

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

  if (info.Length() > 0)
  {
    Napi::TypeError::New(env, "It does not take any arguments")
        .ThrowAsJavaScriptException();
  }

  this->window_.destroy();
}
