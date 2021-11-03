let rainSound; 
let checkbox;
let states = [];

function preload() {
  states[0] = loadImage("assets/waving.png");
  states[1] = loadImage("assets/pointing.png");
  states[2] = loadImage("assets/celebrating.png");
  soundFormats("mp3");
  rainSound = loadSound("assets/rainSound");
}

function setup() {
  let canvas = createCanvas(400, 445);
  canvas.parent("mascot-container");

  checkbox = select('#music-toggle');
  
  checkbox.changed(onToggle);
}

function draw() {
  background("#dce8e8");
  image(states[state], 0, 0, 400, 445);
}

function onToggle() {
  console.log(checkbox.value());
  if (this.checked()) {
    rainSound.loop();
  } else {
    rainSound.pause();
  }
}