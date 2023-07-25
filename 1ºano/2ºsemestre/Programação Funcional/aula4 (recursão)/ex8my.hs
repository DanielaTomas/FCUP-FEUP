-- c)
myconcat' :: [[a]] -> [a]
myconcat' xs = [ val | x <- xs, val <- x]

-- d)
--myreplicate' :: Int -> a -> [a]
--myreplicate' n x = take n (repeat x)
myreplicate' :: Int -> a -> [a]
myreplicate' n x = [ x | v <-[1..n]]

-- e)
myselection' :: [a] -> Int -> a
myselection' lista n = head [ x | (x,y) <- zip lista [0..n], y == n ]
