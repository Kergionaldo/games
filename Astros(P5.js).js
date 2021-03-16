function setup() {
  createCanvas(400, 400);
}

var ang = 0;
var ang2 = 0;
var psx = 200;
var px = 100, py = 0;

function draw() {
  
  background(0);
  
  fill(255, 255, 0)
  ellipse(psx, psx, 40, 40)
  
  translate(psx, psx)
  push();
  rotate(ang)
  fill(0, 0, 255)
  ellipse(px, py, 20, 20)
  
  ang+=0.01;
  
  translate(px, py)
  push()
  rotate(ang)
  fill(100, 100, 100)
  ellipse(20, 0, 10, 10)
  
  pop()
  ang2+= 0.5
  pop()
}
