-- a)
myminimum :: Ord a => [a] -> a
myminimum [] = error "lista vazia"
myminimum [x] = x
myminimum (x:xs) | x < myminimum xs = x
                 | otherwise        = myminimum xs

-- b)
delete :: Eq a => a -> [a] -> [a]
delete n [] = []
delete n (x:xs) | n == x    = xs
                | otherwise = x : delete n xs

-- c)
ssort :: Ord a => [a] -> [a]
ssort [] = []
ssort x  = m : ssort (delete m x)
         where m = myminimum x
