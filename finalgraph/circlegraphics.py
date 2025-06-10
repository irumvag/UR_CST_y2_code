import turtle


screen = turtle.Screen()
screen.bgcolor("white")
screen.title("Ruth IBYISHAKA : 2D Rotation")


pen = turtle.Turtle()
#pen.hideturtle()
pen.speed(0)


pen.penup()
pen.goto(-250, 80)
pen.pendown()
pen.fillcolor("#70ad47")
pen.pencolor("blue")
pen.pensize(1)
pen.begin_fill()
for _ in range(2):
    pen.forward(480)
    pen.right(90)
    pen.forward(160)
    pen.right(90)
pen.end_fill()

# Function to draw a labeled circle
def draw_circle(x, y, color, label):
    pen.penup()
    pen.goto(x, y - 70)  
    pen.pendown()
    pen.fillcolor(color)
    pen.pencolor("#2e75b6")
    pen.pensize(1)
    pen.begin_fill()
    pen.circle(60, steps=5000)
    pen.end_fill()


    pen.penup()
    pen.goto(x, y - 20)
    pen.color("white")
    pen.write(label, align="center", font=("Arial", 12, "bold"))
    
    pen.color("#2e75b6")
    pen.pensize(2)
# Draw three circles
draw_circle(-150, 0, "#ff0000", "CST")
draw_circle(0, 0, "#2e75b6", "SoICT")
draw_circle(150, 0, "#ed7d31", "CS")

pen.hideturtle()
# Keep the window open
#turtle.done()
screen.exitonclick()