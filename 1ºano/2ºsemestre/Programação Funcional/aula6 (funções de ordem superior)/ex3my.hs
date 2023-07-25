-- a)
junta :: [a] -> [a] -> [a]
junta xs ys = foldr (:) ys xs

{-import Prelude hiding ((++))

(++) :: [a] -> [a] -> [a]
xs ++ ys = foldr f z lista
    where f     = (:)
          z     = ys
          lista = xs -}

-- b)
myconcat :: [[a]] -> [a]
myconcat l = foldr (++) [] l
      where aux resxs = (++) l resxs
{-
myconcat' :: [[a]] -> [a]
myconcat' [] = []
myconcat' (x:xs) = x ++ myconcat' xs
-}

--c)
myreverse :: [a] -> [a]
myreverse l = foldr aux [] l
         where aux x xs = xs ++ [x]

{- myreverse :: [a] -> [a]
myreverse l = foldl aux [] l
          where aux x xs = xs : x -}
{-
myreverse' :: [a] -> [a]
myreverse' [] = []
myreverse' (x:xs) = (myreverse' xs) ++ x
-}

-----------------------------------------------
myfoldr :: b -> (a -> b -> b) -> [a] -> b
myfoldr rf _ [] = rf
myfoldr rf f (x:xs) = f x (myfoldr rf f xs)
