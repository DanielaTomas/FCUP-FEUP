zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys
zipWith' _ _ _ = []

zipWith'' f l1 l2 = map aux (zip l1 l2)
            where aux (x,y) = f x y
