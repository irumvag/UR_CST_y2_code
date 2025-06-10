import turtle
import math

screen = turtle.Screen()
screen.bgcolor("white")
screen.title("Ruth") 
turtle.speed(0)
screen.tracer(1)
screen.update()

def star(x,y,length,penc,fillc):
  turtle.up()
  turtle.goto(x,y)
  turtle.seth(90)
  turtle.fd(length)
  turtle.seth(180+36/2)
  L = length*math.sin(36*math.pi/180)/math.sin(54*math.pi/180)
  turtle.seth(180+72)
  turtle.down()
  turtle.fillcolor(fillc)
  turtle.pencolor(penc)
  turtle.begin_fill()
  for _ in range(5):
    turtle.fd(L)
    turtle.right(72)
    turtle.fd(L)
    turtle.left(144)
  turtle.end_fill()

def star_fractal(x,y,length,penc,fillc,n):
  if n==0:
    star(x,y,length,penc,fillc)
    return
  length2 = length/(1+(math.sin(18*math.pi/180)+1)/math.sin(54*math.pi/180))
  L = length-length2-length2*math.sin(18*math.pi/180)/math.sin(54*math.pi/180)
  for i in range(5):
    star_fractal(x+math.cos((90+i*72)*math.pi/180)*(length-length2),
                 y+math.sin((90+i*72)*math.pi/180)*(length-length2),
                 length2,penc,fillc,n-1)
    
star_fractal(0,0,200,'blue','blue',3)
#turtle.done()
turtle.hideturtle()
screen.exitonclick()