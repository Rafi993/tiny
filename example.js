const Tiny = require("./index");

const window = new Tiny();
window.setSize(500, 600);
window.setTitle("Your app");

// When using your own app use express to run the server and pass the url
window.navigate("http://dev.to/");
window.run(() => {
  console.log("window has been closed");
});
