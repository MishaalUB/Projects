class Circle {
  constructor(x, y, r, img = "", options = {}, id = "", isWhole = true) {
    this.x = x;
    this.y = y;
    this.r = r;
    this.id = id;
    this.img = img;
    this.isWhole = isWhole;
    this.done = false;
    this.body = Bodies.circle(x, y, r);

    Composite.add(world, this.body);
  }

  show() {
    var pos = this.body.position;
    var angle = this.body.angle;

    push();
    translate(pos.x, pos.y);
    rotate(angle);
    if (this.img == "") {
      circle(0, 0, this.r * 2);
    } else {
      image(this.img, -this.r * 2, -this.r * 2, this.r * 2, this.r * 2);
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