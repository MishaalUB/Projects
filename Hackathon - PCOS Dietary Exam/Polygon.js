class Polygon { // only works for static objects right now ;-;
  constructor(x, y, path, img = "", options = {}, id = "") {
    this.x = x;
    this.y = y;
    this.vertices = Vertices.fromPath(path);
    this.img = img; 
    this.id = id;
    this.done = false;

    var temp = Bodies.fromVertices(0, 0, this.vertices); // so that we count from the top left corner
    this.offset = temp.bounds.min;
    this.body = Bodies.fromVertices(this.x - this.offset.x, this.y - this.offset.y, this.vertices, options);
    Composite.add(world, this.body);

    this.w = this.body.bounds.max.x - this.body.bounds.min.x;
    this.h = this.body.bounds.max.y - this.body.bounds.min.y;
  }

  show() {
    var pos = this.body.position;
    var angle = this.body.angle;

    push();
    if (this.img == "") {
      beginShape();
      for (var i = 0; i < this.body.vertices.length; i++) {
        var v = this.body.vertices[i];
        vertex(v.x, v.y);
      }
      endShape(CLOSE);
    } else {
      image(this.img, this.x, this.y - 20, this.w, this.h);
    }
    pop();
  }
}