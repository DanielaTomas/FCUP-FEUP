-- a)
max', min' :: Ord a => a -> a -> a
max' x y = if x>=y then x else y
min' x y = if x<=y then x else y
{-
max3, min3 :: Ord a => a -> a -> a
max3 x y = if x>=y && x>=z then x
            else if y>=x && y>=z then y
             else z
min3 x y = if x<=y && x<=z then x
            else if y<=x && y<=z then y
             else z
-}
max3, min3 :: Ord a => a -> a -> a -> a
max3 x y z | x>=y && x>=z = x
           | y>=z = y
           | otherwise = z
min3 x y z | x<=y && x<=z = x
           | y<=z = y
           | otherwise = z
-- b)
max3', min3' :: Ord a => a -> a -> a -> a
max3' x y z = if x >= max y z then x else max y z
min3' x y z = if x <= min y z then x else min y z
{-
max3' x y z = max (max x y)
min3' x y z = min (min x y)
-}
