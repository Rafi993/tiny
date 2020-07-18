# Tiny

This is a tiny alternative to electron

## Why?

Electron is big and sometime you may not need all it is functionality to build your desktop. This package renders webview with basic window management functionality without all electron API's cutting down the size drastically and improving performance. It renders webview using https://github.com/webview/webview C++ library.

## Usage

```javascript
const Tiny = require("tiny");

const window = Tiny();
window.setSize(400, 300);
window.setTitle("Hello World");
window.setURL("https://github.com/nodejs/node-addon-api");
```
