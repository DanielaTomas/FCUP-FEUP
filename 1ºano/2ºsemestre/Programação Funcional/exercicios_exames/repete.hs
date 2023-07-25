repete :: a -> [[a]]
repete a = [] : [ a:x | x <- repete a]
