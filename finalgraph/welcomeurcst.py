import turtle

# Set up the screen
screen = turtle.Screen()
screen.bgcolor("white")
screen.title("Ruth")

# Keep animation on and fast
screen.tracer(1)

# Create turtle for drawing
pen = turtle.Turtle()
pen.hideturtle()
pen.speed(10)
pen.penup()

# Draw the rectangle
pen.goto(-250, 75)
pen.fillcolor("royalblue")
pen.begin_fill()
pen.pendown()
pen.pencolor("blue")
for _ in range(2):
    pen.forward(500)
    pen.right(90)
    pen.forward(150)
    pen.right(90)
pen.end_fill()

# Write centered text
pen.penup()
pen.goto(0, -15)  # Adjusted Y for better vertical centering
pen.color("white")
pen.write("Welcome to UR CST", align="center", font=("Arial", 28, "bold"))

screen.exitonclick()