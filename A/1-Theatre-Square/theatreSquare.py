import math

theatreSquare = input().strip().split()
length = int(theatreSquare[0])
width = int(theatreSquare[1])
tileSize = int(theatreSquare[2])

tilesNeeded = math.ceil(length / tileSize) * math.ceil(width / tileSize)
print(tilesNeeded)
