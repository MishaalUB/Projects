class Ragdoll {
  constructor(x, y) {
    this.x = x;
    this.y = y;
    this.head = new Circle(this.x, this.y, 20);
    this.torso = new Box(this.x, this.y + 20, 26, 70);

    var constraint = Constraint.create({
      bodyA: this.head.body,
      bodyB: this.torso.body,
      pointA: Vector.create(0, this.head.r),
      pointB: Vector.create(0, -(this.torso.h/2)),
      length: 0,
      strength: 0.7
    });

    Composite.add(world, constraint); // adds it to the world
  }

  show() {
    this.head.show();
    this.torso.show();
  }
}