compL :: [a -> a] -> a -> a
compL [] v = v
compL (x:xs) v = x (compL xs v)

compL' :: [a -> a] -> a -> a
compL' xs v = (foldr (f) v xs) v
              where f g x = g x
