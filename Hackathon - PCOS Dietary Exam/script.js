/*
  project name: PCOS I'm Hungry!
  authors: Mishaal and Beaux :D
  description: 
*/

//aliases - to save time writing the longer name over and over again
var Engine          = Matter.Engine,
    Render          = Matter.Render,
    Runner          = Matter.Runner,
    Bodies          = Matter.Bodies,
    Composite       = Matter.Composite,
    Common          = Matter.Common,
    Constraint      = Matter.Constraint,
    Vector          = Matter.Vector,
    Vertices        = Matter.Vertices,
    Mouse           = Matter.Mouse,
    MouseConstraint = Matter.MouseConstraint,
    SAT             = Matter.SAT;

// global variables
var canvas;
var engine;
var world;
var mouse;
var mouseConstraint;

var state = 0;
var score = 0;
var index = 0;

var food = [];
var foodInfo = [];

var trashcan;
var trashcanSensor;

var plate;
var plateSensor;

var sign;

var fryingPan;

// image files
var bgImg;
var hotdogImg;
var trashcanImg;
var darkChocoImg;
var fishImg;
var toastImg;
var signImg;
var sodaImg;
var steakImg;
var friedChickenImg;
var gingerImg;
var spinachImg;
var grapeImg;
var leafImg;
var fryingPanImg
var plateImg;

var myFont;

function preload() { // this has to load before the program starts
  // images
  bgImg = loadImage("assets/bg.png");
  hotdogImg = loadImage("assets/hotdog.png");
  trashcanImg = loadImage("assets/trashcan.png");
  darkChocoImg = loadImage("assets/darkchoco.png");
  fishImg = loadImage("assets/fish.png");
  toastImg = loadImage("assets/toast.png");
  signImg = loadImage("assets/sign.png");
  sodaImg = loadImage("assets/dietSoda.png");
  steakImg = loadImage("assets/steak.png");
  friedChickenImg = loadImage("assets/friedChicken.png");
  gingerImg = loadImage("assets/ginger.png");
  spinachImg = loadImage("assets/spinach.png");
  grapeImg = loadImage("assets/grape.png");
  leafImg = loadImage("assets/leaf.png");
  fryingPanImg = loadImage("assets/fryingPan.png");
  plateImg = loadImage("assets/plate.png");
  
  // fonts
  myFont = loadFont('assets/Nunito-Bold.ttf');
}

function setup() { // ran once at the start
  canvas = createCanvas(1000, 600);
  foodInfo = [
    {
      id: "hotdog",
      type: "chain",
      x: width/2,
      y: 20,
      w: 20,
      h: 60,
      n: 3,
      img: hotdogImg,
      options: { restitution: 1 },
      isThrown: true,
      description: "Processed meats like Hot Dogs are unsuitable as they are high in saturated fat, which causes inflammation. Studies show that higher intakes of these processed meats go hand in hand with diseases caused by inflammation."
    },
    {
      id: "dark chocolate",
      type: "box",
      x: width/2,
      y: 20,
      w: 50,
      h: 70,
      img: darkChocoImg,
      options: {},
      isThrown: false,
      description: "Although sugar isn’t suitable for a PCOS diet, a square or two of dark chocolate with a 70% cocoa content contains antioxidants and magnesium - a mineral found to be lacking in the majority of women"
    },
    {
      id: "fish",
      type: "box",
      x: width/2,
      y: 60,
      w: 50,
      h: 80,
      img: fishImg,
      options: {},
      isThrown: false,
      description: "The PCOS diet leans more towards protein. Lean white fish like cod are low in fat but rich in protein to keep you full and satisfied. Fatty fish like salmon and mackerel are rich in omega-3 fatty acids which are anti-inflammatory."
    },
    {
      id: "white bread",
      type: "box",
      x: width/2,
      y: 60,
      w: 50,
      h: 50,
      img: toastImg,
      options: {},
      isThrown: true,
      description: "Carbohydrate foods that are sugary or refined (such as soda, juice, white bread and white rice) can cause insulin levels to go up higher. This can be an issue as women with PCOS are at a higher risk of getting diabetes."
    },
    {
      id: "diet soda",
      type: "box",
      x: width/2,
      y: 60,
      w: 30,
      h: 45,
      img: sodaImg,
      options: {},
      isThrown: true,
      description: "Diet soda amps up sugar craving and confuses your body. Additionally, diet soda can increase risk for osteoporosis - 4% of female cola drinkers had a lower bone mineral density in their hips compared to women who did not drink soda."
    },
    {
      id: "steak",
      type: "box",
      x: width/2,
      y: 60,
      w: 70,
      h: 50,
      img: steakImg,
      options: {},
      isThrown: true,
      description: "Red meat such as mutton, beef, pork etc. contains saturated fat and cholesterol which increases the risk of cardiovascular disease. This may lead to weight gain and contribute to already existing hormonal imbalance and thus, should be avoided."
    },
    {
      id: "fried chicken",
      type: "box",
      x: width/2,
      y: 60,
      w: 55,
      h: 35,
      img: friedChickenImg,
      options: {},
      isThrown: true,
      description: "Fried foods are rich in saturated or hydrogenated fats. These unhealthy fats can increase estrogen production, which can make the PCOS symptoms worse."
    },
    {
      id: "ginger",
      type: "box",
      x: width/2,
      y: 60,
      w: 30,
      h: 40,
      img: gingerImg,
      options: {},
      isThrown: false,
      description: "Cinnamon extract has been shown to have a positive effect on insulin resistance. Turmeric is an anti-inflammatory spice that contains a powerful compound called curcumin which also reduces insulin resistance, lowers blood sugar levels and increases your HDL."
    },
    {
      id: "spinach",
      type: "box",
      x: width/2,
      y: 60,
      w: 40,
      h: 50,
      img: spinachImg,
      options: {},
      isThrown: false,
      description: "High fiber foods help combat insulin resistance by slowing down digestion and reducing the impact of sugar on the blood. Green leafy veg such as kale or spinach, contains high levels of Vitamin B which is found to be deficient in more than 80% of women with PCOS."
    },
    {
      id: "grape",
      type: "grapes",
      x: width/2,
      y: 60,
      r: 7,
      n: 4,
      img: grapeImg,
      options: { restitution: 0.8 },
      isThrown: false,
      description: "Women with PCOS have been shown to have low-grade inflammation. Elevated inflammation levels can raise insulin, contributing to worsening the PCOS symptoms. The best inflammation-fighting antioxidant-filled foods include fruits, vegetables, whole grains, and unsaturated fats."
    }
  ];

  changeState(0);

  Runner.run(engine);
}

function draw() { // looped per frame
  background(50);
  image(bgImg, 0, 0, width + 10, height + 10);
  switch(state) {
    case 0:
      sign.show();
      push();
      fill("#413e4d");
      stroke(255);
      strokeWeight(7);
      textFont(myFont);
      textSize(28);
      textAlign(CENTER);
      text("Click anywhere to start", width/2, 500);
      pop();
      break;
    case 1:
      push();
      fill("#413e4d");
      stroke(255);
      strokeWeight(7);
      textFont(myFont);
      textSize(28);
      text('Score: ' + score, 10, 30);

      textAlign(CENTER);
      text(foodInfo[index-1].id, width/2, 30);
      pop();

      for (var i = 0; i < food.length; i++) {
        food[i].show();
      }
      
      trashcan.show();
      plate.show();
      // plateSensor.show();
      fryingPan.show();
      break;
  }
  
}

// utility functions
function changeState(x) {
  Common.setDecomp(decomp);
  engine = Engine.create();
  world = engine.world;

  // mouse control
  mouse = Mouse.create(canvas.elt);
  mouse.pixelRatio = pixelDensity();
  mouseConstraint = MouseConstraint.create(engine, { mouse: mouse });
  Composite.add(world, mouseConstraint);

  // prevents objects from yeeting off screen
  new Box(width/2, height + 20, width + 100, 40, "", { isStatic: true });
  new Box(width/2, -20, width + 100, 40, "", { isStatic: true });
  new Box(-20, height/2, 40, height + 100, "", { isStatic: true });
  new Box(width + 20, height/2, 40, height + 100, "", { isStatic: true });

  Runner.run(engine);

  state = x;
  switch (x) {
    case 0:
      sign = new Sign(300, 300, 600, 300, signImg);
      break;
    case 1:
      fryingPan = new Box(width/2, 240, 300, 40, fryingPanImg, { isStatic: true });
      spawnFood();
      plate = new Box(width - 130, 280, 200, 20, plateImg, {isStatic: true});
      plateSensor = new Box(width - 130, 260, 200, 10, "", {isStatic: true, isSensor: true});
      trashcan = new Polygon(20, height - 280, "0 0 20 300 190 300 200 0 190 0 180 290 30 290 10 0", trashcanImg, {isStatic: true});
      trashcanSensor = new Polygon(30, height - 290, "10 0 30 290 180 290 190 0", "", {isStatic: true, isSensor: true});
      break;
  }
}

function spawnFood() {
  var obj = foodInfo[index];
  switch (obj.type) {
    case "chain":
      food.push(new Chain(obj.x, obj.y, obj.w, obj.h, obj.n, obj.img, obj.options, obj.id));
      break;
    case "box":
      food.push(new Box(obj.x, obj.y, obj.w, obj.h, obj.img, obj.options, obj.id));
      break;
    case "grapes":
      food.push(new Grapes(obj.x, obj.y, obj.r, obj.n, obj.img, obj.options, obj.id));
      break;
  }
  index++;
}

// events
function mousePressed() {
  if (state == 0) {
    changeState(1);
  }
}

function isThrown(obj) {
  if (!obj.done) { // if the object hasn't been thrown or eaten before
    var modal = new bootstrap.Modal(document.getElementById("modal"));
    modal.toggle();

    var f = foodInfo[index-1]; // get the information about the food
    if (f.isThrown) { //if the object is supposed to be thrown
      document.getElementById("food-message").innerHTML = "Well done! ✔️";
      score++;
    } else {
      document.getElementById("food-message").innerHTML = "Nice try ❌";
    }
    document.getElementById("food-description").innerHTML = f.description;
    
  }
  obj.done = true;
}

function isEaten(obj) {
  if (!obj.done) { // if the object hasn't been thrown or eaten before
    var modal = new bootstrap.Modal(document.getElementById("modal"));
    modal.toggle();

    var f = foodInfo[index-1]; // get the information about the food
    if (!f.isThrown) { //if the object is supposed to be eaten
      document.getElementById("food-message").innerHTML = "Well done! ✔️";
      score++;
    } else {
      document.getElementById("food-message").innerHTML = "Nice try ❌";
    }
    document.getElementById("food-description").innerHTML = f.description;
    
  }
  obj.done = true;
}