class Grapes {
  constructor(x, y, r, n, img="", options={}, id="") {
    this.x = x;
    this.y = y;
    this.r = r;
    this.img = img;
    this.options = options;
    this.id = id;
    this.done = false;

    var l = n; // number of layers

    this.balls = [];
    this.leaf = new Box(this.x, this.y, 30, 30, leafImg);
    
    for (var i = 0; i < l; i++) {
      this.balls.push(new Array(l - i));
      for (var j = 0; j < this.balls[i].length; j++) {
        this.balls[i][j] = new Circle(this.x, this.y, this.r, this.img, this.options, false);
        if (i > 0) {
          Composite.add(world, Constraint.create({
            bodyA: this.balls[i-1][j].body,
            bodyB: this.balls[i][j].body,
            pointA: Vector.create(cos(PI/3) * this.r, sin(PI/3) * this.r),
            pointB: Vector.create(-cos(PI/3) * this.r, -sin(PI/3) * this.r),
            length: 0,
            stiffness: 0.4
          }));
          Composite.add(world, Constraint.create({
            bodyA: this.balls[i-1][j+1].body,
            bodyB: this.balls[i][j].body,
            pointA: Vector.create(-cos(PI/3) * this.r, sin(PI/3) * this.r),
            pointB: Vector.create(cos(PI/3) * this.r, -sin(PI/3) * this.r),
            length: 0,
            stiffness: 0.4
          }));
          Composite.add(world, Constraint.create({
            bodyA: this.balls[i-1][j].body,
            bodyB: this.balls[i-1][j+1].body,
            pointA: Vector.create(this.r, 0),
            pointB: Vector.create(-this.r, 0),
            length: 0,
            stiffness: 0.4
          }));
        }
      }
    }
    
    Composite.add(world, Constraint.create({
      bodyA: this.balls[0][this.balls[0].length / 2 - 1].body,
      bodyB: this.leaf.body,
      pointA: Vector.create(cos(PI/3) * this.r, -sin(PI/3) * this.r),
      pointB: Vector.create(-cos(PI/3) * 20, sin(PI/3) * 20),
      length: 7,
      stiffness: 0.7
    }));
    Composite.add(world, Constraint.create({
      bodyA: this.balls[0][this.balls[0].length / 2].body,
      bodyB: this.leaf.body,
      pointA: Vector.create(-cos(PI/3) * this.r, -sin(PI/3) * this.r),
      pointB: Vector.create(cos(PI/3) * 20, sin(PI/3) * 20),
      length: 7,
      stiffness: 0.7
    }));
}

  show() {
    this.leaf.show();
    for (var i = 0; i < this.balls.length; i++) {
      for (var j = 0; j < this.balls[i].length; j++) {
        this.balls[i][j].show();
        if (state == 1) {
          if (SAT.collides(this.balls[i][j].body, trashcanSensor.body).collided) {
            isThrown(this);
          }
          if (SAT.collides(this.balls[i][j].body, plateSensor.body).collided) {
            isEaten(this);
          }
        }
      }
    }
  }
}