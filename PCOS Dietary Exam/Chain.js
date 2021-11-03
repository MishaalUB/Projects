class Chain {
  constructor(x, y, w, h, n, img = "", options = {}, id = "") {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.n = n; // number of chains
    this.id = id;
    this.done = false;
    this.chains = [];

    this.chains[0] = new Box(this.x, this.y, this.w, this.h, img, options, "", false);

    for(var i = 1; i < this.n; i++) {
      this.chains[i] = new Box(this.x, this.chains[i-1].y + this.h, this.w, this.h, img, options, "", false);

      Composite.add(world, Constraint.create({
        bodyA: this.chains[i-1].body,
        bodyB: this.chains[i].body,
        pointA: Vector.create(0, this.h / 2),
        pointB: Vector.create(0, -(this.h/2)),
        length: 1,
        stiffness: 0.2
      }));
    }
    
  }

  show() {
    for (var i = 0; i < this.n; i++) {
      this.chains[i].show();
      if (state == 1) {
        if (SAT.collides(this.chains[i].body, trashcanSensor.body).collided) {
          isThrown(this);
        }
        if (SAT.collides(this.chains[i].body, plateSensor.body).collided) {
          isEaten(this);
        }
      }
    }
  }
}