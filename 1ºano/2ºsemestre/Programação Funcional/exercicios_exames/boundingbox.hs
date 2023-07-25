type Point = (Double, Double)

boundingBox :: [Point] -> (Point, Point)
boundingBox pontos = ((menorX, menorY), (maiorX, maiorY))
            where xs = [ x | (x, y) <- pontos]
                  ys = [ y | (x, y) <- pontos]
                  menorX = minimum xs
                  maiorX = maximum xs
                  menorY = minimum ys
                  maiorY = maximum ys
