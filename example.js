const Tiny = require("./lib/bindings")

const window = new Tiny();
window.setSize(500, 600);
window.setTitle("Your app");

// When using your own app use express to run the server and pass the url
window.navigate("http://dev.to/");
window.run();
window.destroy()