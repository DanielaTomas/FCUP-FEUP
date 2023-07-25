testaTriangulo :: Float -> Float -> Float -> Bool
testaTriangulo a b c = a > 0 &&
                       b > 0 &&
                       c > 0 &&
                       a < (b + c) &&
                       b < (a + c) &&
                       c < (a + b)
