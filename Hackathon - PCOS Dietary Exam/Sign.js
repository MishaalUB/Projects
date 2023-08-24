class Sign {
  constructor(x, y, w, h, img = "") {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.sign = new Box(this.x, this.y, this.w, this.h, img);
    this.lRope = Constraint.create({ // left rope
      pointA: Vector.create(width/3, -20), 
      bodyB: this.sign.body, 
      pointB: Vector.create(width/3 - width/2, -this.h / 2 + 20), 
      length: 100,
      stiffness: 0.4
    });
    this.rRope = Constraint.create({ // right rope
      pointA: Vector.create(2 * width/3, -20), 
      bodyB: this.sign.body, 
      pointB: Vector.create(2 * width/3 - width/2, -this.h / 2 + 20), 
      length: 100,
      stiffness: 0.4
    })

    Composite.add(world, this.lRope); // adds it to the world

    Composite.add(world, this.rRope); // adds it to the world
  }

  show() {
    this.sign.show();

    push();
    strokeWeight(20);
    stroke("#413e4d");
    fill("#413e4d");
    line(this.lRope.pointA.x, this.lRope.pointA.y, this.sign.body.position.x + this.lRope.pointB.x, this.sign.body.position.y + this.lRope.pointB.y);
    line(this.rRope.pointA.x, this.rRope.pointA.y, this.sign.body.position.x + this.rRope.pointB.x, this.sign.body.position.y + this.rRope.pointB.y);
    pop();
  }
}