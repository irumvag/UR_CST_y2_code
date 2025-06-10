import turtle
colors=['red', 'blue', 'yellow', 'green', 'purple', 'orange']
s=1
n=5
for i in range(8):
  for j in colors:
    turtle.pensize(s)
    turtle.pencolor(j)
    turtle.forward(n)
    turtle.left(45)
    n+=3
  s+=2
turtle.done()