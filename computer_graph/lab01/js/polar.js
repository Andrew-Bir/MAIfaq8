//Пашкевич М8О-307Б-16 r = a*sin(2fi)
Line = []

var canvas = document.getElementById("cs1")
var cnt1 = canvas.getContext("2d");
var y0 = canvas.height / 2
var x0 = canvas.width / 2

function r_polar(a, fi) {
  return a*Math.sin(2*fi);
}

function x(r, fi) {
  return r * Math.cos(fi)
}

function y(r, fi) {
  return r * Math.sin(fi)
}

function draw_axes() {
    with (cnt1){
      beginPath()
      //axes
      moveTo(x0,y0 * 2);
      lineTo(x0,0);
      moveTo(0,y0);
      lineTo(x0 * 2,y0);
      // arrows y
      moveTo(x0,0);
      lineTo(x0 - 10,10)
      moveTo(x0,0);
      lineTo(x0 + 10,10)
      //arrows x
      moveTo(x0 * 2,y0);
      lineTo((x0 * 2) - 10,y0 + 10)
      moveTo(x0 * 2,y0);
      lineTo((x0 * 2) - 10,y0 - 10)
      strokeStyle="#0000FF"
      stroke()
      //axes names
      fillText("y",x0 + 15,15);
      fillText("x",(x0 * 2) - 15,y0 + 20);
		}
}

function start(){
  var a_label = document.getElementById("a");
  var a = parseInt(a_label.value) * 100;
	i=0
	for (fi=0; fi <= 2 * Math.PI; fi+=0.01){
    r = r_polar(a , fi);
		p = [x(r, fi) + x0,y(r, fi) + y0];
		Line[i++] = p;
	}
	with (cnt1){
    clearRect(0, 0, canvas.width, canvas.height)
    draw_axes()
		beginPath()
		moveTo(Line[0][0],Line[0][1])
		for (var i=1; i<Line.length; i++){
			lineTo(Line[i][0],Line[i][1]);strokeStyle="#FF0000"; stroke()
		}
    //function
    fillText("\u03C1 = " + a_label.value + "\u00B7sin(2\u03C6)",x0 + (x0 / 5), 50)
	}
}
