#ifndef WINDOW_WORKER_H
#define WINDOW_WORKER_H

#include <napi.h>
#include "webview.h"

using namespace Napi;

class WindowWorker : public AsyncWorker
{
public:
    WindowWorker(webview::webview window_, Function &callback);

    void Execute();
    void OnOK();

private:
    webview::webview window_;
};

WindowWorker::WindowWorker(webview::webview window_, Function &callback) : AsyncWorker(callback)
{
    this->window_ = window_;
}

void WindowWorker::Execute()
{
    this->window_.run();
}

void WindowWorker::OnOK()
{
    Callback().Call({});
}

#endif