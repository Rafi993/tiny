var addon = require('bindings')('addon');

const window = new addon.Tiny();
window.setSize(400, 300);
window.setTitle("Hello World");
window.navigate("https://en.m.wikipedia.org/wiki/Main_Page");
window.run();
// window.destroy()