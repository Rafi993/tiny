# Tiny

This is a tiny alternative to electron

## Why?

Electron is big and sometime you may not need all it is functionality to build your desktop app. This package renders webview with basic window management functionality without all electron API's cutting down the size drastically and improving performance. It renders webview using https://github.com/webview/webview C++ library.

## Installation

make sure you have these [native dependencies](./dependencies.md) installed then install package using npm

```
$ npm i tinytron
```

or 

```
$ yarn add tinytron

```

## Usage

```javascript
const Tiny = require("tinytron")

const window = new Tiny();
window.setSize(500, 600);
window.setTitle("Your app");

// When using your own app use express to run the server and pass the url
window.navigate("http://dev.to/");
window.run();
window.destroy()
```
