-- a)
myand :: [Bool] -> Bool
myand [] = True
myand (False:xs) = False
myand (True:xs) = myand xs

-- b)
myor :: [Bool] -> Bool
myor [] = False
myor (True:xs) = True
myor (False:xs) = myor xs

--myor :: [Bool] -> Bool
--myor [] = False
--myor (x:xs) = x || myor xs

-- c)
myconcat :: [[a]] -> [a]
myconcat [] = []
myconcat (x:xs) = x ++ myconcat xs

-- d)
myreplicate :: Int -> a -> [a]
myreplicate n x | n <= 0    = []
                | otherwise = x : myreplicate (n-1) x
-- e)
myselection :: [a] -> Int -> a
myselection (x:_) 0 = x
myselection (_:xs) n = myselection xs (n-1)

-- f)
myelem :: Eq a => a -> [a] -> Bool
myelem _ [] = False
myelem n (x:xs) | x == n    = True
                | otherwise = myelem n xs
