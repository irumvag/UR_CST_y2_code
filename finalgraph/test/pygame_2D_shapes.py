import pygame
import math

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((500, 500))
pygame.display.set_caption("Transformations - Pygame")

# Original square coordinates
square = [(100, 100), (150, 100), (150, 150), (100, 150)]

def translate(shape, tx, ty):
    return [(x + tx, y + ty) for x, y in shape]

def rotate(shape, angle_deg, origin=(0, 0)):
    angle_rad = math.radians(angle_deg)
    cos_a = math.cos(angle_rad)
    sin_a = math.sin(angle_rad)
    ox, oy = origin
    return [((x - ox) * cos_a - (y - oy) * sin_a + ox,
             (x - ox) * sin_a + (y - oy) * cos_a + oy)
            for x, y in shape]

def scale(shape, sx, sy, origin=(0, 0)):
    ox, oy = origin
    return [((x - ox) * sx + ox, (y - oy) * sy + oy) for x, y in shape]

# Transformations
translated = translate(square, 100, 50)
rotated = rotate(square, 45, origin=(125, 125))
scaled = scale(square, 1.5, 1.5, origin=(125, 125))

# Main loop
running = True
while running:
    screen.fill((255, 255, 255))
    pygame.draw.polygon(screen, (0, 0, 255), square, 2)
    pygame.draw.polygon(screen, (0, 255, 0), translated, 2)
    pygame.draw.polygon(screen, (255, 0, 0), rotated, 2)
    pygame.draw.polygon(screen, (255, 165, 0), scaled, 2)
    pygame.display.flip()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
pygame.quit()
