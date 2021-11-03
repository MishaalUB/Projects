class Box {
  constructor(x, y, w, h, img = "", options = {}, id = "", isWhole = true) {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.img = img;
    this.id = id;
    this.isWhole = isWhole;
    this.body = Bodies.rectangle(x, y, w, h, options);
    this.done = false;

    Composite.add(world, this.body);
  }

  show() {
    var pos = this.body.position;
    var angle = this.body.angle;

    push();
    translate(pos.x, pos.y);
    rotate(angle);
    rectMode(CENTER);
    imageMode(CENTER);
    fill(255);
    if (this.img == "") {
      rect(0, 0, this.w, this.h);
    } else {
      image(this.img, 0, 0, this.w, this.h);
    }
    pop();
    
    if (state == 1) {
      if (SAT.collides(this.body, trashcanSensor.body).collided && this.isWhole) {
        isThrown(this);
      }
      if (SAT.collides(this.body, plateSensor.body).collided && this.isWhole) {
        isEaten(this);
      }
    }
  }
}