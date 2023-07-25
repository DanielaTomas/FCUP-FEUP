-- a)
mediana :: Ord a => a -> a -> a -> a
mediana x y z | x>=y && x<=z = x
              | x<=y && x>=z = x
              | y>=x && y<=z = y
              | y<=x && y>=z = y
              | otherwise = z

mediana' x y z = (x + y + z) - (max3 x y z) - (min3 x y z)

--------------------------------------------------
max3, min3 :: Ord a => a -> a -> a -> a
max3 x y z = if x >= max y z then x else max y z
min3 x y z = if x <= min y z then x else min y z
