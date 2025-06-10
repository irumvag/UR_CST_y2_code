import turtle

screen = turtle.Screen()
screen.bgcolor("white")
screen.title("Ruth") 

colors = ( 'yellow', 'blue', 'green', 'orange', 'purple',  'red' )

for i in range(44):
  turtle.left(45)
  turtle.pencolor(colors[i % 6])
  turtle.pensize(i*0.5 + 1)
  turtle.forward(i*2.5 + 5)
#turtle.done()
turtle.hideturtle()
screen.exitonclick()
